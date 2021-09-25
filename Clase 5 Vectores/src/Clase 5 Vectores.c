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

int main(void) {

	setbuf(stdout,NULL);

	int v[5]; //Cantidad de elementos que va a tener el vector
	int i;

	// Secuencial
    for(i=0; i<5; i++){

        printf("Ingrese el valor del vector %d:", i+1);
        scanf("%d",&v[i]);
    }



	return EXIT_SUCCESS;
}
