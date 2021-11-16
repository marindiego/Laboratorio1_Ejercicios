/*

 Marin Diego(1c)

	Modificar la función que calcula el promedio en la opción 4 del Menú,
	para que devuelva el resultado del promedio por parámetro por referencia.
	El retorno de la misma debe indicar si funcionó correctamente.
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
