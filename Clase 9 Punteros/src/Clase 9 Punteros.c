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

	int a=5;
	int b;
	int* p;

	printf("Size a: %lld\n",sizeof(a)); //4
	printf("Direccion a: %p\n",&a); // direccion de memoria de a

	printf("Size b: %lld\n",sizeof(b)); //4
	printf("Dirrecion b: %p\n",&b); // direccion de memoria de b

	p=&a;

	printf("\n%p\n", &a);
	printf("%d\n", *p);
	printf("%p\n", p);
	printf("%p\n", &p);

	/*
	 * direccion de memoria de a
	 * El contenido de la direccion de memoria que apunta la variable p
	 * direccio de memoria de a
	 * direccion de memoria de p
	 */




	return EXIT_SUCCESS;
}
