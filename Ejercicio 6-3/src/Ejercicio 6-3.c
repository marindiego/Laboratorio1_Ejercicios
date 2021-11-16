/*

  Marin Diego (1c)

  Ejercicio 6-3:

	Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido).
	Ninguna de las dos variables se puede modificar.
	Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
	Por ejemplo:
	Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:

	Gomez, Juan Ignacio

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones_matematicas.h"
#include "funciones_string.h"

void getString (char cadena[], char mensaje[], char mensajeError [] );

int main(void) {

	setbuf(stdout, NULL);

	char nombre[21];
	char apellido[21];
	char mostrarNA[1000];
	int i;

	printf("Ingrese su nombre completo: ");
	fflush(stdin);
	fgets(nombre, sizeof(nombre), stdin);
	nombre[strnlen(nombre, sizeof(nombre))-1]='\0';

	while(strlen(nombre)>sizeof(nombre) ){

		printf("Reingrese su nombre completo: ");
		fflush(stdin);
		fgets(nombre, sizeof(nombre), stdin);
		nombre[strnlen(nombre, sizeof(nombre))-1]='\0';
	}

	printf("Ingrese su apellido: ");
	fflush(stdin);
	fgets(apellido, sizeof(nombre), stdin);
	apellido[strnlen(apellido, sizeof(apellido))-1]='\0';

	while(strlen(apellido)>sizeof(apellido)){

		printf("Reingrese su nombre completo: ");
		fflush(stdin);
		fgets(nombre, sizeof(nombre), stdin);
		nombre[strnlen(nombre, sizeof(nombre))-1]='\0';
	}

	strlwr(nombre);
	strlwr(apellido);

	nombre[0]=toupper(nombre[0]);
	apellido[0]=toupper(apellido[0]);

	for(i=0; i<strnlen(nombre, sizeof(nombre)) ; i++){

		if(isspace(nombre[i])){

			nombre[i+1]=toupper(nombre[i+1]);
			apellido[i+1]=toupper(apellido[i+1]);
		}
	}

	snprintf(mostrarNA, sizeof(mostrarNA), "%s, %s", apellido, nombre);

	puts(mostrarNA);


	return EXIT_SUCCESS;
}

void getString (char cadena[], char mensaje[], int tam ) {


	printf("%s", mensaje);
	fflush(stdin);
	gets(cadena);

	while(strlen(cadena)> tam){

		printf("Reingrese: ");
		fflush(stdin);
		fflush(stdin);
		gets(cadena);
	}
}
