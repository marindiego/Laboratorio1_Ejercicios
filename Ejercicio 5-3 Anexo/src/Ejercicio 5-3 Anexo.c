/*

 Marin Diego(1c)

	Crear un Array de 5 elementos de tipo num�rico donde se cargar�n edades.
	Agregar la funcionalidad para la opci�n 1 del Men� del ejercicio anterior utilizando funciones,
	es decir una funci�n que inicialice el Array.
	Agregar la funcionalidad para la opci�n 2 del Men� utilizando funciones,
	es decir una funci�n que le pida los n�meros o edades al usuario para cargar el Array de forma secuencial.

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
