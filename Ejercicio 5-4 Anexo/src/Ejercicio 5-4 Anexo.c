/*

 Marin Diego (1c)

	Modificar la funcionalidad de la opción 2 del Menú para que la carga del Array sea de forma aleatoria.
	Agregar la funcionalidad de la opción 3 del Menú para mostrar por pantalla los elementos del Array, o sea las edades.

 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones_matematicas.h"
#define T 10

int main(void) {

	setbuf(stdout, NULL);

	int edadesIngresadas[T];

	MenuEnteros(edadesIngresadas, T, "Ingrese una edad entre en 10 y 100: ", "Reingrese una edad valida entre 10 y 100", 9, 101);


	return EXIT_SUCCESS;
}
