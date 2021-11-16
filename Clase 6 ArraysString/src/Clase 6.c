/*

 Marin Diego(1c)

 	 Ejercicio 6-1:

	 Disponemos de dos variables numéricas (a y b). Realizar un algoritmo que permita el intercambio de valores de dichas variables.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Biblioteca de strings

int main(void) {



	setbuf(stdout, NULL);

	//Cadena de Caracteres

	//"h" "o" "l" "a"

	//Inicializacion de cadenas de caracteres

	char saludo[10]="hola";
	char saludo[10]={'h','o','l','a','\0'};
	char saludo[]="hola";
	char menu [3][50]={"Archivo", "Nuevo", "Abrir"};

	char cad1[20];
	char cad2[20];

	//Funcion pedir una cadena de caracteres con scanf (no se usa) cuenta los espacios

	char cadena[11];
	fflush(stdout);
	//scanf("%s", cadena);
	scanf("%[^\n]", cadena);

	printf("Palabra Ingresada: %s", cadena);

	//Para pedir un vector con la Funcion gets (Lo recomendable)

	char vec[10];

	printf("Ingrese su nombre: ");
	gets(vec);

	//Para pedir con fgets

	fgets(cadena, sizeof(cadena), stdin); //LINUX



	// \0= lo pone automaticamente para cualquier
	//funcion que lee cadenas de texto para indicar que aqui
	//se acaba la cadena



	//FUNCIONES CON CADENAS DE CARACTERES

	//Devuelve menor a 0 si cad1 < cad2 || 0 si cad1 == cad2 || mayor a 0 si cad1> cad2
	//strcmp(cad1,cad2); // Sin Importar las Mayusculas con una i en el medio
	stricmp(cad1,cad2);

	//Example
	if(strcmp(cad1, cad2)==0){
		printf("Cadena 1 [%s] == Cadena 2[%s]", cad1, cad2);
	}
	else{
		if(strcmp(cad1,cad2)<0){
			printf("Cadena 1 [%s] < Cadena 2[%s]", cad1,cad2);
		}
		else{
			if(strcmp(cad1,cad2)>0){
				printf("Cadena 1 [%s] > Cadena 2[%s]", cad1,cad2);
			}
		}
	}
	//otro Example, sirve tambien como argumento de una cadena de si se pasa lo vuelve a pedir

	//Sirve para copiar una cadena de caracteres a otra desde el origen hasta destino
	strcpy(cad2, cad1);
	  /*Destino*//*Origen*/

	strncpy(cad2, cad1, sizeof(cad2));
	                 //ME LIMITA LA CANTIDAD DE LETRAS QUE SE INGRESAN
	printf("ARRAY ORIGINAL %s ARRAY COPIA: %s", cad2, cad1);

	//Cantidad de letras que tiene un array, cuentan los espacios.

	int cantidadLetras;

	cantidadLetras=strlen(cad1);//const char*
	                    //ARRAY

	cantidadLetras=strnlen(cad1,sizeof(cad1)); //el sizeof evita desbordamiento de memoria y no desvorde en caso de errores

	printf("Cantidad de letras %d:", cantidadLetras);

	//Convertir toda una cadena en mayuscuclas

	strupr(cadena);

	//Convertir toda una cadena en minusculas

	strlwr(cadena);

	//Concatenar cadena 2 a cadena 1

	strncat(cad1,cad2, sizeof(cad1));

	//Guardar en una variable destino cualquier parametro o texto que le paso, sirve para concatenar varios strings

	snprintf(cad1, sizeof(cad1), " Este mensaje se guarda en cad1 y sizeof me asegura que no se pase, puedo agregarle cualquier %");

	//Funciones a Investigar

	tolower(); // Transforma a minusculas
	isdigit(); // me duevuelve 1 si es un digito !isdigit(cadena[i]) = si es distinto a un numero
	isalpha(); // me devuelve  un numero mayor a cero si es un caracter !isdigit(cadena[i]) =  si es distinto a un caracter
	isspace(); // Si es un espacio


	return EXIT_SUCCESS;
}
