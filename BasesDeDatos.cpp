#include "sqlite3.h"
#include "DBConnector.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX 100
#define DNI 3

int BasesDeDatos::getNum() const
{
	return this->num;
}

void BasesDeDatos::setNum(int num)
{
	this->num = num;
}

int clear_if_neededCT (char *str)
{

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }

    return 0;
}


// METODOS PARA TRABAJADOR 

int BasesDeDatos::insertarTrabajador(std::string DNI, std::string nombre, std::string apellido, std::string puesto) 
{
	sqlite3_stmt *stmt;

	char sql[] = "insert into TRABAJADOR (DNI, nombre, apellido, puesto) values (?, ?, ?, ?)"; 
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, DNI.c_str(), DNI.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, nombre.c_str(), nombre.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, apellido.c_str(), apellido.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, puesto.c_str(), puesto.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into trabajador table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int BasesDeDatos::chequearTrabajador(char* DNI)
{
	sqlite3_stmt *stmt;
	setNum(0);

	char sql[] = "select DNI from TRABAJADOR";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	char dniBD[100];
	
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			strcpy(dniBD, (char *)sqlite3_column_text(stmt, 0));

			if (strcmp(DNI, dniBD)==0 ) 
				setNum(5);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	

	return SQLITE_OK;
}

int BasesDeDatos::eliminarTrabajador(std::string DNI) //borra el contenido del DNI que hemos seleccionado
{


	char sql[] = "delete from TRABAJADOR where DNI = ? ";

	sqlite3_stmt *stmt;

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_bind_int(stmt, 1, id);

	if(result != SQLITE_OK)
	{
		printf("Error binding parameter(DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, trabajador.c_str(), strlen(trabajador.c_str()), 0);

		if(result != SQLITE_OK)
	{
		printf("Error binding parameter(DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	//PARA PODER EJECUTAR LA CONSULTA

	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}


// METODOS PARA VUELOS 

int BasesDeDatos::insertarVuelo(std::string codigo, std::string origen, std::string destino, std::string fecha, double precio) 
{
	sqlite3_stmt *stmt;

	char sql[] = "insert into VUELO (codigo, origen, destino, fecha, precio) values (?, ?, ?, ? , NULL)"; 
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, codigo.c_str(), codigo.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, origen.c_str(), origen.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, destino.c_str(), destino.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, fecha.c_str(), fecha.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	//// NOOO SE COMO PONER PAL PRECIO

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into vuelo table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}
