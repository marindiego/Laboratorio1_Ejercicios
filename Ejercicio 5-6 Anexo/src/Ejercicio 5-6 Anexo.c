/*

 Marin Diego(1c)

 	 Realizar una función que calcule el promedio de los números ingresados en el Array y agregarlo a la opción de Menú 4.
 	 La misma deberá imprimir el resultado por pantalla.
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
