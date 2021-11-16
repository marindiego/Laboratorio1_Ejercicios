/*
 Marin Diego (1C)


	Realizar un programa que permita el ingreso de 10 números enteros distintos de cero.
	La carga deberá ser aleatoria (todos los elementos se inicializan en cero por default).
	Determinar el promedio de los positivos, y del menor de los negativos la suma de los antecesores
	(Según la recta numérica de los reales, hasta llegar a cero).
	Utilizar funciones y vectores.

 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones_matematicas.h"
#include "biblioteca.h"
#define T 10


int main(void) {

	setbuf(stdout, NULL);

	int numerosIngresados[T];
	float promedioPositivos, promedioNegativos, sumaNegativos;

	CargarEnterosAleatorios(numerosIngresados, T);

	PromedearVectorEntero(&promedioPositivos, &promedioNegativos, numerosIngresados, T);

	SumarEnterosNegativos(numerosIngresados, T, &sumaNegativos);

	return EXIT_SUCCESS;
}
