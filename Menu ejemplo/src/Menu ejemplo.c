/*
 ============================================================================
 Name        : Menu.c
 Author      : DIego
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int opcion;
	setbuf(stdout,NULL);
	do
	{
		printf("\nAlta usuario\n");
		printf("Baja Usuario\n");
		printf("Modificacion Usuario\n");
		printf("Salir\n");
		printf("Elija una opcion:");
		scanf("%d", &opcion);
		switch(opcion)
		{
		case 1:
			printf("ACA ESTOY DANDO DE ALTA");
			break;
		case 2:
			printf("ACA ESTOY DANDO DE BAJA");
			break;
		case 3:
			printf("ACA ESTOY MODIFICANDO");
			break;
		case 4:
			printf("GRACIAS POR USAR NUESTRO PROGRAMA");
			break;
		}
	}while(opcion!=4);

	return EXIT_SUCCESS;
}
