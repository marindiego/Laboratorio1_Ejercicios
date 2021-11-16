/*
 ============================================================================
 Name        : Clase.c
 Author      : DIego
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {

	setbuf(stdout,NULL);
    int numero;
    int factorial;

    printf("Ingrese un numero: ");
    fflush(stdin);
    scanf("%d",&numero);


    factorial=CalcularFactorial(numero);

    printf("El factorial del numero es %d", factorial);

	return EXIT_SUCCESS;
}







