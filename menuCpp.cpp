#include "trabajador.h"
#include "general.h"
#include "estructuras.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void menuPrincipal()
{
	int opcion;

	do
	{
		cout<<"Introduzca una de las siguientes opciones:"<<endl;
		cout<<"1.- Crear vuelo"<<endl;
		cout<<"2.- Consultar vuelos"<<endl;
		cout<<"3.- Consultar trabajadores"<<endl;
		cout<<"4.- Asignar tarea a trabajador"<<endl;
		cout<<"5.- Ver agenda de trabajo"<<endl;
		cout<<"6.- Insertar nuevo trabajador"<<endl;
		cout<<"7.- Modificar un trabajador"<<endl;
		cout<<"8.- Salir"<<endl;
		cin >> opcion;
		switch(opcion)
		{
			case 1:
				cout<<"Ha escogido crear un nuevo vuelo"<<endl;
				IntroducirVuelo(); 
				break;

			case 2:
				cout<<"Ha escogido consultar los vuelos existentes"<<endl;
				LeerVuelos();
				break;

			case 3:
				cout<<"Ha escogido consultar los trabajadores existentes"<<endl;
				listarTrabajadores();
				break;

			case 4:
				cout<<"Ha escogido asignar tarea a trabajador"<<endl;
				asignarTarea();
				break;

			case 5:
				cout<<"Ha escogido ver la lista de agenda de trabajo"<<endl;
				LeerAgenda();
				break;

			case 6:
				cout<<"Ha escogido insertar trabajador"<<endl;
				InsertarTrabajador();
				break;


			case 7:
				cout<<"Ha escogido modificar trabajador"<<endl;
				ModificarTrabajador();
				break;

			case 8:
				cout<<"Adios!"<<endl;
				break;

			default:
				cout<<"La opcion elegida es incorrecta"<<endl;
				break;
		}
	}while(opcion!=8);
}


void InsertarTrabajador() // validar el DNI del trabajador antes de guardar en fichero
{
	Trabajador t1;

	cin >> t1; //Pedimos datos y los guardamos en t1

	t1.EscribirTrabajador(t1);
}


void listarTrabajadores()
{
	Trabajador t1;
	string fichero = "Trabajador.txt";
	t1.ConsultarTrabajadores();

	int longitud = t1.longFichero(fichero);
	cout<<"Tenemos "<< longitud <<" trabajadores registrados "<<endl;

	cout<<"Leyendo trabajadores de vectorTrabajadores..."<<endl;
	vector<Trabajador> miVector = t1.leerDeFichero(fichero);
	for(int i=0; i<miVector.size(); i++)
	{
		Trabajador t = miVector[i];
		cout<<"Trabajador "<< i <<endl;
		//cout<< atoi(t.getDNI().c_str()) <<endl;
		cout <<t.getNombre()<<endl;
		cout<<t.getApellido()<<endl;
		cout<<t.getPuesto()<<endl;
		i++;
	}
}



