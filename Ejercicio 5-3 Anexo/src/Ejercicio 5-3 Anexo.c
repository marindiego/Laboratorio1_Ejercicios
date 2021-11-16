/*

 Marin Diego(1c)

	Crear un Array de 5 elementos de tipo numérico donde se cargarán edades.
	Agregar la funcionalidad para la opción 1 del Menú del ejercicio anterior utilizando funciones,
	es decir una función que inicialice el Array.
	Agregar la funcionalidad para la opción 2 del Menú utilizando funciones,
	es decir una función que le pida los números o edades al usuario para cargar el Array de forma secuencial.

 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones_matematicas.h"
#define T 5
int main(void) {

	setbuf(stdout, NULL);

	int edadesIngresadas[5];

	MenuEnteros(edadesIngresadas, T, "Ingrese su hermosa edad xfa entre el 10 y 21: ","Reingrese su hermosa edad entre 10 y 21" , 11, 20);


	return EXIT_SUCCESS;
}
