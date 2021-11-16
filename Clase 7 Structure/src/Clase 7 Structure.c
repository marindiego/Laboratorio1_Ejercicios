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
#include <string.h>
#include "utn_funciones.h"

#define TAM_MAX 5  // maxima cantidad de posiciones que puede tener un array
#define CARACTERES_MAX 50 //maxima longitud que puede recibir un array de caracteres

typedef struct{  //Engloba todo un conjunto de variables

	int nota;  //campo o atributos
	int edad;
	char nombre[50];

}eAlumno;  //Nombre por la cual la llamaremos en el main

void MostrarUnAlumno (eAlumno unAlumno);
void CargarListaAlumnos (eAlumno lista[], int tam);
void MostrarListaAlumnos (eAlumno lista[], int tam);
int OrdenarListaAlumnosPorNombre (eAlumno lista[], int tam);

int main(void) {

	setbuf(stdout, NULL);

	//eAlumno unAlumno; //Identificador
 //Tipo de variable

	eAlumno unAlumno=  //Vector MultiTipo
	{6,      25,        "maria"};
//   |       |             |
//1er Campo, 2do Campo, 3er campo

	eAlumno otroAlumno;

	//unAlumno.varible
	        //operador '.' me permite acceder
	       //al campo de la estrucutra y acceder a
	       //una variable dentro de ese campo

	unAlumno.edad=IngresarNumeroEntero("Edad: ", "Error", 0,10);
	unAlumno.nota=IngresarNumeroEntero("Nota: ", "Error", 0,10);
	getString(unAlumno.nombre,"Nombre: ", sizeof(unAlumno.nombre))	;


	//Ahora con varios alumnos

	eAlumno listaAlumnos[TAM_MAX]=
			{{6,25,"Maria"},{5,10,"Diego"},{7,6,"German"},{6,9,"Carlos"},{20,20,"jordeany"}};

	//Cargar Vector en una estructuras

	CargarListaAlumnos(listaAlumnos, TAM_MAX);

	//Mostrar vector en una estructura

	MostrarListaAlumnos(listaAlumnos, TAM_MAX);



	otroAlumno=unAlumno;// Para asignar una estrucutra en otra con los mismo campos

	if(otroAlumno.edad==unAlumno.edad &&
		otroAlumno.nota && unAlumno.nota &&
		strcmp(otroAlumno.nombre,unAlumno.nombre )==0 )
	{

		printf("Si son iguales");
	}
	else
	{
		printf("No son iguales");
	}

	MostrarUnAlumno(unAlumno);// Maria 25 6*/


	//Las estructuras trabajan por valor

	//printf("%lld", sizeof(eAlumno)); //tam max
	//redondea a multiplos de 4 o 8

	return EXIT_SUCCESS;
}
void CargarListaAlumnos (eAlumno lista[], int tam){

	for(int i=0; i<tam ; i++){

		lista[i].edad=IngresarNumeroEntero("Edad: ", "Error", 0,10);
		lista[i].nota=IngresarNumeroEntero("Nota: ", "Error", 0,10);
		getString(lista[i].nombre,"Nombre: ", sizeof(lista[i].nombre));
	}

}

void MostrarUnAlumno (eAlumno unAlumno){

	printf("%4s, %15d, %4d \n", unAlumno.nombre, unAlumno.edad, unAlumno.nota);

}

void MostrarListaAlumnos (eAlumno lista[], int tam){

	for(int i=0; i<TAM_MAX; i++){

		MostrarUnAlumno(lista[i]);
	}
}
int OrdenarListaAlumnosPorNombre (eAlumno lista[], int tam){

	int flagSwap;
	int i;
	int contador=0;
	int retorno=0;
	eAlumno auxString;

	if(lista!=NULL && tam>=0){

		do{
			flagSwap=0;
			for(i=0;i<tam-1; i++){

				contador++;
				if(strcmp(lista[i].nombre, lista[i+1].nombre)>0){

					flagSwap=1;
					auxString=lista[i];
					lista[i]=lista[i+1];
					lista[i+1]=auxString;
				}
			}

		}while(flagSwap);

		retorno=contador;
	}
	return retorno;

}

// Vectores Paraleros
	//Ejemplo

	int nota[TAM_MAX]=
	{8,4,7,4,10};
	int edad[TAM_MAX]=
	{22,36,44,27,19};
	char nombre[TAM_MAX][CARACTERES_MAX]=
	{"diego","maria", "german", "carlos", "Ana"};


void PedirDatosAlumnos (int nota[], int edad[], char nombre[][50], int tam); // Pedir datos con Vectores Paraleros
void MostrarDatosAlumnos (int nota[], int edad[], char nombre[][50], int tam);
int OrdenarDatosAlumnosEdad (int nota[], int edad[], char nombre[][50], int tam);
int OrdenarDatosAlumnosNombre (int nota[], int edad[], char nombre[][50], int tam);

void PedirDatosAlumnos (int nota[], int edad[], char nombre[][50], int tam){

	for(int i=0;i < tam ; i++){

		nota[i]=IngresarNumeroEntero("Nota: ", "ERROR \n", 0, 10);
		edad[i]= IngresarNumeroEntero("Edad: ", "ERROR \n ", 0,20);
		getString(nombre[i], "Nombre: ", 50 );
	}

}
void MostrarDatosAlumnos (int nota[], int edad[], char nombre[][50], int tam){


	printf("Edad  Nombre  Nota \n");
	for(int i=0; i < tam; i++){

		printf("%4d %-20s %4d \n", edad[i] , nombre[i] , nota[i]);
            //Cantida de espacios para mover
	}
}

int OrdenarDatosAlumnosEdad (int nota[], int edad[], char nombre[][50], int tam){

	int flagSwap;
	int i;
	int contador=0;
	int retorno=0;
	int buffer;
	char auxString[50];

	if(edad!=NULL && nota!=NULL && nombre!=NULL && tam>=0){

		do{
			flagSwap=0;
			for(i=0;i<tam-1; i++){

				contador++;
				if(edad[i]>edad[i+1]){

					//Edad
					flagSwap=1;

					buffer=edad[i];
					edad[i]=edad[i+1];
					edad[i+1]=buffer;

					//Nota
					buffer=nota[i];
					nota[i]=nota[i+1];
					nota[i+1]=buffer;

					//Nombre
					strcpy(auxString, nombre[i]);
					strcpy(nombre[i],nombre[i+1]);
					strcpy(nombre[i+1], auxString);
				}
			}

		}while(flagSwap);

		retorno=contador;
	}
	return retorno;
}

int OrdenarDatosAlumnosNombre (int nota[], int edad[], char nombre[][50], int tam){

	int flagSwap;
		int i;
		int contador=0;
		int retorno=0;
		int buffer;
		char auxString[50];

		if(edad!=NULL && nota!=NULL && nombre!=NULL && tam>=0){

			do{
				flagSwap=0;
				for(i=0;i<tam-1; i++){

					contador++;
					if(strcmp(nombre[i], nombre[i+1])<0){

						//Edad
						flagSwap=1;

						buffer=edad[i];
						edad[i]=edad[i+1];
						edad[i+1]=buffer;

						//Nota
						buffer=nota[i];
						nota[i]=nota[i+1];
						nota[i+1]=buffer;

						//Nombre
						strcpy(auxString, nombre[i]);
						strcpy(nombre[i],nombre[i+1]);
						strcpy(nombre[i+1], auxString);
					}
				}

			}while(flagSwap);

			retorno=contador;
		}
		return retorno;
}
