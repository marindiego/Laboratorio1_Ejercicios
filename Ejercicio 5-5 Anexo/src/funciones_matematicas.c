/*
 * funciones_matematicas.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include "funciones_matematicas.h"
#include "biblioteca.h"
#include <time.h>
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
int IngresarNumeroEntero (char* mensaje, char *mensajeError, int minimo, int maximo){



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
		numeroIngresado=ValidarRangoEntero(numeroIngresado, minimo, maximo, mensaje, mensajeError);
	}

	return numeroIngresado;

}
float IngresarNumeroFloat (char* mensaje, char *mensajeError, int minimo, int maximo){

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
		numeroIngresado=ValidarRangoEntero(numeroIngresado,  minimo,  maximo, mensaje,  mensajeError);
	}

	return numeroIngresado;
}

void InicializarVectorEnteroExcluyente (int listadoEnteros [], int tam, int  numeroExcluyente){

	int i;

	if(listadoEnteros!=NULL){

		for(i=0; i<tam; i++){

			listadoEnteros[i]=numeroExcluyente;
		}
	}
}

int ValidarRangoEntero (int numeroEnteroIngresado, int minimo, int maximo, char mensaje[], char mensajeError[]){

	while(numeroEnteroIngresado<minimo || numeroEnteroIngresado> maximo){

		printf("%s", mensajeError);
		scanf("%d", &numeroEnteroIngresado);
	}

	return numeroEnteroIngresado;
}

void CargarNumerosEnteros (int listaEnteros[], int tam, char mensaje[], char mensajeError[], int minimo, int maximo){

	int i;

	if(listaEnteros!=NULL){

		for(i=0; i<tam; i++){

			listaEnteros[i]=IngresarNumeroEntero(mensaje, mensajeError, minimo, maximo);
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
		if(VereficarParidad(numeroIngresado)==1 ){

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
void ContarNumerosRepetidos (int listaValores[], int tam){

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

void MostrarNumerosEnteros (int listaEnteros[], int tam, int numeroExcluyenteArray){

	int i;
	if(listaEnteros!=NULL ){

		for(i=0; i<tam; i++){

			if(listaEnteros[i]!=numeroExcluyenteArray){

				printf("[DEBUG] Indice: %d - Valor %d\n", i+1, listaEnteros[i]);
			}
		}
		MostrarEnteroAleatorio(listaEnteros, tam);
	}
}

void MostrarEnteroAleatorio (int listaEnteros[], int tam){

	srand(time(NULL));

	int indiceAleatorio, numeroArrayAleatorio;

	indiceAleatorio=rand()% tam;
	numeroArrayAleatorio=listaEnteros[indiceAleatorio];

	printf("\n[DEBUG] IndiceAleatorio: %d - Valor %d\n", indiceAleatorio+1, numeroArrayAleatorio);
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

void CargarEnterosNoSecuencial (int listaEnteros[], int tam, char mensaje[], char mensajeError[],  int minimo, int maximo){

	int numeroIngresado,i;
	char seguir;

	if(listaEnteros!=NULL){

		InicializarVectorEnteroExcluyente(listaEnteros, tam, 0);

		do{

			numeroIngresado=IngresarNumeroEntero(mensaje, mensajeError, minimo, maximo);
			i=IngresarNumeroEntero(" En que posicion quieres guadarlo ?: ", "Reingrese un posicion valida", 0, tam);

			listaEnteros[i-1]=numeroIngresado;

			printf("Desea Ingresar otro numero  s/n ?:  ");
			fflush(stdin);
			scanf("%c", &seguir);

		}while(seguir=='s');
	}
}

void PromedearVectorEntero (float *pPromedioPositivos, float *pPromedioNegativos, int listaEnteros[], int tam){

	float acumuladorPositivos=0, acumuladorNegativos=0;
	int numeroIngresado;

	*pPromedioPositivos=0;
	*pPromedioPositivos=0;

	if(listaEnteros!=NULL){

		for(int i=0; i<tam; i++){



			numeroIngresado=listaEnteros[i];

			if(VerificarSigno(numeroIngresado)==1){

				acumuladorPositivos+=numeroIngresado;
			}
			else{
				acumuladorNegativos+=numeroIngresado;
			}
		}
	}
	if(acumuladorPositivos!=0){

		*pPromedioPositivos=acumuladorPositivos/tam;
		printf("\n(---||  Promedio Positivos  ||---)[%.2f] \n", *pPromedioPositivos );
	}
	else{

		if(acumuladorNegativos!=0){

			*pPromedioNegativos=acumuladorNegativos/tam;
			printf("\n(---||  Promedio Negativos  ||---)[%.2f] \n", *pPromedioNegativos );
		}
	}

}

void SumarEnterosNegativos (int listaEnteros[], int tam, float *pSumaNegativos){

		int i, numeroIngresado;

		InicializarVectorEnteroExcluyente(listaEnteros, tam, 0);

		for(i=0; i<tam; i++){

			numeroIngresado=listaEnteros[i];

			if(VereficarParidad(numeroIngresado)==0){

				*pSumaNegativos+=listaEnteros[i];
			}
		}

		printf("\n(--- Suma Negativos---)[%.2f] \n", *pSumaNegativos);
	}

void MenuEnteros (int listaEnteros[], int tam, char mensaje[], char mensajeError[], int minimo, int maximo, int numeroExcluyenteArray){

	// 1 CargaSecuencial 0 Carga No secuencial

	int opcion, tipoArray;

		do{
			printf("Menu de Arrays: \n 1-Inicializar Array \n 2-Cargar Array \n 3-Mostrar Array\n 4-Calcular Promedio Array \n 5-Ordenar Array \n 6-Salir del Menu \n");

			printf("\n Ingrese una opcion 1-2-3-4-5-6: ");
			scanf("%d", &opcion);

			switch(opcion){

			case 1:
				printf("Ud. ha seleccionado lo opción 1-Inicializar \n");
				InicializarVectorEnteroExcluyente(listaEnteros, tam, 0);
				printf("Inicializacion Completa!!!");
				system("pause");
				system("cls");
				break;

			case 2:
				printf("“Ud. ha seleccionado lo opción 2-Cargar \n");
				tipoArray=IngresarNumeroEntero(" 1 = Carga Secuencial 2 = Carga Aleatoria: ", "Reingrese entre en l y el 0 xfa: ", 0, 3);
				if(tipoArray==1){

					CargarNumerosEnteros(listaEnteros, tam, mensaje, mensajeError, minimo, maximo);
					printf("Carga completa!!!");
					system("pause");
					system("cls");
				}
				else{

					CargarEnterosNoSecuencial(listaEnteros, tam, mensaje, mensajeError, minimo, maximo);
					printf("Carga completa!!!");
					system("pause");
					system("cls");
				}
				break;

			case 3:
				printf("“Ud. ha seleccionado lo opción 3-Mostrar \n");
				MostrarNumerosEnteros(listaEnteros, tam, numeroExcluyenteArray);
				printf("Mostrar Completado!!!");
				system("pause");
				system("cls");
				break;

			case 4:
				printf("“Ud. ha seleccionado lo opción 4-Calcular Promedio \n");
				system("pause");
				system("cls");
				break;

			case 5:
				printf("“Ud. ha seleccionado lo opción 5-Ordenar \n");
				system("pause");
				system("cls");
				break;

			case 6:
				printf("(---| ** Gracias por Operar ** |---)");
				system("pause");
				system("cls");
				break;
			}


		}while(opcion!=6);

	}

