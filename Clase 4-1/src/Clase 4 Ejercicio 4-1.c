/*Ejercicio 4-1:

 Marin Diego(1c)

 Realizar un programa EN EL MAIN
 que permita calcular y mostrar
 el factorial de un número.
 Utilizar la función PedirNumero de la ejercitación 3-4.
 Por ejemplo:
 5! = 5*4*3*2*1 = 120*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "biblioteca.h"
int PedirNumero(char mensjae[]);

int main(void) {

	setbuf(stdout,NULL);
	int numeroIngresado;
	int factorial=1;

	numeroIngresado = PedirNumero("Ingrese un numero entre el 1 y 10: ");

	for(int i=1; i<=numeroIngresado; i++){

		factorial=factorial*i;
	}

	printf("El factorial del numero %d es: %d\n",numeroIngresado,factorial);


	return EXIT_SUCCESS;
}

