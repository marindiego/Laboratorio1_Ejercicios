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
#include <windows.h>

int main(void) {
	setbuf(stdout,NULL);
	system("color 63");

	int x,o;

	do{
	printf("Elija una opcion: \n ");
	printf("1 Ingresar numero: %d \n ", x );

	scanf("%d", &o);

	switch(o){

	case 1:
		printf("Ingrese el primer operando: ");
		scanf("%d", &x);
		system("cls");
		break;
	}

	}while(o!=3);
	return EXIT_SUCCESS;
}
