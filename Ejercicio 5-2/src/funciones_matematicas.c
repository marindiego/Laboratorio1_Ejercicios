/*
 * funciones_matematicas.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include "funciones_matematicas.h"
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
				system("cls");

			}else{

				retorno=1;
			}
		}
		numeroIngresado=ValidarRangoEntero(numeroIngresado, -1000, 1000);
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
				system("cls");
			}else{

				retorno=1;
			}
		}
		numeroIngresado=ValidarRangoEntero(numeroIngresado, -1000, 1000);
	}

	return numeroIngresado;
}
int ValidarRangoEntero (int numeroEnteroIngresado, int minimo, int maximo){

	while(numeroEnteroIngresado<minimo || numeroEnteroIngresado> maximo){

		printf("Reingrese un numero entre -1000 y 1000 xfa: ");
		scanf("%d", &numeroEnteroIngresado);
	}

	return numeroEnteroIngresado;
}

void CargarNumerosEnteros (int listaEnteros[], int tam){

	int i;

	if(listaEnteros!=NULL){

		for(i=0; i<tam; i++){

			listaEnteros[i]=IngresarNumeroEntero("Ingrese un entero entre -1000 y 1000: ", "Reingrese un entero entre -1000 y 1000: ");
		}
	}

}

int VerificarSigno (int numeroIngresado){

	int signo;//1 positivo 0 negativo


	if(numeroIngresado>0){

		signo=1;

	}else{

		signo=0;
	}

	return signo;

}
void MonstrarCantidadNegativosPositivos (int listaEnteros[], int tam){


	int contadorPositivos=0, contadorNegativos=0, i, numeroIngresado;

	for(i=0; i<tam; i++){

		numeroIngresado=listaEnteros[i];
		//1 Positivo 0 Negativo
		if(VerificarSigno(numeroIngresado)==1){

			contadorPositivos++;
		}
		else{

			contadorNegativos++;
		}
	}

	printf("Hay %d positivos: \n",contadorPositivos);
	printf("Hay %d negativos: \n",contadorNegativos);

}
int VereficarParidad (int numeroIngresado){

	int paridad;// 1 Par  0 Impar

	if( numeroIngresado%2==0){

		paridad=1;
	}
	else{
		paridad=0;
	}

	return paridad;
}

void SumarParidad (int listaEnteros[], int tam, int *pAcumuladorPares, int *pAcumuladorImpares){

	int numeroIngresado, i;

	if(pAcumuladorPares!=NULL && pAcumuladorImpares!=NULL){

		for(i=0; i<tam; i++){

			numeroIngresado=listaEnteros[i];

			if(VereficarParidad(numeroIngresado)==1){

				*pAcumuladorPares+=numeroIngresado;
			}
			else{

				*pAcumuladorImpares+=numeroIngresado;
			}
		}
	}

	if(*pAcumuladorPares!=0){

		printf("La suma de los pares es: %d\n", *pAcumuladorPares );
	}
	else{

		printf("No hay pares Ingresado \n");
	}
	if(*pAcumuladorImpares!=0){

		printf("La suma de los impares es: %d\n", *pAcumuladorImpares );
	}
	else{
		printf("No hay impares Ingresado \n");
	}


}

void CalcularMayorImpares (int listaEnteros [], int tam){

	int i;
	int mayor=0;
	int numeroIngresado;
	int FlagMayorImpar=0;

	for(i=0; i<tam; i++){

		numeroIngresado=listaEnteros[i];

		if(VereficarParidad(numeroIngresado)==0){// 0 Impar 1 par

			if(FlagMayorImpar==0 || numeroIngresado>mayor){ //Despues de la primer iteracion Comparo

				FlagMayorImpar=1;
				mayor=listaEnteros[i];
			}
		}
	}
	if(mayor!=0){

		printf("El mayor de los impares es: %d \n", mayor);
	}
	else{

		printf("No se encontro ningun Impar \n");
	}
}


void MostrarNumerosEnterosPares (int listaEnteros[], int tam){

	int i, numeroIngresado;

	for(i=0; i<tam; i++){

		numeroIngresado=listaEnteros[i];
		if(VereficarParidad(numeroIngresado)==1){

			printf("Hay un numero par en la posicion %d y es: %d\n", i+1, numeroIngresado);
		}
	}
}
void MostrarPosicionEnterosImpares (int listadoEnteros[], int tam){

	int i, numeroIngresado;

	if(listadoEnteros!=NULL){

		for(i=0; i<tam; i++){

			numeroIngresado=listadoEnteros[i];

			if(VereficarParidad(numeroIngresado)==0){

				printf("Hay un numero impar en la posicion %d\n", i+1);
			}
		}
	}
}
void CargarNumerosRepetidos (int listaValores[], int tam){

	int i,j, contadorRepetidos=0;

	if(listaValores!=NULL){

		for(i=0;i<tam-1; i++){

			for(j=i+1; j<tam; j++){

				if(listaValores[i]==listaValores[j]){

					contadorRepetidos++;
				}
			}
		}
		printf("Se repiten %d numeros \n", contadorRepetidos);
	}
}
int OrdenarNumerosEnterosCreciente (int listaEnteros[], int tam){

		int flagSwap;
		int i;
		int contador=0;
		int retorno=0;
		int buffer;
		int nuevoLimite;

		if(listaEnteros!=NULL && tam>=0){

			nuevoLimite=tam-1;
			do{
				flagSwap=0;
				for(i=0;i<nuevoLimite; i++){

					contador++;
					if(listaEnteros[i]>listaEnteros[i+1]){

						flagSwap=1;
						buffer=listaEnteros[i];
						listaEnteros[i]=listaEnteros[i+1];
						listaEnteros[i+1]=buffer;
					}
					nuevoLimite--;
				}
			}while(flagSwap);
			retorno=contador;
		}

		return retorno;
}

void MostrarNumerosEnteros (int listaEnteros[], int tam){


	int i;
	if(listaEnteros!=NULL && tam>=0){

		for(i=0; i<tam; i++){

			printf("[DEBUG] Indice: %d - Valor %d\n", i, listaEnteros[i]);
		}
	}

}
int OrdenarNumerosEnterosDecrecienteNegativos (int listaEnteros[], int tam){

		int flagSwap;
		int i;
		int contador=0;
		int retorno=0;
		int buffer;
		int nuevoLimite;

		if(listaEnteros!=NULL && tam>=0){

			nuevoLimite=tam-1;
			do{
				flagSwap=0;
				for(i=0;i<nuevoLimite; i++){

					contador++;
					if( listaEnteros[i]<0 && listaEnteros[i]<listaEnteros[i+1]){

						flagSwap=1;
						buffer=listaEnteros[i];
						listaEnteros[i]=listaEnteros[i+1];
						listaEnteros[i+1]=buffer;
					}
					nuevoLimite--;
				}
			}while(flagSwap);
			retorno=contador;
		}

		return retorno;
}



