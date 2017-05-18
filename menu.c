#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"

int validacion(int DNI);
int validacionVuelo(int cod_vuelo);

void menuPrincipal()
{
	int opcion;

	do
	{
		printf("\nIntroduzca una de las siguientes opciones:\n");
		printf("1.- Crear vuelo\n");
		printf("2.- Consultar vuelos\n");
		printf("3.- Consultar trabajadores\n");
		printf("4.- Asignar tarea a trabajador\n");
		printf("5.- Ver agenda de trabajo\n");
		printf("6.- Insertar nuevo trabajador");
		printf("7.- Salir\n");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				printf("Ha escogido crear un nuevo vuelo. \n");
				IntroducirVuelo(); 
				break;

			case 2:
				printf("Ha escogido consultar los vuelos existentes. \n");
				LeerVuelos();
				break;

			case 3:
				printf("Ha escogido consultar los trabajadores existentes. \n");
				LeerTrabajadores();
				break;

			case 4:
				printf("Ha escogido asignar tarea a trabajador. \n");
				asignarTarea();
				break;

			case 5:
				printf("\n Ha escogido ver la lista de agenda de trabajo: \n" );
				LeerAgenda();
				break;

			case 6:
				printf("\n Ha escogido insertar trabajador: \n");
				InsertarTrabajador();
				break;

			case 7:
				printf("Adios!\n");
				break;

			default:
				printf("La opcion elegida es incorrecta\n");
				break;
		}
	}while(opcion!=7);
}

int validacion(int DNI)//Devuelve 1 en caso de que exista, -1 si no hay trabajadores y 0 si no coincide con ningun trabajador
{
	FILE *fichero;
	fichero = fopen("trabajador.txt", "r");
	char r[50];
	int DNI2; //El DNI que se lee desde el fichero
	if(fichero==NULL)
	{
		return -1; //Devuelve -1 como senyal de que no hay trabajadores registrados
	}else
	{
		while(fgets(r, 50, fichero))
		{

        	sscanf(r, "%d", &DNI2);
			if(DNI==DNI2)
			{
        		return 1; //En caso de que el DNI introducido coincida con el de algun trabajador      
        	}
     	}
		return 0; //En caso de que el DNI NO coincida con el de ningun trabajador
	}
}

int validacionVuelo(int cod_vuelo)//Devuelve 1 en caso de que exista, -1 si no hay vuelos y 0 si no coincide con ningun vuelo
{
	FILE *fichero;
	fichero = fopen("vuelos.txt", "r");
	char r[50];
	int cod_vuelo2; //El codigo de vuelo que se lee desde el fichero
	if(fichero==NULL)
	{
		return -1; //Devuelve -1 como senyal de que no hay vuelos registrados
	}else
	{
		while(fgets(r, 50, fichero))
		{

        	sscanf(r, "%d", &cod_vuelo2);
			if(cod_vuelo==cod_vuelo2)
			{
        		return 1; //En caso de que el codigo de vuelo introducido coincida con el de algun vuelo      
        	}
     	}
		return 0; //En caso de que el codigo de vuelo NO coincida con el de ningun vuelo
	}
}






