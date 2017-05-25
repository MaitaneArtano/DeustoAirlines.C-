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

//Escribe el trabajador en fichero
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
		archivo << t.DNI << endl;
		archivo << t.nombre << endl;
		archivo << t.apellido << endl;
		archivo << t.puesto << endl;
		archivo << "---------------"<<endl;
	}
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
	ifstream ifs(fic.c_str());
	vector<Trabajador> vectorTrabajadores;
	string dato;
	string nada ="---------------";
	int dni;
	string nombre;
	string apellido;
	string puesto;

	while(!ifs.eof())
	{
		
		getline(ifs, dato);
		 if(dato != nada ) //Para asegurar que las rayas no se guardan como atributo del trabajador
		 {
		 		dni = atoi(dato.c_str());
		 		//cout<<"DNI guardado en vector "<<atoi(dato.c_str())<< endl;
		 		
		 		getline(ifs, dato);
		 		nombre = dato;
		 		//cout<<"Nombre guardado en vector "<<dato<<endl;
		 		
		 		getline(ifs, dato);
		 		apellido = dato;
		 		//cout<<"Apellido guardado en vector "<<dato<<endl;
		 	
		 		getline(ifs, dato);
		 		puesto = dato;
		 		//cout<<"Puesto guardado en vector "<<dato<<endl;
		 		
		 }else
		 {
		 	Trabajador t1(dni, nombre, apellido, puesto);
		 	//printTrabajador(t1);
		 	vectorTrabajadores.push_back(t1);
		 }
	}

	ifs.close();
	return vectorTrabajadores;
}

void Trabajador::printTrabajador(Trabajador &t1)
{
	cout << "Trabajador:" << endl;
	cout << "\tDNI: " << t1.getDNI() << endl;
	cout << "\tNombre: " << t1.getNombre() << endl;
	cout << "\tApellido: " << t1.getApellido() << endl;
	cout << "\tPuesto: " << t1.getPuesto() << endl;
	cout << "-------------------: "<< endl;
}


void Trabajador::EliminarTrabajador(string fic)
{
	int DNI;
	bool comprob = false;//Debera cambiar a true en caso de que encuentre un trabajador con el mismo DNI 
	int posTra; //La posicion en el vector del trabajador que quiero eliminar

	vector <Trabajador> vectorAuxiliar;

	cout << "Lista de los trabajadores disponibles:" << endl;
	Trabajador t1;
	
	vector<Trabajador> vectorTrabajadores = t1.leerDeFichero(fic);
	for(int i=0; i<vectorTrabajadores.size(); i++)
	{
		Trabajador t = vectorTrabajadores[i];
		cout<<"Trabajador "<< i+1 <<endl;
		cout<< "\t" << t.getDNI() <<endl;
		cout << "\t" << t.getNombre()<<endl;
		cout<< "\t" << t.getApellido()<<endl;
		cout<<"\t" << t.getPuesto()<<endl;
	}

	do
	{
		cout<<"Escriba el DNI del trabajador(sin letra):"<<endl;
		cin>> DNI;

		for(int i=0; i<vectorTrabajadores.size();i++)
		{
			Trabajador t = vectorTrabajadores[i];
			if(DNI == t.getDNI())
			{
				comprob = true;
				cout<<"He cambiado a true, existe trabajador"<<endl;
				posTra = i;//En esa posición del vector es donde esta el trabajador que quiero eliminar
				break; 
			}else
			{
				comprob = false;
			}
		}
		if(comprob == false)
		{
			cout<<"No se ha encontrado ningun trabajador con ese DNI, intentalo otra vez"<<endl;
		}
	}while(comprob != true);

	vectorTrabajadores.erase(vectorTrabajadores.begin()+posTra);

	cout<<endl;
	cout<<"NUEVO VECTOR"<<endl;
	for(int i=0; i<vectorTrabajadores.size(); i++)
	{
		Trabajador t = vectorTrabajadores[i];
		cout<<"Trabajador "<< i+1 <<endl;
		cout<< "\t" << t.getDNI() <<endl;
		cout << "\t" << t.getNombre()<<endl;
		cout<< "\t" << t.getApellido()<<endl;
		cout<<"\t" << t.getPuesto()<<endl;
	}

	//Ahora elimino el fichero de trabajadores para escribir el nuevo
	if(remove("Trabajador.txt") != 0)
	{
		cout<<"Error al eliminar fihcero Trabajador.txt"<<endl;
	}else
	{
		cout<<"Fichero correctamente eliminado"<<endl;
	}

	//Finalmente, reescribo el fichero con los datos del nuevo vector
	for(int i=0; i<vectorTrabajadores.size();i++)
	{
		Trabajador t = vectorTrabajadores[i];
		EscribirTrabajador(t);
	}

}	
			
		






