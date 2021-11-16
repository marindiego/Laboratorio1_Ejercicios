/*

 Marin Diego (1c)

  Ejercicio 6-1:
  Disponemos de dos variables numéricas (a y b). Realizar un algoritmo que permita el intercambio de valores de dichas variables.


 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {

	setbuf(stdout,NULL);

	int a = 10;
	int b = 20;
	int aux;

	printf(" VALOR A: %d - VALOR B: %d \n", a, b);

	printf(" \n INTERCAMBIO \n ");

	//Algoritmo de intercambio
	aux=a;
	a=b;
	b=aux;

	printf("\n VALOR A: %d - VALOR B: %d \n", a, b);


	return EXIT_SUCCESS;
}
