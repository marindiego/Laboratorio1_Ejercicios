/*
 ============================================================================
 Name        : Practica.c
 Author      : DIego
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "utn_funciones.h"

int IntercambioCaracterComodin (char *cadena, char caracterComodin);
int CalcularDivisoresDeUnNumero (int numero);

int main(void) {

	setbuf(stdout, NULL);


	return EXIT_SUCCESS;
}
int IntercambioCaracterComodin (char *cadena, char caracterComodin){

	int i;
	int contadorVocales=0;

	if(cadena!= NULL ){

		strlwr(cadena);

		for(i=0; cadena[i]!='\0'; i++){

			if(cadena[i]=='a' || cadena[i]=='e' || cadena[i]=='i' || cadena[i]=='o' || cadena[i]=='u'){

				cadena[i]=caracterComodin;
				contadorVocales++;
			}
		}
	}

	return contadorVocales;
}

int CalcularDivisoresDeUnNumero (int numeroIngresado){

	int contador = 0;

	if (numeroIngresado > 0 ) {

		for (int i = 1; i <= numeroIngresado; i++) {

			if (numeroIngresado%i == 0) {

				contador++;
			}
		}
	}

	return contador;
}









