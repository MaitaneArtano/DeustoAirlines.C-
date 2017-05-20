#include <string>
#include "trabajador.h"
#include "estructuras.h"
#include <stdlib.h>
#include <iostream>
#include <fstream> //Provee de las clases ofstream(salida), ifstream(entrada) y fstream(entrada/salida)
#include <vector>

using namespace std;


Trabajador::Trabajador(int DNI, string nombre, string apellido, string puesto)
{
	this->DNI = DNI;
	this->nombre = nombre;
	this->apellido = apellido;
	this->puesto = puesto;
}

void Trabajador::setDNI(int DNI)
{
	this->DNI = DNI;
}

void Trabajador::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Trabajador::setApellido(string apellido)
{
	this->apellido = apellido;
}

void Trabajador::setPuesto(string puesto)
{
	this->puesto = puesto;
}

int Trabajador::getDNI()
{
	return this->DNI;
}

string Trabajador::getNombre()
{
	return this->nombre;
}

string Trabajador::getApellido()
{
	return this->apellido;
}

string Trabajador::getPuesto()
{
	return this->puesto;
}

istream& operator>>(istream &in, Trabajador& t)
{
	cout<<"Escriba el DNI del trabajador(sin letra):"<<endl;
	cin>> t.DNI;
	cout<<"Escriba el nombre del trabajador:"<<endl;
	cin>>t.nombre;
	cout<<"Escriba el apellido del trabajador:"<<endl;
	cin>>t.apellido;
	cout<<"Escriba el puesto del trabajador:"<<endl;
	cin>>t.puesto;
	cout<< "-----------------------------------" <<endl;	
	return in;
}

void Trabajador::EscribirTrabajador(Trabajador& t) // insertar trabajador en el fichero 
{
	ofstream archivo;
	archivo.open("Trabajador.txt", ios::app); // para abrir el archivo, si no hay txt crea y si ya existe lo reemplaza

	if(archivo.fail())
	{
		cout << "No se pudo abrir el archivo";
		exit(1);
	}

	else
	{
		archivo << endl;
		archivo << t.DNI << endl;
		archivo << t.nombre << endl;
		archivo << t.apellido << endl;
		archivo << t.puesto << endl;
		archivo << "---------------";
	}
}

void Trabajador::ConsultarTrabajadores()
{
	ifstream archivo;
	string texto;
	archivo.open("Trabajador.txt", ios::in);

	if(archivo.fail())
	{
		cout << "No se pudo abrir el archivo";
		exit(1);
	}else
	{
		while(!archivo.eof())
		{
			getline(archivo,texto);
			cout<<texto<<endl;
		}
	}
	archivo.close();
}

int Trabajador::longFichero(string fic)
{
	ifstream ifs(fic.c_str());
	int longFichero = 0;
	string dato;

	while(!ifs.eof())
	{
		getline(ifs, dato);
		longFichero++;
	}

	ifs.close();
	return (longFichero/5); //Se tiene en cuenta que cada trabajador tiene 4 atributos + "-------"
}

vector<Trabajador> Trabajador::leerDeFichero(string fic)
{
	Trabajador *trabajador = new Trabajador[longFichero(fic)]; //Crea un array a trabajadores reservando el numero de trabajadores que hay
	int i = 0; //i controla que la fila 0 es el DNI, el 1 el nombre, 2 apellido, 3 puesto y cuando i=4 --> "-----", i se pone otra vez a 0

	int numTrabajador = 0;
	ifstream ifs(fic.c_str());
	vector<Trabajador> vectorTrabajadores;
	string dato;
	string nada = "---------------";

	while(!ifs.eof())
	{
		getline(ifs, dato);
		 if(dato != nada) //Para asegurar que las rayas no se guardan como atributo del trabajador
		 {
		 	cout<< "TRABAJADOR ["<<numTrabajador<<"] "<<endl;
		 	if(i==0)
		 	{
		 		trabajador[numTrabajador].setDNI(atoi(dato.c_str()));
		 		i++;
		 	}
		 	if(i==1)
		 	{
		 		trabajador[numTrabajador].setNombre(dato);
		 		i++;
		 	}
		 	if(i==2)
		 	{
		 		trabajador[numTrabajador].setApellido(dato);
		 		i++;
		 	}
		 	if(i==3)
		 	{
		 		trabajador[numTrabajador].setPuesto(dato);
		 		i++;
		 	}
		 }else
		 {
		 	i=0;
		 	vectorTrabajadores.push_back(trabajador[numTrabajador]);
		 	numTrabajador++;
		 }
	}

	ifs.close();
	return vectorTrabajadores;
}

void Trabajador::ModificarTrabajador(string fic)
{


}