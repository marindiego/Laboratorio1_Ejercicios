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
#include "funciones_matematicas.h"
#include "biblioteca.h"
#define T 5

 void CargarVectorEntero ( int listaValores[], int tam);
 void MostrarVectorEntero (int listaValores[], int tam);
 int BuscarUnNumero (int listaVectores[], int tam, int valorBusqueda );

int main(void) {

	setbuf(stdout,NULL);

	int mayor;
	int v[T];  //Cantidad de elementos que va a tener el vector

	v[0]=20;
	v[1]=40;
	v[2]=60;

	printf("%d -%d -%d", v[0], v[1], v[2]);
	// Normal
	    /*for(i=0; i<tam; i++){

	    		printf("Ingrese un numero: ");
	    		scanf("%d", &listaValores[i]);
	    	}
	    }*/

	//COMO USAMOS UN VECTOR


	int i;

	// Secuencial

    for(i=0; i<T; i++){

        printf("Ingrese el valor del vector %d:", i+1);
        scanf("%d",&v[i]);
    }

    //Muestro los Valores de cada indice

    for(i=0;i<T; i++){

    	printf("el valor del vector %d es %d\n", i+1, v[i]);
    }


    //Calcular un maximo o un minimo

    int mayor=v[0];

    if(v[i]>mayor/* v[i]<menor*/ ){

    	mayor=v[i];
    }


    //Cargo
    CargarVectorEntero(v, T );

    //Muestro
    MostrarVectorEntero(v, T);

    int acumulador=0;

    for(i=0; i<T; i++){

    	if(v[i]!=0){

    		acumulador=v[i];
    	}
    }
    printf("Acumulo %d", acumulador);

	return EXIT_SUCCESS;
}



    // Carga No secuencial
    void CargarVectorEntero ( int listaValores[], int tam){

   	int  numero,i;// varibale de control

    //Siempre inicializamos un Vector con un valor en cada posicion en una carga No secuencial
    for(i=0; i<tam; i++){

    	listaValores[i]=0;//operador logico
    }


   	char seguir;
   	//Cargo cada Vector en el sistema
   	do{

   		numero=IngresarNumeroEntero("Ingrese un numero entero", "Error, Ingrese un numero entero");
   		i=IngresarNumeroEntero("Donde quiere guardarlo 1-5 ?","Error, ingrese un numero entero");
                                             //0-5
   		listaValores[i-1]=numero;

   		printf("Desea Ingresar otro Numero?");
   		fflush(stdin);
   		scanf("%c", &seguir);

   	}while(seguir=='s');

    }

    //Funcion de  mostrar Vectores
    void MostrarVectorEntero (int listaValores[], int tam){

        	int i;
        	for(i=0;i<tam; i++){

        		printf("%d\n", listaValores[i]);
        	}

    }
    //Funcion de mostrar un numero
    int BuscarUnNumero (int listaVectores[], int tam, int valorBusqueda ){

    	int i,indiceEncontrado;

    	for(i=0; i<tam; i++){

    		if(listaVectores[i]==valorBusqueda){

    			indiceEncontrado=i;
    			break;
    		}

    	}

    	return indiceEncontrado;
    }
