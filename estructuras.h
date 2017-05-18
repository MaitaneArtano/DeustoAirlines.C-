#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

#ifdef __cplusplus

extern "C"
{
	#endif

	//Metodos de menu.c
	int validacion(int DNI);
	int validacionVuelo(int cod_vuelo);
	void clear_if_needed(char *str);

	//Metodos de vuelo.c
	int IntroducirVuelo();
	void guardarEnFichero(int codigo, char *origen, char *destino, char *fecha, float precio);
	void LeerVuelos();

	//Metodos de trabajador.c
	void LeerTrabajadores();
	void asignarTarea();
	void guardarEnFic(int DNI, int codigo, char *descrip);
	void LeerAgenda();


	#ifdef __cplusplus
}

#endif

#endif