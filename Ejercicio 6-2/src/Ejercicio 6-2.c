/*

 Marin Diego (1c)

	Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
	Necesito generar un listado de los números positivos de manera creciente y negativos de manera decreciente.
	(Como máximo 5 estructuras repetitivas)
	Ejemplo:
	Listado 1 : 4, 5, 6, 10, 18, 29
	Listado 2 : -1,-5,-9,-12

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones_matematicas.h"
#define T 10

int main(void) {

	setbuf(stdout, NULL);



	int numerosIngresado [T]={-1,3,-9,-12, 7, -5, 6, 10, -8, 5};
	int i;
	int numerosNegativos [T];
	int* pArrayNegativos [T];
	int numerosPositivos [T];
	int* pArrayPositivos [T];

	//CargarNumerosEnteros(numerosIngresado, T, "Ingrese un numero positivo o negativo " , " Reingrese un entero ", -1000, 1000);
	InicializarVectorEnteroExcluyente(numerosPositivos, T, 0);
	InicializarVectorEnteroExcluyente(numerosNegativos, T, 0);


	for (i = 0; i < T; ++i) {

		pArrayPositivos[i]=&numerosPositivos[i];
		pArrayNegativos[i]=&numerosNegativos[i];
	}

	for(i=0; i<T; i++){

		if(VereficarSigno(numerosIngresado[i])==0){

			numerosPositivos[i]=numerosIngresado[i];
		}
		if(VereficarSigno(numerosIngresado[i])==-1){

			numerosNegativos[i]=numerosIngresado[i];
		}
	}

		printf("Listado 1\n\n");
		OrdenarNumerosEnterosCreciente(pArrayPositivos, T);
		MostrarNumerosEnteros(numerosPositivos, T, 0);


		printf("\nListado 2\n\n");
		OrdenarNumerosEnterosDecreciente(pArrayNegativos, T);
		MostrarNumerosEnteros(numerosNegativos, T, 0);



	return EXIT_SUCCESS;
}
