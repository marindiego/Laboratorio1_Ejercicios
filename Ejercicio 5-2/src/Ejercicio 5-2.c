/*
	 Ejercicio 5-2:

	Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:

	Cantidad de positivos y negativos.
	Sumatoria de los pares.
	El mayor de los impares.
	Listado de los números ingresados.
	Listado de los números pares.
	Listado de los números de las posiciones impares.
	Los números que se repiten
    Los positivos creciente y los negativos de manera decreciente

 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones_matematicas.h"
#include "biblioteca.h"
#define T 3

int main(void) {

	setbuf(stdout,NULL);

	int numerosIngresados[T];
	int acumuladorPares=0;
	int acumuladorImpares=0;
	int respuesta;
	int respuestaNegativos;

	//Cargo los numeros al programa, con validacion sin floats;
	CargarNumerosEnteros(numerosIngresados, T);

	//Muestro los positivos y Negativos ingresados
	MonstrarCantidadNegativosPositivos(numerosIngresados, T);

	//Sumatoria de los Pares ya validados y los muestro
	SumarParidad(numerosIngresados, T, &acumuladorPares, &acumuladorImpares);

	//Muestra el mayor de los impares y acumula numeros
	CalcularMayorImpares(numerosIngresados, T);

	//Muestro los numerosIngresados no secuenciales
	MostrarNumerosEnteros(numerosIngresados, T);

	//Muestro los pares y si no hay lo muestro
	MostrarNumerosEnterosPares(numerosIngresados, T);

	//Muestro los pares y si no hay lo muestro
	MostrarPosicionEnterosImpares(numerosIngresados, T);

	//Funcion de Burbujeo con Numeros Repetidos
	CargarNumerosRepetidos(numerosIngresados, T);

	//Funcion Burbujeo Creciente
	respuesta=OrdenarNumerosEnterosCreciente(numerosIngresados, T);

	if(respuesta>0){

		printf("\n Iteraciones : %d\n", respuesta);
	}

	MostrarNumerosEnteros(numerosIngresados, T);

	//Funcion burbujeo Decreciente Negativos
	respuestaNegativos=OrdenarNumerosEnterosDecrecienteNegativos(numerosIngresados, T);

	if(respuestaNegativos>0){

		printf("\n Iteraciones : %d\n", respuestaNegativos);
	}

	MostrarNumerosEnteros(numerosIngresados, T);




	return EXIT_SUCCESS;
}








