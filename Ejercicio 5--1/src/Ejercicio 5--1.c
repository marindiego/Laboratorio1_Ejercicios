/*
 Marin Diego Dic(C)

 Ejercicio 5-1:
Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.

 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "funciones_matematicas.h"
#define T 5

int main(void) {

	setbuf(stdout, NULL);

	int numerosIngresados[T];
	int i;
	int suma=0;
	int posicion;
	int numeroIngresado;

	//le agregamos un valor a cada posicion en caso de no ser una carga secuencial

	for(i=0; i<T; i++){

		numerosIngresados[i]=0;
	}


	for(i=0; i<T; i++){

		numeroIngresado=IngresarNumeroEntero("Ingrese un numero entero: ", "Reingrese un numero entero: ");
		posicion=IngresarNumeroEntero("En que posicion quiere guardarlo 1-5 ?","Reingrese un numero entero: ");
		numerosIngresados[posicion-1]=numeroIngresado;
	}

	for(i=0; i<T; i++){

		suma+=numerosIngresados[i];
		printf("El numero en la posicion %d es: %d\n",i+1, numerosIngresados[i] );
	}

	printf("La sumatoria de lo numeros es: %d \n", suma);



	return EXIT_SUCCESS;
}
