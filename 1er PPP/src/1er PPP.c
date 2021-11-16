/*

 Marin Diego (1c)

	1C_Módulo Práctico PP

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones_matematicas.h"
#include "funciones_string.h"


int IntercambioCaracterComodin (char *cadena, char caracterComodin);

int main(void) {

	setbuf(stdout, NULL);

	/*Realizar un párrafo en donde se pueda observar la/s relación/es entre los siguientes términos:
	 vector, estructura repetitiva, dirección de memoria, pasaje por valor, pasaje por referencia.
	 No esta permitido realizar definiciones de manual,
	 es necesario que el párrafo demuestre las relaciones entre los términos.*/


	// Una relacion principal que comparte esos conceptos puede ser una funcion o memoria estatica.



	/*2. Realizar una función que reciba como parámetro una cadena de caracteres.
  	 La misma permitirá intercambiar las vocales por un carácter comodín que también será recibido como parámetro.
  	 La función retornará la cantidad de reemplazos que se llevaron a cabo.*/


	char letrasIngresadas[6]={"diego"};
	int vocales;

	vocales=IntercambioCaracterComodin(letrasIngresadas, '$');

	if(vocales>0){

		printf(" \n Vocales: %d \n", vocales );
	}

	puts(letrasIngresadas);

	/*3. Realizar una función que reciba como parámetro el importe de un producto y un porcentaje de descuento.
	  La función retornará el importe con el descuento aplicado. */





	return EXIT_SUCCESS;
}

int IntercambioCaracterComodin (char *cadena, char caracterComodin){

	int i;
	int contadorVocales;

	if(cadena!= NULL ){

		for(i=0; cadena[i]!='\0'; i++){

			if(cadena[i]=='a' || cadena[i]=='e' || cadena[i]=='i' || cadena[i]=='o' || cadena[i]=='u'){

				cadena[i]=caracterComodin;
				contadorVocales++;
			}
		}
	}

	return contadorVocales;
}
