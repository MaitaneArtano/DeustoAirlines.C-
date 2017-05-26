#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"

int validacionVuelo(int cod_vuelo);


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

void clear_if_needed(char *str)
{
	 if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }
}







