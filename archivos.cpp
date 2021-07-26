#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
using namespace std;
void menu();void guardar();void eliminar();void consultar();void buscar();void modificar();void salir();
char nombre[30],grupo[10];
char mensaje[]={'P','R','O','G','R','A','M','A','C','I','O','N',' ','D','E',' ','S','O','F','T','W','A','R','E'};
int semestre,edad,auxclave,clave;
bool encontrado;
main()
{
	menu();// system ("PAUSE");
}
void menu()
{
	int opcion;
	do
	{
		cout<<"\n \t\t\t\t\tManejo de archivos en C++ \n"<<endl;
		cout<<"\n \t\t\t\t\t1.Guardar \n"<<endl;
		cout<<"\n \t\t\t\t\t2.Eliminar \n"<<endl;
		cout<<"\n \t\t\t\t\t3.Consultar Registros \n"<<endl;
		cout<<"\n \t\t\t\t\t4.Buscar Registros \n"<<endl;
		cout<<"\n \t\t\t\t\t5.Modificar \n"<<endl;
		cout<<"\n \t\t\t\t\t6.Salir \n"<<endl;
		cout<<"\n \t\t\t\t\tSelecione una de las opciones \n"<<endl;
		cin>>opcion;
		switch(opcion)
		{
			case 1: guardar(); break;
			case 2: eliminar(); break;
			case 3: consultar(); break;
			case 4: buscar(); break;
			case 5: modificar(); break;
			case 6: salir(); break;
			deafult: cout<<"La opcion que elegiste no hace parte del menu"; break;	
		}
	}
	while(opcion!=6);
}
void guardar()
{
	ofstream escritura; ifstream consulta; bool repetido=false;
	escritura.open("aprendiz.txt",ios::out|ios::app);
	consulta.open("aprendiz.txt",ios::in);
	if(escritura.is_open() && consulta.is_open())
	{
		cout<<"ingresa la clave del aprendiz: ";
		cin>>auxclave;
		consulta>>clave;
		while(!consulta.eof())
		{
			consulta>>nombre>>semestre>>grupo>>edad;
			if(clave==auxclave)
			{
				cout<<" Ya existe el registro con esa clave "<<endl;
				repetido=true;
				break;
			}
			consulta>>clave;
		}
		if(repetido==false)
		{
			cout<<"ingresa el nombre del aprendiz: "; cin>>nombre;
			cout<<"ingrese el semestre del aprendiz: "; cin>>semestre;
			cout<<"ingrese el grupo del aprendiz: "; cin>>grupo;
			cout<<"ingrese la edad del aprendiz: "; cin>>edad;
			escritura<<auxclave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
		}
	}
	else{
			cout<<"Error, el registro no se pudo abrir o no ha sido creado"<<endl;
	}
	escritura.close();consulta.close();
}
void eliminar()
{
	ofstream aux; ifstream leer; encontrado=false; int auxclave;
	aux.open("auxiliar.txt", ios::out); leer.open("aprendiz.txt", ios::in);
	if(aux.is_open() &&leer.is_open())
	{
		cout<<"ingresa la clave del aprendiz que deseas eliminar: "<<endl;
		cin>>auxclave;
		leer>>clave;
		while(!leer.eof())
		{
			leer>>nombre>>semestre>>grupo>>edad;
			if(auxclave==clave)
			{
				encontrado=true;
				cout<<"Registro eliminado "<<endl;
			}
			else
			{
				aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
			}
			leer>>clave;
		}
	}
	else{
		cout<<"Error, revisa tu clave pues esa no esta dentro de mi archivo "<<auxclave<<endl;
	}
	leer.close(); aux.close();
	remove("aprendiz.txt"); rename("auxiliar.txt","aprendiz.txt");
}
void consultar()
{
	ifstream leer; leer.open("aprendiz.txt", ios::out|ios::in);
	if(leer.is_open())
	{
		cout<<"                    Registros del archivo aprendiz.txt"<<endl;
		cout<<"                    **********************************"<<endl;
		leer>>clave;
		while(!leer.eof())
		{
			leer>>nombre>>semestre>>grupo>>edad;
			cout<<"                Clave: "<<clave<<endl;
			cout<<"                Nombre: "<<nombre<<endl;
			cout<<"                Semestre: "<<semestre<<endl;
			cout<<"                Grupo: "<<grupo<<endl;
			cout<<"                Edad: "<<edad<<endl;
			leer>>clave;
			cout<<"                **********************************"<<endl;
		}
	}
	else
	{
		cout<<"Error, el registro no se pudo abrir o no ha sido creado "<<endl;
	}
	leer.close();
}
void buscar()
{
	ifstream leer;
	leer.open("aprendiz.txt", ios::out|ios::in);
	encontrado=false;
	if(leer.is_open())
	{
		cout<<"ingresa la clave del aprendiz que deseas buscar ";
		cin>>auxclave;
		leer>>clave;
		while(!leer.eof())
		{
			leer>>nombre>>semestre>>grupo>>edad;//leyendo campos del registro
			if(auxclave==clave)
			{
				cout<<"                *********************************"<<endl;
				cout<<"                  Clave: "<<clave<<endl;
				cout<<"                  Nombre: "<<nombre<<endl;
				cout<<"                  Semestre: "<<semestre<<endl;
				cout<<"                  Grupo: "<<grupo<<endl;
				cout<<"                  Edad: "<<edad<<endl;
				cout<<"                **********************************"<<endl;
				encontrado=true;
			}
			leer>>clave;
		}
		if(encontrado==false)
		{
			cout<<"no se encontraron registros con esa clave "<<auxclave<<endl;
		}
	}
	else
	{
		cout<<"no se pudo abrir el archivo o aun no ha sido creado"<<endl;
	}
	leer.close();//cerrar archivo
}
void modificar()
{
	ofstream aux;
	ifstream leer;
	encontrado=false;
	int auxclave,auxedad,auxsemestre;
	int opcion1;
	char auxnombre[20],auxgrupo[10];
	aux.open("auxiliar.txt", ios::out);
	leer.open("aprendiz.txt", ios::in);
	if(aux.is_open() && leer.is_open())
	{
		cout<<"ingrese la clave del aprendiz que desea modificar "<<endl;
		cin>>auxclave;
		leer>>clave;
		while(!leer.eof())
	{	
		leer>>nombre>>semestre>>grupo>>edad;
		if(auxclave==clave)
			{
				cout<<"                *********************************"<<endl;
				cout<<"                  Clave: "<<clave<<endl;
				cout<<"                  Nombre: "<<nombre<<endl;
				cout<<"                  Semestre: "<<semestre<<endl;
				cout<<"                  Grupo: "<<grupo<<endl;
				cout<<"                  Edad: "<<edad<<endl;
				cout<<"                **********************************"<<endl;
				cout<<"                  Modificacion de datos "<<endl;
				cout<<"                 ingrese (1) para cambiar el nombre "<<endl;
				cout<<"                 ingrese (2) para cambiar el semestre "<<endl;
				cout<<"                 ingrese (3) para cambiar el grupo "<<endl;
				cout<<"                 ingrese (4) para cambiar el edad "<<endl;
				cout<<"                 ingrese una de las opciones del menu"<<endl;
				cin>>opcion1;
				switch(opcion1)
				{
					case 1: cout<<"               cambio de nombre"<<endl;
					cout<<"      ingresa el nuevo nombre del aprendiz con clave: "<<clave<<endl;
					cin>>auxnombre;
					aux<<clave<<" "<<auxnombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
					break;
					case 2: cout<<"              cambio de semestre"<<endl;
					cout<<"      ingresa el nuevo semestre del aprendiz con clave: "<<clave<<endl;
					cin>>auxclave; 
					aux<<clave<<" "<<nombre<<" "<<auxsemestre<<" "<<grupo<<" "<<edad<<endl;
					break;
					case 3: cout<<"                cambio de grupo"<<endl;
					cout<<"      ingresa el nuevo grupo del aprendiz con clave: "<<clave<<endl;
					cin>>auxgrupo; 
					aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<auxgrupo<<" "<<edad<<endl;
					break;
					case 4: cout<<"                cambio de edad"<<endl;
					cout<<"      ingresa la nueva edad del aprendiz con clave: "<<clave<<endl;
					cin>>auxedad; 
					aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<auxedad<<endl;
					break;
					default: cout<<"Error, el numero digitado no se encuentra dentro de las opciones"<<endl;
					break;
				}
				cout<<"El registro fue modificado con exito! "<<endl;
				encontrado=true;
			}
		else
			{
				aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
			}
		leer>>clave;
		}
		if(encontrado==false)
		{
			cout<<"No se encontraron los egistros con esa clave"<<auxclave<<endl;
		}
	}
	else
	{
		cout<<"Error, no se puede encontar el archivo o no ha sido creado"<<endl;
	}
	leer.close();
	aux.close();
	remove("aprendiz.txt");
	rename("auxiliar.txt", "aprendiz.txt");
}
void salir()
{
	cout<<endl<<endl<<endl<<"\t\t\t\t\t";
	for(int i=0;i<26;i++)
	{
		cout<<mensaje[i];
		Sleep(80);
	}
	cout<<endl<<endl<<"\t\t\t\t\tadios.......programa finalizado"<<endl;
}
