/*
 * funciones_matematicas.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <windows.h>


float Sumar (float a, float b){

	float resultado;

	resultado=a+b;

	return resultado;
}

float Restar (float operando1, float operando2){

	float resultado;

	resultado=operando1-operando2;

	return resultado;

}
int Dividir (float operando1, float operando2, float* pResultado){


	float resultado;
	int error=1;

	if(pResultado!=NULL && operando2!=0){

	resultado=operando1/operando2;

	(*pResultado)=resultado;
	}else{

		error=0;
	}
	return error;
}
float Multiplicar (float operando1, float operando2){

	float resultado;

	resultado=operando1*operando2;

	return resultado;

}

int CalcularFactorial (int numeroIngresado){

	int factorial;

	if(numeroIngresado==1){

		return 1;
	}
	else{
		factorial=numeroIngresado* CalcularFactorial (numeroIngresado-1);
	}

	return factorial;

}
int ValidarEntero (float numeroIngresado){

	float resultado;
	int enteroOflotante=1;

	resultado=numeroIngresado-(int)numeroIngresado;

	if(resultado!=0){

		enteroOflotante=0;
	}

	return enteroOflotante;
}
int IngresarNumeroEntero (char* mensaje, char *mensajeError){



	float numeroIngresado;
	float resultado;
	int retorno=0;

	if(mensaje!=NULL && mensajeError!=NULL){

		printf("%s", mensaje );
		scanf("%f", &numeroIngresado);

		resultado=numeroIngresado-(int)numeroIngresado;

		while(retorno==0){

			if(resultado!=0){

				printf("%s", mensajeError);
				scanf("%f", &numeroIngresado);
				resultado=numeroIngresado-(int)numeroIngresado;
			}else{

				retorno=1;
			}
		}

	}

	return numeroIngresado;

}
float IngresarNumeroFloat (char* mensaje, char *mensajeError){

	float numeroIngresado;
	float resultado;
	int retorno=0;

	if(mensaje!=NULL && mensajeError!=NULL){

		printf("%s", mensaje );
		scanf("%f", &numeroIngresado);

		resultado=numeroIngresado-(int)numeroIngresado;

		while(retorno==0){

			if(resultado==0){

				printf("%s", mensajeError);
				scanf("%f", &numeroIngresado);
				resultado=numeroIngresado-(int)numeroIngresado;
			}else{

				retorno=1;
			}
		}
	}

	return numeroIngresado;
}
void CargarNumeros (int listaEnteros[], int tam ){

	int i;

	for(i=0; i<tam ;i++){

		listaEnteros[i]=IngresarNumeroEntero("Ingrese un numero Entero entre -1000 y 1000", "Reintente un entero");

	}

}
int ValidarRango (int numeroIngresado, int minimo, int maximo){


	while(numeroIngresado<minimo || numeroIngresado>maximo){

		printf("Reingrese un numero entre -1000 y 1000: ");
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;

}
