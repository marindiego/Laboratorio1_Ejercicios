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

typedef struct{
	int a;
	char c;
}Dato;

int main(void) {

	setbuf(stdout,NULL);

	int d=5;
	int b;
	int* p;

	p = &d;

	printf("Size a: %d\n",sizeof(d)); //4
	printf("Direccion a: %p\n",d); // direccion de memoria de a

	printf("Size b: %lld\n",sizeof(b)); //4
	printf("Dirrecion b: %p\n",&b); // direccion de memoria de b

	printf("\n%p\n", &d);
	printf("%d\n", *p);
	printf("%p\n", p);
	printf("%p\n", &p);

	/*
	 * direccion de memoria de a
	 * El contenido de la direccion de memoria que apunta la variable p
	 * direccio de memoria de a
	 * direccion de memoria de p
	 */
	int i;

	int vector[10]; // Memoria estatica _
	int* pVector;// Memoria dinamica    _|-"Lo mismo"

	int numeros[10];
	int *pArrayNumeros[10];

	//Inicializar array de punteros

	for (i = 0; i < 10; i++) {

		pArrayNumeros[i]=&numeros[i];
	}

	char* pArrayCaracteres[12];
	char caracteres [12]={"Diego Marin"};

	//Inicializar array de punteros

	for (i = 0; i < 10; ++i) {

		pArrayCaracteres[i]=&caracteres[i];
	}

	//Puntero a funcion

	void saludar ()
	{
		printf("Hola\n");
	}

	int main (void)
	{
		void (*pFuncion) (void);

		pFuncion=saludar;
		pFuncion();

		/*
		 *  Hola
		 */

		return 0;
	}
	int* a;

	exit(0); // Termina el programa


	Dato d[2];//{{1,'Q'},{1,'C'}};
	Dato* p;

	p=d;

	for(int i; i<2; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &p[i].a);

		printf("Ingrese un char: ");
		fflush(stdin);
		scanf("%c", &p[i].c);
	}
	int j;

	for (j = 0; j < 2; j++) {

		//una forma
		printf("%d %c\n", (*(p+j)).a,(*(p+j)).c );
		//otra forma
		printf("%d %c\n", (p+j)->a, (p+j)->c);
	}

	return EXIT_SUCCESS;
}
