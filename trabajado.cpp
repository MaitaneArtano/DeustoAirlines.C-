#include <string>
#include "trabajador.h"
#include "estructuras.h"
#include <iostream>
#include <fstream> //Provee de las clases ofstream(salida), ifstream(entrada) y fstream(entrada/salida)

using namespace std;

Trabajador::Trabajador(int DNI, string nombre, string apellido, string puesto)
{
	this->DNI = DNI;
	this->nombre = nombre;
	this->apellido = apellido;
	this->puesto = puesto;
}

void Trabajador::setNomApe(int DNI, string nombre, string apellido)
{
	if(validacion(DNI)!=1)//Devuelve 1 en caso de que exista, -1 si no hay trabajadores y 0 si no coincide con ningun trabajador
	{
		cout<<"No existe el trabajador al que se quiere modificar"<<endl;
	}

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

istream& operator>>(istream& in, Trabajador t)
{
	in>>t.getDNI()>>endl;
	in>>t.getNombre()>>endl;
	in>>t.getApellido()>>endl;
	in>>t.getPuesto()>>endl;
	in>>"---------------------------">>endl;

	return in;
}