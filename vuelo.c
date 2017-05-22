#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"

#define MAX_LENGTH 20

int IntroducirVuelo();
void clear_if_needed(char *str);
void guardarEnFichero(int codigo, char *origen, char *destino, char *fecha, float precio);
void LeerVuelos();


int IntroducirVuelo() //Devolvera 1 en caso de que no se pueda o no se quiera escribir en fichero, 0 si se consigue
{
    int opcion;
    int codigo=0;
    char str1[MAX_LENGTH];
    char origen[MAX_LENGTH];
    char destino[MAX_LENGTH];
    char fecha[9];
    float precio;

    printf("\nIntroduzca el codigo del vuelo:\n");
    do
    {
        fgets(str1, 9, stdin);
        clear_if_needed(str1);
        sscanf(str1, "%d", &codigo);
    }while(codigo==0);

    printf("Introduzca el origen del vuelo:\n");
    do
    {
        fgets(str1, 20, stdin);
        clear_if_needed(str1);
        sscanf(str1, "%[^\n]s", origen);
    }while(origen==NULL);

    printf("Introduzca el destino del vuelo:\n");
    do
    {
        fgets(str1, 20, stdin);
        clear_if_needed(str1);
        sscanf(str1, "%[^\n]s", &destino);
    }while(destino==NULL);

    printf("Introduzca la fecha del vuelo, en formato xx/xx/xx:\n");
    do
    {
        fgets(str1, 9, stdin);
        clear_if_needed(str1);
        sscanf(str1, "%s", &fecha);
    }while(fecha==NULL);

     printf("Introduzca el precio del vuelo, con 2 decimales:\n");
    
    do
    {
    fgets(str1, 9, stdin);
    clear_if_needed(str1);
    sscanf(str1, "%f", &precio);
    } while(precio == 0.0);   

    printf("\n\n LOS DATOS DEL VUELO SON: \n");
    printf("El codigo de vuelo es: %i \n", codigo);  
    printf("El origen de vuelo es: %s \n", origen);
    printf("El destino de vuelo es: %s \n", destino);
    printf("La fecha de vuelo es: %s \n", fecha);
    printf("El precio de vuelo es: %.2f \n", precio);

    printf("\n\n Guardando en fichero...\n");

    guardarEnFichero(codigo, origen, destino, fecha, precio);

    printf("Vuelos guardados!\n");
}

void guardarEnFichero(int codigo, char *origen, char *destino, char *fecha, float precio) 
{
    FILE *fic;
    fic = fopen("vuelos.txt", "a");

    fprintf(fic, "%i\n", codigo);
    fprintf(fic, "%s\n", origen);
    fprintf(fic, "%s\n", destino);
    fprintf(fic, "%s\n", fecha);
    fprintf(fic, "%.2f\n\n", precio);
    fprintf(fic, "------------------\n" );
    fprintf(fic, "------------------\n" );

    fclose(fic);
}

void LeerVuelos()
{
    char *str;
    FILE *fic;
    fic = fopen("vuelos.txt", "r");
    char str2[500];
    int endfile=0;

    if(fic == NULL)
    {
        printf("No hay vuelos registrados");
    }else
    {
            endfile = fscanf(fic, " %[^\n] ", &str2);
            while(endfile != EOF)
            {
                printf(" %s\n " , str2);
                endfile = fscanf(fic, " %[^\n] \n", &str2);
            }
          
        fclose(fic);
    }
}



