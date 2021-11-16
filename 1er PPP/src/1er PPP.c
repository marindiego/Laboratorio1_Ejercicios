/*

 Marin Diego (1c)

	1C_M�dulo Pr�ctico PP

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

	/*Realizar un p�rrafo en donde se pueda observar la/s relaci�n/es entre los siguientes t�rminos:
	 vector, estructura repetitiva, direcci�n de memoria, pasaje por valor, pasaje por referencia.
	 No esta permitido realizar definiciones de manual,
	 es necesario que el p�rrafo demuestre las relaciones entre los t�rminos.*/


	// Una relacion principal que comparte esos conceptos puede ser una funcion o memoria estatica.



	/*2. Realizar una funci�n que reciba como par�metro una cadena de caracteres.
  	 La misma permitir� intercambiar las vocales por un car�cter comod�n que tambi�n ser� recibido como par�metro.
  	 La funci�n retornar� la cantidad de reemplazos que se llevaron a cabo.*/


	char letrasIngresadas[6]={"diego"};
	int vocales;

	vocales=IntercambioCaracterComodin(letrasIngresadas, '$');

	if(vocales>0){

		printf(" \n Vocales: %d \n", vocales );
	}

	puts(letrasIngresadas);

	/*3. Realizar una funci�n que reciba como par�metro el importe de un producto y un porcentaje de descuento.
	  La funci�n retornar� el importe con el descuento aplicado. */





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
