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
    int id;
    char descripcion[10];
}eProducto;

int initArray (int*pArray, int limite, int valor){

	int retorno=-1;
	int i;
	if (pArray!=NULL && limite>0) {

		retorno=0;
		for (i = 0; i < limite; i++) {
			*(pArray+i)= valor;
		}
	}
	return retorno;
}
int imprimirArray (int*pArray, int limite){

	int retorno=-1;
	int i;
	if (pArray!=NULL && limite>0) {

		retorno=0;
		for (i = 0; i < limite; i++) {
			printf("%d\n",*(pArray+i));
		}
	}
	return retorno;
}
int resizeArray (int**pArray, int* sizeActual, int sizeNuevo){

	int retorno=-1;
	int *pArrayTemp=NULL;

	if (pArray!=NULL && sizeActual!=NULL && sizeNuevo>=0) {

		pArrayTemp= (int*) realloc(*pArray,sizeof(int) * sizeNuevo);
		if (pArrayTemp !=NULL ) {

			*sizeActual=sizeNuevo;
			*pArray= pArrayTemp;
			pArrayTemp=NULL;
			retorno=0;
		}
	}
	return retorno;
}


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
int main(void) {

	setbuf(stdout,NULL);

	int* pArrayEdades=NULL;
	int i;
	int *aux;

	pArrayEdades=(int*) malloc(sizeof(int)*5); //int array[5]

	for (i = 0; i < 5; i++) {

		printf("Numero: ");
		scanf("%d", pArrayEdades+i);
	}

	printf("Muestro los primeros 5\n");
	for (i = 0; i < 5; i++) {

		printf("%d\n", *(pArrayEdades+i) );
	}

	aux= (int*) realloc(pArrayEdades, sizeof(int)*(5*2));// int array[10]

	if(aux!=NULL){


		pArrayEdades=aux;

		for (i = 5; i < 5*2; i++) {

			printf("Numero: ");
			scanf("%d", pArrayEdades+i);
		}
		printf("Muestro los 10 cargados\n");

		for (i = 0; i < 5*2; i++) {

			printf("%d\n", *(pArrayEdades+i) );
		}
	}

	int sizeArrayEdades= 10;

	pArrayEdades=(int*) malloc(sizeof(int)*sizeArrayEdades);

	if (pArrayEdades!=NULL)
	{

		if (!initArray(pArrayEdades, sizeArrayEdades, 0))
		{
			printf("INIT OK\n");
			imprimirArray(pArrayEdades, sizeArrayEdades);
		}
		if(!resizeArray(&pArrayEdades, &sizeArrayEdades, 20)){

			printf("RESIZE OK\n");
			initArray(pArrayEdades, sizeArrayEdades, 0);
			imprimirArray(pArrayEdades, sizeArrayEdades);
		}
	}

	free(pArrayEdades);

	eProducto* pProducto;

	pProducto = CargarDivisionParametros(1, "Iphone");



	if (pProducto != NULL ) {

		printf("Dir: %p -- Dir: %p\n", pProducto, &pProducto);

		printf("%d, %s\n", pProducto->id, pProducto->descripcion);
		printf("%d, %s\n", pProducto->id, pProducto->descripcion);
		printf("%d, %s\n", pProducto->id, pProducto->descripcion);
		printf("%d, %s\n", pProducto->id, pProducto->descripcion);
	}


	/*
	 *
	 * Dir: 0000000000152490 -- Dir: 000000000062fe18
		1, Iphone
		1, Iphone
		1, I	phone
		1, Iphone
	    *
	    */
	/*
	 * ----------------------------------------------------------------------------
	 * */



	return EXIT_SUCCESS;
}
