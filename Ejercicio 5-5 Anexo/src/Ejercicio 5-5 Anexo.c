/*

	Marin Diego(1c)

	Modificar la funcionalidad de la opción 3 del Menú de forma que existan 2 funciones una que muestre solamente un elemento o edad
	y otra que muestre todos los elementos o edades. La función que muestra todos los elementos o edades debe llamar a la que muestra solo uno.
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones_matematicas.h"
#define T 5

int main(void) {

	setbuf(stdout, NULL);

	int edadesIngresadas[T];

	MenuEnteros(edadesIngresadas, T, "Ingrese su edad entre 10 y 21: ", "Reingrese su edad entre 10 y 21: ", 9, 22, 0);

	return EXIT_SUCCESS;
}
