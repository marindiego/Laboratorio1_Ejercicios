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

	int a;
	int b;
	printf("Size a: %lld\n",sizeof(a));
	printf("Direccion a: %p\n",&a);

	printf("Size a: %lld\n",sizeof(b));
	printf("Dirrecion b: %p\n",&b);

	return EXIT_SUCCESS;
}
