#include "sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

class BasesDeDatos 
{

private:
		sqlite3 *db;
		int num;

public:
	int mostrarTrabajadores();
	int eliminarTrabajador();
	int insertarTrabajador(std::string DNI, std::string nombre, std::string apellido, std::string puesto);

	int insertarVuelo(std::string codigo, std::string origen, std::string destino, std::string fecha, double precio);
	int mostrarVuelo(std::string vuelo);
	int eliminarVuelo(std::string codigo);

	int insertarTarea(std::string cod_tarea,std::string DNI, std::string codigo, std::string descripcion);
	int mostrarTareas();
	int mostrarTareaTrabajador(std::string DNI);
	int eliminarTarea(std::string cod_tarea);

	int chequearTrabajador (char* DNI, char* nombre);
	//int chequearNombre(std::string nombre);
	//int chequearContrasenya(std::string contrasenya);

	BasesDeDatos(std::string dbFile);

	~BasesDeDatos();

	int getNum() const;
	void setNum(int num);
};