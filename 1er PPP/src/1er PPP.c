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
int CalcularDivisoresDeUnNumero (int numero, int* divisores);

int main(void) {

	setbuf(stdout, NULL);

	/*1. Realizar un párrafo en donde se pueda observar la/s relación/es entre los siguientes términos: vector, estructura repetitiva,
	 dirección de memoria, pasaje por valor, pasaje por referencia. No esta permitido realizar definiciones de manual,
	 es necesario que el párrafo demuestre las relaciones entre los términos.*/



	/*
	 *
	 * Un ejemplo podria ser cargar un vector en una funcion en el cual la funcion va a recibir como argumento
	 * el vector que es una pasaje por refencia ya que cuando se pasa solo el nombre del vector hace referencia que es donde empieza la primera
	 * direccion memoria del vector y como segundo argumento el tamaño de ese vector por pasaje por valor, recorremos el vector con una estrucutra repetitiva
	 * ya sea un  do while, while o un for, se recomienda un for, cargamos un valor en cada posicion del vector y luego hariamos otra estrucutra repetitiva para mostrar los elementos del vector
	 *
	 */


	/*
	 *
	 * 2. Realizar una función que reciba como parámetro una cadena de caracteres.
	 * La misma permitirá intercambiar las vocales por un carácter comodín que también será recibido como parámetro.
	 * La función retornará la cantidad de reemplazos que se llevaron a cabo.
	 * */

	char letrasIngresadas[6]={"diego"};
	int vocales;

	vocales=IntercambioCaracterComodin(letrasIngresadas, '$');

	if(vocales>0){

		printf(" \n Vocales: %d \n", vocales );
		puts(letrasIngresadas);
	}



	/*
	 * Realizar una función que reciba y retorne un entero.
	 * La función deberá hallar cuántos divisores hay del numero recibido como parámetro entre la unidad y el mismo.
	 * Retornará la cantidad encontrada.
	 * */


	int divisores;
	int numeroIngresado = 10;

	if(!CalcularDivisoresDeUnNumero(numeroIngresado,&divisores)){

		printf("Cantida encontradas: %d", divisores);
	}
	else
		printf("Ocurrio un error, vuelva intentarlo \n");



	return EXIT_SUCCESS;
}
int IntercambioCaracterComodin (char *cadena, char caracterComodin){

	int i;
	int contadorVocales=0;

	if(cadena!= NULL &&  caracterComodin != NULL){

		strlwr(cadena);

		for(i=0; cadena[i]!='\0'; i++){

			if(cadena[i]=='a' || cadena[i]=='e' || cadena[i]=='i' || cadena[i]=='o' || cadena[i]=='u'||
					cadena[i]=='A' || cadena[i]=='E'|| cadena[i]=='I'|| cadena[i]=='O'|| cadena[i]=='U')
			{

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


















