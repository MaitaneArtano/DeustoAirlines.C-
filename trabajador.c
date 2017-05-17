#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"

#define MAX_LENGTH 200

void LeerTrabajadores();
void asignarTarea();
void guardarEnFic(int DNI, int codigo, char *descrip);
void LeerAgenda();

void LeerTrabajadores()
{
    char *str;
    FILE *fic;
    fic = fopen("trabajador.txt", "r");
    char str2[500];
    int endfile=0;

    if(fic == NULL)
    {
        printf("No hay trabajadores registrados");
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


void asignarTarea()
{
    int existe;
    int existe1=20;
    int codigo=0;
    char str1[20];
    char descrip[MAX_LENGTH];
    int DNI=0;
    char str3[MAX_LENGTH];
    printf("Lista de trabajadores disponibles:\n");
    LeerTrabajadores();

    printf("\n\nEscriba el DNI del trabajador al que quieres asignar un puesto\n");
    do
    {
        fgets(str1, 9, stdin);
        clear_if_needed(str1);
        sscanf(str1, "%i", &DNI);
    }while(DNI==0);

    existe = validacion(DNI);//Devuelve 1 en caso de que exista, -1 si no hay trabajadores y 0 si no coincide con ningun trabajador
    if(existe==0)
    {
        printf("El trabajador no coincide con ningun trabajador\n");
    }if(existe==-1)
    {
        printf("No hay trabajadores\n");
    }if(existe==1)
    {
        printf("\nTrabajador encontrado!\n");
        printf("Lista de vuelos disponibles:\n");
        LeerVuelos(); 
        printf("Escriba el codigo del vuelo al que quieres asignar al trabajador\n");

        do
        {
            fgets(str1, MAX_LENGTH, stdin);
            clear_if_needed(str1);
            sscanf(str1, "%i", &codigo);
        }while(codigo==0);

        existe1=validacionVuelo(codigo);
        if(existe1==0)
        {
            printf("El vuelo no coincide con ningun vuelo\n");
        }if(existe1==-1)
        {
            printf("No hay vuelos registrados\n");
        }if(existe1==1)
        {
            printf("\nVuelo encontrado!\n");

            printf("Introduzca una breve descripcion de lo que realizara el trabajador: \n");
                   do
                   {
                     fgets(str3, 200, stdin);
                     clear_if_needed(str3);
                     sscanf(str3, "%s", &descrip);
                   }while(descrip==NULL);


            printf("\n Guardando en fichero... \n");
            guardarEnFic( DNI, codigo, descrip);
            printf("\n RELACION GUARDADA!!\n");
        }
    }

}

void guardarEnFic(int DNI, int codigo, char *descrip) 
{
    FILE *fic;
    fic = fopen("agenda.txt", "a");

    fprintf(fic, "\n El DNI del trabajador es: %i\n", DNI);
    fprintf(fic, "El codigo del vuelo: %i\n", codigo);
    fprintf(fic, "Descripcion: %s\n", descrip);
    fprintf(fic, "------------------\n" );
    fprintf(fic, "------------------\n" );

    fclose(fic);
}


void LeerAgenda()
{
    
    FILE *fic;
    fic = fopen("agenda.txt", "r");
    char str4[500];
    int endfile=0;

    if(fic == NULL)
    {
        printf("No hay tareas asignadas");
    }else
    {
            endfile = fscanf(fic, " %[^\n] ", &str4);
            while(endfile != EOF)
            {
                printf(" %s\n " , str4);
                endfile = fscanf(fic, " %[^\n] \n", &str4);
            }
          
        fclose(fic);
    }

}







