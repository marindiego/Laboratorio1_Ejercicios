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

	FILE* pArchivo;

	char nombre[30]="Diego";
	char apellido[30]="Marin";

	pArchivo = fopen("archivo_texto.txt", "w");

	if (pArchivo!=NULL ) {

		fprintf(pArchivo,"%s\n%s\n",nombre,apellido); // para escribir en un archivo

		printf("Abrir archivo extitoso\n");

		fclose(pArchivo);
	}
	else{

		printf("No se encontro el archivo\n");
	}

	/*pArchivo = fopen("archivo_texto.txt", "r");

	fgets(cadena,30,pArchivo);

	fclose(pArchivo);

	puts(cadena);*/

	return EXIT_SUCCESS;
}
