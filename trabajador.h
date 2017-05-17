#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_
#include <string>
using namespace std;

class Trabajador
{
private:
	int DNI;
	string nombre;
	string apellido;
	string puesto;

public:
	Trabajador();
	Trabajador(int DNI, string nombre, string apellido, string puesto);

	//Para cambiar cualquier atributo del trabajador primero tenemos que buscar el trabajador que nos interesa en fichero (por DNI), despues
	//hacer los sets al trabajador que nos interesen y finalmente escribir en fichero
	void setNomApe(int DNI, string nombre, string apellido);
	int getDNI();
	string getNombre();
	string getApellido();
	string getPuesto();
	void EScribirTrabajador();
	//void setPuesto(int DNI, string puesto);
	//Funcion que escribira directamente en fichero el trabajador
	friend istream& operator>>(istream &in, Trabajador t);
	//Falta eliminar trabajador


	//Vamos a implementar de C las clases que muestran trabajadores y chequean trabajadores
};

#endif