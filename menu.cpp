#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "trabajador.h"


void InsertarTrabajador() // validar el DNI del trabajador antes de guardar en fichero
{


	Trabajador t1;

	cin >> t1; //Pedimos datos y los guardamos en t1

	t1.EscribirTrabajador(t1);


}