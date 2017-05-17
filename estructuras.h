#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_


void clear_if_needed(char *str);
//Metodos de menu.c
void menuPrincipal();
int validacion(int DNI);
int validacionVuelo(int cod_vuelo);

//Metodos de vuelo.c
int IntroducirVuelo();
void guardarEnFichero(int codigo, char *origen, char *destino, char *fecha, float precio);
void LeerVuelos();

//Metodos de trabajador.c
void LeerTrabajadores();
void asignarTarea();
void guardarEnFic(int DNI, int codigo, char *descrip);
void LeerAgenda();

#endif 