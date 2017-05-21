#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Trabajador
{
private:
	int DNI;
	string nombre;
	string apellido;
	string puesto;

public:
	//Constructores
	Trabajador(){};
	Trabajador(int DNI, string nombre, string apellido, string puesto);
	~Trabajador(){};

	//Getters y setters
	void setDNI(int DNI);
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setPuesto(string puesto);
	int getDNI();
	string getNombre();
	string getApellido();
	string getPuesto();

	void EscribirTrabajador(Trabajador& t);
	void ConsultarTrabajadores();
	//void ModificarTrabajador(string fic);
	vector<Trabajador> leerDeFichero(string fic);
	int longFichero(string fic);
	//void ReescribirEnFichero (string fic,  vector<Trabajador> t);

	//Funcion que escribira directamente en fichero el trabajador
	friend istream& operator>>(istream &in, Trabajador& t);
	

	//Vamos a implementar de C las clases que muestran trabajadores y chequean trabajadores
};

#endif