/*

 Marin Diego(1c)

	Modificar la funci�n que calcula el promedio en la opci�n 4 del Men�,
	para que devuelva el resultado del promedio por par�metro por referencia.
	El retorno de la misma debe indicar si funcion� correctamente.
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones_matematicas.h"
#define T 5

int main(void) {

	setbuf(stdout, NULL);

	int edadesIngresadas[T];

	MenuEnteros(edadesIngresadas, T, "Ingrese su edad entre 1 y 25: ", "Reingrese su edad entre 1 y 25: ", 0, 26, 0);


	return EXIT_SUCCESS;
}
