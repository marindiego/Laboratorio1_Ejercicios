/*
 ============================================================================
 Name        : Practica.c
 Author      : DIego
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include "utn_funciones.h"

#define t_pass 12
#define t_flyCodesPass 5
#define t_typePass 3

#define CARGADO 0
#define VACIO 1

#define ACTIVO 0
#define CANCELADO -1
#define DEMORADO 1

static int  pass_MaxFlyCode = 4;
static int  pass_MaxTypePassenger = 2;

typedef struct{

	char flycode[10]; //PK
	int statusFlight;
	char statusFlightChar[10];
}FlyCode;

typedef struct{

	int idTypePassenger;  //PK
	char descripcionPassenger [30];
}TypePassenger;

typedef struct{

	int id;  //PK
	char name[51];
	char lastName[51];
	float price;
	char flycode[10]; //FK
	int typePassenger; //FK
	int isEmpty;
}Passenger;

/** \brief Load 10 Passengers sequentially or if you want adding another Passenger will load in the array
 *
 * \param list Passenger*
 * \param int Passengers
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or (0) if ok
 *
 */
int pass_HardcodePassengers (Passenger* list, int Passengers);
/// @brief Load 10 TypePassengers sequentially or if you want adding another Passenger will load in the array
///
/// @param list
/// @param len_tpass
/// @return
int pass_HardcodeTypePassenger (TypePassenger* list, int TyPassengers);
/// @brief Load 10 flyCode sequentially or if you want adding another Passenger will load in the array
///
/// @param list
/// @param len_flypass
/// @return 0 ok -1 wrong
int pass_HardcodeFlyCodePassenger (FlyCode* list, int FlyCodes);

int printPassenger(Passenger* this,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass,int len_typePass,int* contadorFlyCode, int* contadorTypePassenger);
int printPassengers(Passenger* list,int len,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass,int len_typePass);
int pass_printfFlyCodes (FlyCode* listFlyCode, int len_flyCode);
int pass_prinfTypePassenger (TypePassenger* listTypePass, int len_typePass);
int imprimirArray (int*pArray, int limite);
int resizeArray (int**pArray, int* sizeActual);
int cargarEnBinario (char* path, int* listEnteros, int tam);

int main(void) {

	setbuf(stdout, NULL);


	int sizeEnteros= 10;
	int* listEnteros=(int*) malloc(sizeof(int)*5); //int array[5];

	*(listEnteros+0)=2;
	*(listEnteros+1)=4;
	*(listEnteros+2)=3;
	*(listEnteros+3)=6;
	*(listEnteros+4)=8;

	/* 2.

	 * Cuando se inicializa una varia con cualquier tipo de tipo se guarda la direccion de memoria de esa
	 * variable en segmento stack, pero si le agregamos un asterico* despues de declarar el tipo de dato y
	 * esa varibale  y le asignamos la funcion malloc o calloc, y a malloc la pasamos como argumento el tamaño
	 * en bytes de ese tipo de datos, nos va a devolver un puntero, pero no es un puntero que esta el stack,
	 * sino creado en el heap, esto quiere decir que podremos  no solo en tiempo de ejecucion poder redimensionar el tamaño
	 * de dicha varibale, sino que tambien "liberarla", (que ya no guarde ningun valor esa direccion de memoria),
	 * en el segmento heap podemos manipular cuando sea necesario no solo variables de manera dinamica, arrays de
	 * cualquier tipo de dato, arrayList, linkedList etc..., aparte C posee un "herramienta" muy poderosa para los
	 * programadores que son los "Punteros a funcion", esto evita por ejemplo evitar la redundancia de codigo
	 * tener modulos mas genericos, velocidad de procesamiento etc..., pero ojo, no son faciles de programar y
	 * pueden llevar a cometer muchos errores, es un arma de doble filo como quien dice, tambien podemos hacer un
	 * array de punteros a funciones, ya que el simple nombre de la funcion sin argumentos es un puntero, y como dijimos
	 * antes un punteros puede llegar a usarse de muchisimas formas posibles, tambien el solo nombre de un array es un
	 * puntero a donde empieza el vector, y podermos asignarlo a otro puntero con el mismo tipo de dato ect...
	 *
	 *
	 *
	 *
	 */

	imprimirArray(listEnteros, sizeEnteros);

	cargarEnBinario("data.bin", listEnteros, sizeEnteros);

	return EXIT_SUCCESS;
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

int cargarEnBinario (char* path, int* listEnteros, int tam)
{
	int retorno = -1;
	FILE *pFile;

	pFile = fopen(path, "wb");

	if (path!=NULL && listEnteros!=NULL) {

		fwrite(listEnteros,sizeof(int),tam,pFile);
	}

	return retorno;
}

int resizeArray (int**pArray, int* sizeActual){

	int retorno=-1;
	int *pArrayTemp=NULL;
	int contador=0;

	if (pArray!=NULL && sizeActual!=NULL ) {

		for (int i = 0; i < *sizeActual; i++) {

			if (**(pArray+i)%2==0) {

				contador++;

				pArrayTemp= (int*) realloc(*pArray,sizeof(int) * contador);
				if (pArrayTemp !=NULL ) {

					*pArray= pArrayTemp;
					pArrayTemp=NULL;
					retorno=0;
				}
			}
		}
	}
	return retorno;
}



int pass_HardcodePassengers (Passenger *list, int Passengers){

	int retorno=-1;
	int i;
	if(list!=NULL && Passengers >= 0){

		retorno=0;
		Passenger buffer[]=
						{{101,"Diego","Marin",6000,"EQ315",1,CARGADO},
						{102,"Carla","Suarez", 8000,"XL1371",3, CARGADO},
						{103,"German","Scarafilo",6000,"EQ315",1,CARGADO},
						{104,"Carlos","Ramirez",4000,"AR140",3,CARGADO},
						{105,"Pedro","Alvarez", 5500,"XL1371",1, CARGADO},
						{106,"Juan","Facundo",9800,"PS408",2,CARGADO},
						{107,"Fabian","Geopolis",5000,"PS408",1,CARGADO},
						{108,"David","Yiuta",4000,"CM158",3,CARGADO},
						{109,"Octavio","Lepez", 6000,"CM158",1,CARGADO},
						{110,"Gonzalo","Bastian",5000,"EQ315",2,CARGADO},
						{111,"Emiliano","Marin", 4000,"CM158",1,CARGADO},
						{112,"Wilker","Fari�ez",3000,"XL1371",2,CARGADO}};
				//Agregar Otro Passengers

		for (i = 0; i < Passengers; i++) {
			list[i]=buffer[i];
		}
	}

	return retorno;
}


int pass_HardcodeTypePassenger (TypePassenger* list, int TyPassengers)
{
	int retorno = -1;

	if(list!=NULL && TyPassengers >= 0){

		retorno = 0;
		TypePassenger buffer[3]=
						   {{1,"Infante"},
						    {2,"Ni�o"},
							{3,"Adulto"}};

		for (int i = 0; i < TyPassengers; i++) {
			list[i]=buffer[i];
		}

	}
	return retorno;
}

int pass_HardcodeFlyCodePassenger (FlyCode* list, int FlyCodes)
{
	int retorno = -1;

	if(list!=NULL && FlyCodes >= 0)
	{

		retorno = 0;
		FlyCode buffer[100]=
						{{"AR140",ACTIVO,"Activo"},
						{"CM158",ACTIVO,"Activo"},
						{"XL1371",CANCELADO,"Cancelado"},
						{"EQ315",CANCELADO,"Cancelado"},
						{"PS408",DEMORADO,"Demorado"}};

		for (int i = 0; i < FlyCodes; i++) {

			list[i] = buffer[i];
		}
	}
	return retorno;
}
int printPassenger(Passenger* this,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass,int len_typePass,int* contadorFlyCode, int* contadorTypePassenger){

	int retorno=-1; // No passanger load or any len < 0 or pointer NULL

	if (this!=NULL && this->isEmpty == CARGADO && listFlyCode !=NULL && listTypePass !=NULL && len_flyCode > 0 && len_typePass > 0 )
	{

		for (int i = 0; i < len_flyCode; i++)
		{
			if (!stricmp(this->flycode,listFlyCode[i].flycode))
			{
				for (int j = 0; j < len_typePass;j++)
				{
					if (this->typePassenger == listTypePass[j].idTypePassenger)
					{
						if (*contadorFlyCode <= pass_MaxFlyCode || *contadorTypePassenger <= pass_MaxTypePassenger) // Si todavia hay un elemento de las otras listas por mostrar
						{
							printf("| %3d  ||    %-10s     ||    %-9s     ||    %9.2f    ||        %-9s       ||         %-8d    |\t" ,this->id ,this->name, this->lastName,this->price,this->flycode,listTypePass[j].idTypePassenger);

							if ( *contadorFlyCode <= pass_MaxFlyCode)// Si todavia queda un elementro de la lista de Codigo por mostrar
							{

								printf("|    %-9s     ||    %-10s    |\t",listFlyCode[*contadorFlyCode].flycode,listFlyCode[*contadorFlyCode].statusFlightChar);
								(*contadorFlyCode)++; //Contandor apunta al siguiente elmento de la lista de Codigos


								if (*contadorTypePassenger > pass_MaxTypePassenger) { // Cuando no hay mas tipos de pasajeros por mostrar

									printf("\n -------------------------------------------------------------------------------------------------------------------     --------------------------------------\n");
								}
							}
							if (*contadorTypePassenger <= pass_MaxTypePassenger) { // Si todavia queda un elementro de la lista de tp por mostrar

								printf("|    %5d         ||    %-10s     |\n",listTypePass[*contadorTypePassenger].idTypePassenger,listTypePass[*contadorTypePassenger].descripcionPassenger);
								printf(" -------------------------------------------------------------------------------------------------------------------     --------------------------------------          ---------------------------------------\n");
								(*contadorTypePassenger)++; //Contandor apunta al siguiente elmento de la lista de Tipos de Pasajero
							}

							return 0; //(0) OK - Muestro por lo menos 2 elementos de diferentes lista
						}
						else{

							printf("| %-3d  ||    %-10s     ||    %-9s     ||    %9.2f    ||        %-9s       ||         %-8d    |\n" ,this->id ,this->name, this->lastName,this->price,this->flycode,this->typePassenger);
							printf(" -------------------------------------------------------------------------------------------------------------------\n");
							return 0;

						}
					}
				}
			}
		}
	}

	return retorno;
}
int pass_printfFlyCodes (FlyCode* listFlyCode, int len_flyCode){

	int retorno = -1;

	if (listFlyCode !=NULL && len_flyCode >= 0) {

		printf("\n"
			  "  ----------------------------------- \n"
			  " |Codigo de vuelo || Estado del vuelo|\n"
			  "  ----------------------------------- \n");

		for (int i = 0; i < len_flyCode; i++) {

			printf(" |%2d) %-11s || %-12s    |\n",i+1,listFlyCode[i].flycode,listFlyCode[i].statusFlightChar);
		}
		printf("  -----------------------------------\n");
	}
	return retorno;
}
int pass_prinfTypePassenger (TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1;

	if (listTypePass !=NULL && len_typePass >= 0) {

		printf("\n"
		   	   "  --------------------\n"
			   " |  Tipo de Pasajero  |\n"
			   "  --------------------\n");

		for (int i = 0; i < len_typePass; i++) {

			printf(" |%2d) %-10s      |\n",i+1,listTypePass[i].descripcionPassenger);
		}
		printf("  --------------------\n");
	}
	return retorno;
}

int printPassengers(Passenger* list, int length,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass){

	int retorno=-1; // No passanger load or any len < 0 or pointer NULL

	int contadorFlyCode = 0; // Variable de control para mostrar la lista de Codigos
	int contadorTypePass = 0; // Variable de control para mostrar la lista de Tipos de Pasajeros

	if (list!=NULL && length>0 && listFlyCode!=NULL && len_flyCode >0 && listTypePass !=NULL && len_typePass ) {

		pass_prinfTypePassenger(listTypePass, len_typePass);
		pass_printfFlyCodes(listFlyCode, len_flyCode);

		printf("\n"
			   " -------------------------------------------------------------------------------------------------------------------     --------------------------------------          --------------------------------------- \n"
			   "| Id   ||    Nombre         ||    Apellido      ||      Precio     ||     C�digo de vuelo    ||   IdTipoPasajero    |   | Codigo de vuelo  || Estado del vuelo |        | IdTipoPasajero   ||  Tipo de Pasajero | \n"
	           " -------------------------------------------------------------------------------------------------------------------     --------------------------------------          --------------------------------------- \n");

		for (int i = 0; i < length; i++) {

			printPassenger(&list[i],listFlyCode,len_flyCode,listTypePass,len_typePass,&contadorFlyCode,&contadorTypePass);
		}
		contadorFlyCode = 0; //Si muestro otra vez las pongo en 0
		contadorTypePass = 0; //Si muestro otra vez las pongo en 0

		retorno=0; //OK
	}
	return retorno;
}


