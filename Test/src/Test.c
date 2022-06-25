/*
 ============================================================================
 Name        : Test.c
 Author      : DIego
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char descripcion[10];
}eProducto;

eProducto* CargarProducto ();
eProducto* CargarProducto ()
{
    eProducto* pProducto = NULL;

    if ((pProducto = (eProducto*) malloc(sizeof(eProducto)))!=NULL) {

    	return pProducto;
	}

    return pProducto;
}

eProducto* CargarDivisionParametros (int id, char* descripcion);
eProducto* CargarDivisionParametros (int id, char* descripcion)
{
	eProducto* pProducto = CargarProducto();

	if ((pProducto = (eProducto*) malloc(sizeof(eProducto)))!=NULL) {

		pProducto->id = id;
		strcpy(pProducto->descripcion,descripcion);
	}

	return pProducto;
}
int main()
{

	setbuf(stdout,NULL);

  /* eProducto* pProducto;

   pProducto = CargarDivisionParametros(1, "Iphone");



   if (pProducto != NULL ) {

	   printf("Dir: %p -- Dir: %p\n", pProducto, &pProducto);

	   printf("%d, %s\n", pProducto->id, pProducto->descripcion);
	   printf("%d, %s\n", pProducto->id, pProducto->descripcion);
	   printf("%d, %s\n", pProducto->id, pProducto->descripcion);
	   printf("%d, %s\n", pProducto->id, pProducto->descripcion);
   }
*/

   /*
    *
    * Dir: 0000000000152490 -- Dir: 000000000062fe18
	1, Iphone
	1, Iphone
	1, Iphone
	1, Iphone
    *
    */
/*
 * ----------------------------------------------------------------------------
 * */



 /*  int* pVector;
   int* aux;

   pVector = (int*) malloc(sizeof(int)*5); // int pVector[5];

	for (int i = 0; i < 5; i++) {

		printf("Numero: ");
		scanf("%d",pVector+i);
	}

	for (int i = 0; i < 5; i++) {

		printf("%d\n",*(pVector+i));
	}


	aux = (int*) realloc(pVector,sizeof(int)*5+5);// int pVector[10];

	if (aux!=NULL) {

		printf("Ahora tengo espacio para 5 mas\n");

		for (int i = 5; i < 10; i++) {

			printf("Nuevos Numeros: ");
			scanf("%d",pVector+i);
		}
		printf("Ahora muestro 10\n");
		for (int i = 0; i < 10 ; i++) {

			printf("%d\n",*(pVector+i));
		}
	}

	free(pVector);

	*/
	/*
	 *
	 *
	 * Dir: 0000000000162490 -- Dir: 000000000062fdf8
1, Iphone
1, Iphone
1, Iphone
1, Iphone
Numero: 1
Numero: 2
Numero: 3
Numero: 4
Numero: 5
1
2
3
4
5
Ahora tengo espacio para 5 mas
Nuevos Numeros: 6
Nuevos Numeros: 7
Nuevos Numeros: 8
Nuevos Numeros: 9
Nuevos Numeros: 10
Ahora muestro 10
1
2
3
4
5
6
7
8
9
10
	 */
	int* pEntero;
	int vector[3] = {}; //PILA

	pEntero = calloc(sizeof(int)*3); //MONTON---> REDIMENSIONAR

	if (pEntero!=NULL) {

		for (int i = 0; i < 3; i++) {
			printf("%c");
		}
	}

    return 0;
}


