/*
 * Passenger.c
 *
 *  Created on: 10 nov. 2021
 *      Author: Usuario
 */

#include "ArrayPassenger.h"

static int idPassengers = 101;

static int pass__AumentarId (){

	return idPassengers++;
}

static const int  pass_MaxTypePassenger = 2; //3
static const int pass_MaxLenNameLasName = 15;
static const int  pass_MaxFlyCode = 4; //5
/*
 * |----- isValid FUNCIONES ----- |
 */

static int isValidFlyCode (char* flyCode, FlyCode* listFlyCode, int len_flyCode)
{
	int retorno = -1; // Error flyCode is NULL or listFlyCode is NULL or len <= 0 or Its not a Alphanumerical

	if ( flyCode != NULL && listFlyCode != NULL && len_flyCode > 0 && isValidAlfaNumerico(flyCode)  ) {

		for (int i = 0; i < len_flyCode; i++)
		{
			if (strcmp(flyCode,listFlyCode[i].flycode) == 0 ) // (Si el FlyCode Ingresado coincide con uno de la lista )
			{

				retorno = 1; // todo Ok
				break;
			}
		}
	}
	return retorno;
}
static int isValidId (int id)
{
	int retorno = -1; //Not id

	if(id >= 100)
	{
		retorno = 1; //ok
	}
	return retorno;
}

static int isValidPrice (float price)
{
	int retorno = -1; // Not price

	if (price > 100  )
	{
		retorno = 1;//Ok
	}

	return retorno;
}
static int isValidTypePassenger (int typePassenger)
{
	int retorno = -1; // Not price

	if ( typePassenger > 0 && typePassenger <= pass_MaxTypePassenger+1 )
	{
		retorno = 1;//Ok
	}

	return retorno;
}


/*
 * |----- HARDCODE - FUNCIONES ------|
 */



int pass_HardcodePassengers (Passenger *list, int Passengers){

	int retorno=-1;
	int i;
	if(list!=NULL && Passengers >= 0){

		retorno=0;
		Passenger buffer[100]=
				{{101,"Diego","Marin",6000,"EQ315",1,CARGADO},
				{102,"Carla","Suarez", 8000,"XL1371",3, CARGADO},
				{103,"German","Scarafilo",6000,"EQ315",1,CARGADO},
				{104,"Carlos","Ramirez",4000,"AR140",8,CARGADO},
				{105,"Hector","Alvarez", 5500,"CM158",9, CARGADO},
				{106,"Edgar","Facundo",9800,"AR140",1,CARGADO},
				{107,"Fabian","Geopolis",5000,"PS408",5,CARGADO},
				{108,"David","Yiuta",4000,"CM158",6,CARGADO},
				{109,"Octavio","Lepez", 6000,"CM158",1,CARGADO},
				{110,"Gonzalo","Bastian",5000,"EQ315",6,CARGADO},
				{111,"Emiliano","Marin", 4000,"CM158",1,CARGADO},
				{112,"Wilker","Fariñez",3000,"XL1371",2,CARGADO}};
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
		TypePassenger buffer[100]=
						   {{1,"Economica"},
						    {2,"Ejecutiva"},
							{3,"Negocios"}};

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

int AltaForzada (Passenger* arrayPassengersHardcode, int len,FlyCode* arrayFlyCodes, int len_flyCode, TypePassenger* arrayTypePassengers, int len_typePass)
{
	int retorno =-1;

	if (arrayPassengersHardcode!=NULL && len>0 && arrayFlyCodes !=NULL && len_flyCode >0 && arrayTypePassengers!=NULL && len_typePass > 0)
	{
		retorno = 0;
		pass_HardcodePassengers(arrayPassengersHardcode, t_pass);
		pass_HardcodeTypePassenger(arrayTypePassengers, t_typePass);
		pass_HardcodeFlyCodePassenger(arrayFlyCodes, t_flyCodesPass);
		printf("\nAlta Forzada Completada!!!..........\n\n");
	}

	return retorno;
}

/*
 * |----- SUB FUNCIONES ------|
 *
 */

int pass_checkPassenger (Passenger* list, int len){

	int i;
	int respuesta=-1; // Pointer NULL or len < 0 or there is not space
	if (list!=NULL && len>0  ) {
		for (i = 0; i < len; i++) {
			if(list[i].isEmpty!= VACIO){
				respuesta=0; //There are space in the array
				break;
			}
		}
	}

	return respuesta;
}

int initPassengers(Passenger* list, int len){

	int retorno=-1;
	int i;

	if(list!=NULL && len>0){
		retorno=0;
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty=VACIO;
		}
	}

	return retorno;
}

int pass_findEmptySpace (Passenger* list, int len){

	int index=-1;
	int i;

	if(list!=NULL && len>0){
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty== VACIO) {
				index = i;
				break;
			}
		}
	}

	return index;
}

int findPassengerById(Passenger* list, int len,int id){

	int index=-1;
	int i;
	if (list!=NULL && len>0 && id>0)
	{
		for (i = 0; i < len; i++)
		{
			if ( list[i].id == id &&
				 list[i].isEmpty== CARGADO )
			{
				index = i;
				break;
			}
		}
	}

	return index;
}
int pass_confirmDecision (char* mensaje){

	int confirmar = -1;// cancelled desition

	if(mensaje!=NULL && !utn_getNumero(&confirmar, mensaje, "\nSolo 1 o 0\n", 0, 1, 1))
	{
		if (confirmar) {
			return 1;//Confirm Decision
		}
		printf("\n-------DECISION CANCELADA------------\n");
	}

	return confirmar;
}
/*___________________________________

	  	  Flight Price
_____________________________________
*/
float pass_pricePassengers (Passenger* list, int len){

	float price=-1; // Pointer NULL or len < 0 or there is not space or no salary
	int i;
	if (list!=NULL && len>=0 && pass_checkPassenger(list, len) == 0) {

		for (i = 0; i < len; i++) {

			price+=list[i].price; // Return !=0 OK
		}
	}
	return price;
}

float pass_promedyPassengers (Passenger* list, int len, float price){

	float promedio=-1;// Pointer NULL or len < 0 or there is not space or no salary
	int contador=0;
	int i;
	if (list!=NULL && len>=0  && pass_checkPassenger(list, len) == 0 ) {

		for (i = 0; i < len; ++i) {
			contador++;
		}

		promedio=price/contador; // !=0 OK
	}
	return promedio;
}
int pass_checkPassengerPrice (Passenger* list,int len, int order)
{
	int retorno=-1;// Pointer NULL or len and order <0 or there is not space
	float price;
	float promedio;
	int contador = 0;
	if (list!=NULL && len>=0 && pass_checkPassenger(list, len) == 0 ) {

		price=pass_pricePassengers(list, len);
		promedio=pass_promedyPassengers(list, len, price);

		switch (order) {
			case 1:
				if(price!=0 && promedio!=0)
				{
					printf("\nPrecio Total: %.2f\n", price);
					printf("\nPrecio Promedio: %.2f\n", promedio);
					retorno=0; //OK
				}
				break;
			case 2:
				for (int i = 0; i < len; i++) {
					if (list[i].price>= promedio ) {
						contador++;

						//Mostrar solo los pasajeros
					}
				}

				printf("\nPrecio Promedio: %.2f\n"
						"\nHay %d Passengers que superan el precio promedio\n", promedio, contador);
				break;
		}
	}

	return retorno;
}
/*
 *
 * |------- INFORMAR Passengers --------|
 *
 *
 */
int pass_prinfTypePassenger (TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1; // NULL pointer or len < 0

	if (listTypePass !=NULL && len_typePass > 0) {

		printf("\n"
				"  --------------------\n"
				" |  Tipo de Pasajero  |\n"
				"  --------------------\n");

		for (int i = 0; i < len_typePass; i++) {

			printf(" |%2d) %-10s      |\n",i+1,listTypePass[i].descripcionPassenger);
		}
		printf("  --------------------\n");
		retorno = 0; //OK
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
int printPassenger(Passenger* this,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass,int len_typePass,int* contadorFlyCode, int* contadorTypePassenger)
{

	int retorno=-1; // No passanger load or any len < 0 or pointer NULL

	if (this!=NULL && this->isEmpty == CARGADO && listFlyCode !=NULL && listTypePass !=NULL && len_flyCode > 0 && len_typePass > 0 && *contadorFlyCode>=0 && *contadorTypePassenger>=0 )
	{
		for (int i = 0; i < len_flyCode; i++)
		{
			if (!stricmp(this->flycode,listFlyCode[i].flycode)) //Empleado encuentra su codigo en la lista
			{
				for (int j = 0; j < len_typePass;j++)
				{
					if (this->typePassenger == listTypePass[j].idTypePassenger) // Empleado encuentra su idTipo en la lista
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
							if (*contadorTypePassenger <= pass_MaxTypePassenger) { // Si todavia queda un elemento de la lista de tipos por mostrar

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



int printPassengers(Passenger* list, int length,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{

	int retorno=-1; // No passanger load or any len < 0 or pointer NULL

	int contadorFlyCode = 0; // Variable de control para mostrar la lista de Codigos
	int contadorTypePass = 0; // Variable de control para mostrar la lista de Tipos de Pasajeros

	if (list!=NULL && length>0 && listFlyCode!=NULL && len_flyCode >0 && listTypePass !=NULL && len_typePass ) {

		pass_printCoverListPassengerListFlyCodeListTypePassenger ();

		for (int i = 0; i < length; i++) {

			printPassenger(&list[i],listFlyCode,len_flyCode,listTypePass,len_typePass,&contadorFlyCode,&contadorTypePass);
		}
		contadorFlyCode = 0;
		contadorTypePass = 0; //Reinicio los contadores

		retorno=0; // todo ok
	}
	return retorno;
}
void printfSubMenuInformarPrice ()
{
	printf("\n1) Total y Promedio de los salarios\n"
			"2) Cuantos pasajeros superan el precio promedio  \n"
			"\n\n-------------------------------------------------\n\n");
}
void printfListados ()
{
	printf("\n1) Listado de (Pasajeros) , Listado de (Codigos de vuelo) y Listado de (Tipos de Pasajeros)\n"
			"2) Listados de los Pasajeros ordenados alfabéticamente por (Apellido) y (Tipo de pasajero).\n"
			"3) Listado de los Pasajeros por  (Código de vuelo)  y estados de vuelos (ACTIVO)\n"
			"\n----------------------------------------------\n");
}


/*------------------------------------
 * 			Sort
 * -----------------------------------
 */
int pass_sortPassengersById (Passenger* lista, int len){

	int retorno=-1;
	int i;
	int contador=0;
	int flagSwap;
	Passenger buffer;
	if( lista!=NULL &&  len>0 ){
		do{
			flagSwap=0;
			for(i=0; i<len-1 ; i++){
				contador++;
				if( lista[i].id > lista[i+1].id)
				{
					flagSwap=1;
					buffer=lista[i];
					lista[i]=lista[i+1];
					lista[i+1]=buffer;
				}
			}
			len--;
		}while(flagSwap);

		retorno=contador;
	}

	return retorno;
}
int sortPassengers(Passenger* lista, int len, int order){

	int retorno=-1;
	int i;
	int contador=0;
	int flagSwap;
	Passenger auxPay;

	if( lista!=NULL &&  len > 0 && order >0 && pass_checkPassenger(lista, len)== 0 ){

		do{
			flagSwap=0;

			for(i=0; i<len-1 ; i++){

				contador++;

				switch (order) {
					case 1:
						if( stricmp(lista[i].lastName,lista[i+1].lastName) > 0 )
						{
							flagSwap=1;
							auxPay=lista[i];
							lista[i]=lista[i+1];
							lista[i+1]=auxPay;

							if(	lista[i].typePassenger >= lista[i+1].typePassenger)
							{
								flagSwap=1;
								auxPay.typePassenger=lista[i].typePassenger;
								lista[i].typePassenger=lista[i+1].typePassenger;
								lista[i+1].typePassenger=auxPay.typePassenger;
							}
						}
						break;
					case 2:
						if(	stricmp(lista[i].lastName,lista[i+1].lastName) < 0 )
						{
							flagSwap=1;
							auxPay=lista[i];
							lista[i]=lista[i+1];
							lista[i+1]=auxPay;
							if(	lista[i].typePassenger <= lista[i+1].typePassenger)
							{
								flagSwap=1;
								auxPay.typePassenger=lista[i].typePassenger;
								lista[i].typePassenger=lista[i+1].typePassenger;
								lista[i+1].typePassenger=auxPay.typePassenger;
							}
						}

						break;
				}
			}
			len--;
		}while(flagSwap);

		retorno=contador;
	}

	return retorno;
}

int pass_sortPassengersByCode (Passenger* lista, int len, int order, FlyCode* listFlyCode, int len_flycode)
{

	int retorno=-1;
	int i;
	int contador=0;
	int flagSwap;
	Passenger auxPay;

	if( lista!=NULL &&  len > 0 && order >0 && listFlyCode !=NULL && len_flycode > 0 && !pass_checkPassenger(lista, len))
	{
		do{
			flagSwap=0;

			for(i=0; i<len-1 ; i++){

				for (int j = 0; j < len_flycode; j++) {

					contador++;
					switch (order)
					{
						case 1:

							if (!stricmp(lista[i].flycode,listFlyCode[j].flycode) &&
									listFlyCode[j].statusFlight == ACTIVO)
							{
								flagSwap=1;

								if (!stricmp(lista[i+1].flycode,listFlyCode[j].flycode) &&
									listFlyCode[j].statusFlight == ACTIVO)
								{

									if( stricmp(lista[i].flycode,lista[i+1].flycode) > 0)
									{
										flagSwap=1;
										auxPay=lista[i];
										lista[i]=lista[i+1];
										lista[i+1]=auxPay;
									}
								}
							}
							break;
						case 2:

							if (!stricmp(lista[i].flycode,listFlyCode[j].flycode) &&
									listFlyCode[j].statusFlight == ACTIVO)
							{
								flagSwap=1;

								if (!stricmp(lista[i+1].flycode,listFlyCode[j].flycode) &&
										listFlyCode[j].statusFlight == ACTIVO)
								{

									if(	stricmp(lista[i].flycode,lista[i+1].flycode) < 0 )
									{
										flagSwap=1;
										auxPay=lista[i];
										lista[i]=lista[i+1];
										lista[i+1]=auxPay;
									}
								}
							}
							break;
					}
				}
			}
			len--;
		}while(flagSwap);

		retorno=contador;
	}

	return retorno;
}

int printfSubMenuInformarListar (Passenger* list, int len,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int opcion; //NULL pointer or len < 0
	int order;
	int retorno = -1;

	if (listFlyCode != NULL && len_flyCode  > 0 && listTypePass!= NULL &&  len_typePass  > 0) {

		printfListados();
		retorno = 2;// Opcion invalida

		if (!utn_getNumero(&opcion, "Opcion: ", "\nError, opcion invalida\n", 1,3, 1))
		{
			switch (opcion)
			{
				case 1: //Mostrar todas las listas cargadas
					printPassengers(list, len, listFlyCode, len_flyCode, listTypePass, len_typePass);
					retorno =0; //OK
					break;
				case 2: // Mostrar listas
					printf(	"\n1) Ordenar de la A a la Z\n"
							"2) Ordenar de la Z a la A\n");

					retorno = 2; //Opcion Invalida
					if(!utn_getNumero(&order,"Opcion: ", "\nError, opcion invalida\n", 1, 2, 1))
					{
						if (!sortPassengers(list, len, order)) {

							printPassengers(list, len,listFlyCode, len_flyCode, listTypePass, len_typePass);
							retorno=0; //OK
						}
					}
					break;
				case 3:
					printf(	"\n1) Ordenar de la A a la Z\n"
							"2) Ordenar de la Z a la A\n");
					if(!utn_getNumero(&order,"Opcion: ", "\nError, opcion invalida\n", 1, 2, 1))
					{
							//Mostrar codigos de vuelo activo
						if (!pass_sortPassengersByCode(list, len, order, listFlyCode, len_flyCode)) {

							printPassengers(list, len,listFlyCode, len_flyCode, listTypePass, len_typePass);
							retorno=0; //OK
						}
					}
					break;
			}
		}
	}

	return retorno;
}
int printfSubMenuInformar (int opcionInformar,Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1; //  NULL pointer or len < 0
	int opcionSueldo;

	if (opcionInformar > 0 && list != NULL && listFlyCode != NULL && len > 0 && len_flyCode  > 0 && listTypePass!= NULL &&  len_typePass  > 0)
	{
		switch (opcionInformar)
		{
			case 1: // Listar y Ordenar
				retorno = printfSubMenuInformarListar(list,len,listFlyCode, len_flyCode, listTypePass,  len_typePass);
				break;
			case 2: //Precio pasaje

				printfSubMenuInformarPrice();
				if(!utn_getNumero(&opcionSueldo, "Opcion: ", "\nError, opcion invalida intentalo de nuevo\n", 1, 2, 1))
				{
					if (!pass_checkPassengerPrice(list, len, opcionSueldo)) {

						retorno=0; //OK
					}
				}
				break;
			case 3: // Mostrar todas las listas
				printPassengers(list, len, listFlyCode, len_flyCode, listTypePass, len_typePass);
				break;
		}
	}
	return retorno;
}


 void printfMenuInformar()
{
	printf("\n0) Volver Menu anterior\n"
			"1) Informar Listados\n"
			"2) Informar Precio de los pasajes.\n"
			"\n-----------------------------------------------\n");
}
void pass_printCoverListPassengerListFlyCodeListTypePassenger (){

	printf("\n" // Portada de la lista de pasajeros 																			   // Portada de la lista de Codigos de Vuelo		// Portada de la lista de Tipos de Pasajeros
			" -------------------------------------------------------------------------------------------------------------------     --------------------------------------          --------------------------------------- \n"
			"| Id   ||    Nombre         ||    Apellido      ||      Precio     ||     Código de vuelo    ||   IdTipoPasajero    |   | Codigo de vuelo  || Estado del vuelo |        | IdTipoPasajero   ||  Tipo de Pasajero | \n"
			" -------------------------------------------------------------------------------------------------------------------     --------------------------------------          --------------------------------------- \n");
}
void printfPassengerOptionsMenuModificar ()
{
	printf("\n0) Volver Menu\n"
			"1) Nombre\n"
			"2) Apellido\n"
			"3) Precio\n"
			"4) Codigo de Vuelo\n"
			"5) Tipo De Vuelo\n"
			"6) Modificar estado de vuelo para un codigo de vuelo\n");
}

void printfPassengerOptionsMenu ()
{
	printf("\t\tPrograma de Passengers en C:\n\n"
			"\t\t1) ALTA Pasajero\n\n"
			"\t\t2) MODIFICACIÓN Pasajero\n\n"
			"\t\t3) BAJA Pasajero\n\n"
			"\t\t4) INFORMAR Pasajero\n\n"
			"\t\t5) Alta Forzada\n\n"
			"\t\t6) Salir\n"
			""
			"\n---------------------------------------------------------------------------------------\n\n");

}

/*
 *
 * |--------- ALTA FUNCIONES ---------|
 *
*/

//_________Getters__________

int passenger_getNameFromStdIn (Passenger* this){

	int retorno = -1; // Error getting a name
	if (this != NULL  && !utn_getCharNombre(this->name, "Nombre: ", "\nError, nombre invalido\n", 1, pass_MaxLenNameLasName))
	{
		if (PrimerasLetrasMayuscula(this->name))
		{
			retorno = 0; //ok
		}
	}
	return retorno;
}
int passenger_getLastNameFromStdIn (Passenger* this){

	int retorno = -1; // Error getting a lastname
	if (this != NULL  && !utn_getCharNombre(this->lastName, "Apellido: ", "\nError, precio invalido\n", 1, pass_MaxLenNameLasName))
	{
		if (PrimerasLetrasMayuscula(this->lastName))
		{
			retorno = 0; //ok
		}
	}
	return retorno;
}
int passenger_getPriceFromStdIn (Passenger* this){

	int retorno = -1; // Error getting a price
	if (this != NULL  && !utn_getFloat(&this->price, "Precio: ", "\nError, precio invalido\n", 1, 10000000, 0))
	{
		retorno = 0; //ok
	}
	return retorno;
}
int passenger_getFlyCodeFromStdIn (Passenger* this, FlyCode* listFlyCode, int len_flyCode){

	int retorno = -1; // this is NULL or listFlyCode is NULL or len <= 0

	if (this != NULL && listFlyCode != NULL && len_flyCode > 0)
	{
		pass_printfFlyCodes ( listFlyCode,  len_flyCode); // Muestra la lista de codigos de vuelo

		if (!utn_getAlphaNumerico(this->flycode, "Codigo de Vuelo: ", "\nError, precio invalido\n",1, 10)) //Pide un codigo de vuelo
		{

			if (isValidFlyCode(this->flycode, listFlyCode, len_flyCode)) // Valida que lo que se Ingresa sea un codigo
			{
				strupr(this->flycode);
				retorno = 0; // Ok
			}
		}
	}
	return retorno;
}
int passenger_getTypePassengerFromStdIn (Passenger* this, TypePassenger* listTypePass, int len_typePass){

	int retorno = -1; // Error - (this) is NULL or (listTypePass) is NULL or len < 0

	if (this != NULL  &&  listTypePass != NULL && len_typePass > 0 )
	{
		pass_prinfTypePassenger(listTypePass, len_typePass);

		if (!utn_getNumero(&this->typePassenger, "Tipo de Pasajero: ", "\nError, tipo de pasajero invalido\n", 1, pass_MaxTypePassenger+1, 1)) //Pido y Valido el Tipo de pasajero con el maximo numero que puede ingresar
		{
			if (isValidTypePassenger(this->typePassenger)) {

				retorno = 0; // OK
			}
		}
	}
	return retorno;
}


int pass_getPassengerFromStdIn (Passenger* buffer, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1; // Failed to get a passenger

	if (buffer!=NULL && listFlyCode !=NULL && len_flyCode >= 0 && listTypePass !=NULL && len_typePass >= 0) {

		if( !passenger_getNameFromStdIn(buffer) &&
			!passenger_getLastNameFromStdIn(buffer) &&
			!passenger_getPriceFromStdIn(buffer) &&
			!passenger_getFlyCodeFromStdIn(buffer, listFlyCode, len_flyCode) &&
			!passenger_getTypePassengerFromStdIn(buffer, listTypePass, len_typePass))
			{
				retorno = 0; // Ok
			}
	}
	return retorno;
}
int passenger_setId (Passenger* this, int id){

	int retorno = -1; // Cant set the id

	if(this != NULL && isValidId(id))
	{
		retorno = 0; //ok
		this->id=id;
	}
	return retorno;

}

int passenger_setName (Passenger* this, char* name){

	int retorno = -1; //Cant set the name

	if(this != NULL && name != NULL && isValidTextoBasico(name, pass_MaxLenNameLasName) )
	{
		retorno = 0; //ok
		strcpy(this->name, name);
	}
	return retorno;

}
int passenger_setLastName (Passenger* this, char* lastName)
{
	int retorno = -1; //Cant set the lastname

	if(this != NULL && lastName != NULL && isValidTextoBasico(lastName, pass_MaxLenNameLasName))
	{
		retorno = 0; // ok
		strcpy(this->name, lastName);
	}
	return retorno;
}
int passenger_setPrice (Passenger* this, float price)
{
	int retorno = -1; //Cant set the price

	if(this != NULL && isValidPrice(price)) //validacion
	{
		retorno = 0; //ok
		this->price = price;
	}
	return retorno;
}

int passenger_setFlyCode (Passenger* this, char* flycode, FlyCode* listFlyCode, int len_flyCode)
{
	int retorno = -1; //Cant set the flycode

	if(this != NULL && flycode != NULL && len_flyCode >= 0 && isValidFlyCode(flycode, listFlyCode, len_flyCode)) // Validacion
	{
		retorno = 0; //OK
		strcpy(this->flycode, flycode);
	}
	return retorno;

}
int passenger_setTypePassenger (Passenger* this, int typePassenger)
{
	int retorno = -1; //Cant set the typePassenger

	if (this != NULL && isValidTypePassenger(typePassenger) )
	{
		retorno = 0; //Ok
		this->typePassenger = typePassenger;
	}
	return retorno;
}
int passenger_setStatusFlightToFlyCode (char* flycode, FlyCode* listFlyCode, int len_flyCode,  int statusFlight)
{
	int retorno = -1; //Cant set the status flight

	if(flycode != NULL && listFlyCode != NULL && len_flyCode >= 0 && isValidFlyCode(flycode, listFlyCode, len_flyCode) ) // Validacion
	{
		for (int i = 0; i < len_flyCode; i++) {

			if (stricmp(flycode, listFlyCode[i].flycode) == 0 &&
					listFlyCode[i].statusFlight == ACTIVO) {  // (Si el FlyCode Ingresado coincide con uno de la lista )

				retorno = 0; //OK
				switch (statusFlight) {
				case 0:
					listFlyCode[i].statusFlight = ACTIVO;
					strcpy(listFlyCode[i].statusFlightChar, "Activo");
					break;
				case 1:
					listFlyCode[i].statusFlight = DEMORADO;
					strcpy(listFlyCode[i].statusFlightChar, "Demorado");
					break;
				case -1:
					listFlyCode[i].statusFlight = CANCELADO;
					strcpy(listFlyCode[i].statusFlightChar, "Cancelado");
					break;
				}
			}
		}
	}
	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[],float price,
		int  typePassenger, char flycode[],FlyCode* listFlyCode, int len_flyCode)
{

	int retorno=-1;
	int index;
	if(list!=NULL && len>0 && name!=NULL && lastName!= NULL &&  price >0 &&  typePassenger>=0){

		if ((index = pass_findEmptySpace(list, len)) >= -1)
		{
			if (	!passenger_setId(&list[index], id) &&
					!passenger_setName(&list[index], name) &&
					!passenger_setLastName(&list[index], lastName) &&
					!passenger_setPrice(&list[index], price) &&
					!passenger_setFlyCode(&list[index], flycode, listFlyCode, len_flyCode) &&
					!passenger_setTypePassenger(&list[index], typePassenger) )
			{

				list[index].isEmpty = CARGADO;
			}
			retorno=0;
		}
	}
	return retorno;
}
int pass_AltaPassengers(Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass){

	int retorno=-1;  //NULL or len <0 cancelled desition
	Passenger buffer;

	if (list !=NULL && len >= 0 && listFlyCode !=NULL && len_flyCode >= 0 && listTypePass !=NULL && len_typePass >= 0 )
	{
		retorno=1; //invalid input data

		if(!pass_getPassengerFromStdIn(&buffer, listFlyCode,len_flyCode,listTypePass,len_typePass)) // Load a passenger
		{
			retorno=2; //Register a passenger cancelled
			if (pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres eliminar este id de la base de datos del sistema?\n"
					"Escribi (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
					"Decisicion: "))
			{

				if (!addPassenger(list, len, idPassengers, buffer.name, buffer.lastName, buffer.price,
						buffer.typePassenger, buffer.flycode, listFlyCode, len_flyCode)) // Add a passenger to the list
				{
					pass__AumentarId(); //Increase Id number
					retorno=0; // Ok
				}
			}
		}
	}

	return retorno;
}



int AltaPassengers (Passenger* arrayPassengers, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno=-1; // Invalid lengths or any NULL pointer
	int VereficarRetornoAltaFuncion;

	if(arrayPassengers!=NULL && len>0 && listFlyCode !=NULL && len_flyCode >= 0 && listTypePass !=NULL && len_typePass >= 0   ){

		retorno=0;

		if (pass_findEmptySpace(arrayPassengers, len) >=0 )
		{
			VereficarRetornoAltaFuncion = pass_AltaPassengers(arrayPassengers, len,listFlyCode,len_flyCode,listTypePass,len_typePass);

			switch (VereficarRetornoAltaFuncion)
			{
				case 0:
					printf("\n\t\tALTA COMPLETADA\n\n");
					break;
				case 1:
					printf("\nIngresa bien los datos, volve a intentarlo\n\n");
					break;
				case 2:
					printf("\nALTA CANCELADA\n\n");
					break;
				default:
					printf("\nError, lenth invalido o NULL pointer \n\n");
					break;
			}
		}
		else{

			printf("\n\tNo hay espacio disponible\n\n");
		}
	}

	return retorno;
}



/*
 *
 * |----- BAJA FUNCIONES ---------|
 *
*/

int BajaPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1;
	int VereficarRetornoBajaFuncion;

	if (list != NULL && len >= 0 && listFlyCode != NULL && len_flyCode >= 0 && listTypePass != NULL && listTypePass!=NULL) {

		if(!pass_checkPassenger(list, len)){

			pass_sortPassengersById(list, len);

			VereficarRetornoBajaFuncion = pass_BajaPassengers(list, len,listFlyCode,len_flyCode,listTypePass,len_typePass);

			retorno = 0;

			switch (VereficarRetornoBajaFuncion) {
			case  0:
				printf("\n\t\tBAJA COMPLETADA\n\n");
				break;
			case -2:
				printf("\n\t\tNo existe ese id o fue dado antes de baja \n\n");
				break;
			case  1:
				printf("\n\t\tBAJA CANCELADA\n\n");
				break;
			case -1:
				printf("\n\t\tError, lenth invalido o NULL pointer\n\n");
				break;
			}
		}
		else{
			printf("\n\tNo hay Pasajeros en el sistema para dar de baja\n\n");
		}
	}

	return retorno;
}

int pass_BajaPassengers (Passenger* list, int len,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass){

	int retorno=-1; //NULL or len <0
	int idIngresado;

	if (list!=NULL && len>0 && listFlyCode !=NULL && len_flyCode >0  && listTypePass !=NULL && len_typePass > 0)
	{
		retorno=-3; // Its not a number
		printPassengers(list, len,listFlyCode,len_flyCode,listTypePass,len_typePass);
		if (utn_getNumero(&idIngresado, "\nId Baja: ", "\nError, intentalo de nuevo\n\n", 0, INT_MAX, 0)==0)
		{
			retorno=-2; // Not found id
			if(findPassengerById(list, len, idIngresado)>=0)
			{
				retorno=1;// Remove cancelled passenger
				if(pass_confirmDecision("\n--------------\n"
										"Confirmar\n"
										"---------------\n"
										"Estas seguro que quieres eliminar este id de la base de datos del sistema?\n"
										"Escribi (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
										"Decisicion: "))
				{
					removePassenger(list, len, idIngresado);
					retorno=0; // Ok
				}
			}
		}
	}

	return retorno;
}

int removePassenger(Passenger* list, int len, int id){

	int retorno=-1;
	int index;
	if (list!=NULL && len>0 && id>0)
	{
		if( (index= findPassengerById(list, len, id)) >= 0 )
		{
			list[index].isEmpty=VACIO; //Change Flag FALSE
			retorno=0;
		}
	}

	return retorno;
}
/*
 *  |------ MODIFICAR FUNCIONES--------|
 */
int passenger_setNewName (Passenger* list, int index )
{

	int retorno = -1; //NULL pointer or index < 0 cancelled desition
	char name[pass_MaxLenNameLasName];

	if (list != NULL && index >=  0) {

		if(!utn_getCharNombre(name, "Nuevo Nombre: ", "\nError, nuevo nombre invalido\n", 1, pass_MaxLenNameLasName))
		{
			if(pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres establecer un nuevo cambio ?\n"
					"Escribi (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
					"Decisicion: "))
			{

				strcpy(list[index].name,name);
				retorno = 0; // Ok
			}
		}
	}
	return retorno;
}
int passenger_setNewLasName (Passenger* list, int index){

	int retorno = -1; //NULL pointer or index < 0 cancelled desition
	char lastName[pass_MaxLenNameLasName];

	if (list !=NULL && index >= 0)
	{
		if( !utn_getCharNombre(lastName, "Nuevo Apellido: ", "\nError, nuevo apellido invalido\n", 1, pass_MaxLenNameLasName))
		{
			if(pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres establecer un nuevo cambio ?\n"
					"Escribi (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
					"Decisicion: "))
			{

				strcpy(list[index].lastName,lastName);
				retorno = 0; // Ok
			}
		}
	}
	return retorno;
}

int passenger_setNewPrice (Passenger* list, int index)
{
	int retorno = -1; //NULL pointer or index < 0 cancelled desition
	float precio;

	if (list != NULL && index >= 0) {

		if (!utn_getFloat(&precio, "Nuevo precio: ", "\nError, precio invalido\n\n", 0, 10000000, 1))
		{
			if(pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres establecer un nuevo cambio ?\n"
					"Escribi (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
					"Decisicion: "))
			{
				if (!passenger_setPrice(&list[index], precio))
				{
					retorno = 0; // Ok
				}
			}
		}
	}

	return retorno;
}

int passenger_setNewFlyCode (Passenger* list, int index,FlyCode* listFlyCode, int len_flyCode )
{
	int retorno = -1; //NULL pointer or index < 0 or cancelled desition
	char flyCode[10];

	if (list != NULL && index >= 0 && listFlyCode && len_flyCode > 0) {

		retorno = -1; //Its not a flyCode into the listFlyCode
		pass_printfFlyCodes(listFlyCode, len_flyCode);
		if(		!utn_getAlphaNumerico(flyCode, "Nuevo Codigo de Vuelo: ", "\nError,codigo de vuelo invalido\n\n", 1, pass_MaxLenNameLasName) &&
				isValidFlyCode(flyCode, listFlyCode, len_flyCode) )
		{
			if(pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres establecer un nuevo cambio ?\n"
					"Escribi (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
					"Decisicion: "))
			{
				passenger_setFlyCode(&list[index],flyCode , listFlyCode, len_flyCode);
				retorno = 0; // Ok
			}
		}
	}
	return retorno;
}


int passenger_setNewTypePassenger (Passenger* list,int index,TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1; //NULL pointer or index < 0 cancelled desition
	int typePassenger;

	if (list != NULL && index >= 0 && listTypePass != NULL &&  len_typePass > 0)
	{
		pass_prinfTypePassenger(listTypePass, len_typePass);
		if (!utn_getNumero(&typePassenger, "Nuevo Tipo de Pasajero: ", "\nError,Tipo de Pasajero invalido\n\n", 1, 3, 1))
		{
			if(pass_confirmDecision(
					"\n--------------\n"
					"Confirmar\n"
					"---------------\n"
					"Estas seguro que quieres establecer un nuevo cambio ?\n"
					"Escribi (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
					"Decisicion: "))
			{
				if (!passenger_setTypePassenger(&list[index], typePassenger))
				{
					retorno = 0; // Ok
				}
			}
		}
	}

	return retorno;
}

int pass_changePassengerSpace (Passenger* list,int opcion , int index, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{

	int cambio=-2; // Invalid length or NULL pointer or Cancel Modification

	if (opcion>=1 && list[index].isEmpty==CARGADO  && listFlyCode != NULL && len_flyCode > 0 && listTypePass != NULL && len_typePass > 0)
	{

		switch (opcion)
		{
			case 1:
				if (!passenger_setNewName(list, index)) {
					cambio = 0; //OK
				}
				break;
			case 2:
				if (!passenger_setNewLasName(list, index)) {
					cambio = 0; //OK
				}

				break;
			case 3:
				if (!passenger_setNewPrice(list, index)) {
					cambio = 0; //OK
				}
				break;
			case 4:
				if (!passenger_setNewFlyCode(list, index, listFlyCode, len_flyCode)) {
					cambio = 0; //OK
				}
				break;
			case 5:
				if (!passenger_setNewTypePassenger(list, index, listTypePass, len_typePass)) {
					cambio = 0; //OK
				}
				break;
		}
	}
	return cambio;
}
int pass_ModificarEstadoVueloCodigoVuelo (FlyCode*listFlyCode,int len_flyCode)
{
	Passenger* buffer = NULL;
	char flyCode[11];
	int statusFlight;
	int retorno = -3; //Pointer NULL or len <0

	if (listFlyCode != NULL && len_flyCode > 0)
	{
		retorno = -2;//\nError, codigo de vuelo invalido
		pass_printfFlyCodes(listFlyCode, len_flyCode);
		if (!utn_getAlphaNumerico(flyCode, "Ingrese el codigo de vuelo: ", "\nError, codigo de vuelo invalido\n\n", 1, 11) &&
				isValidFlyCode(flyCode, listFlyCode, len_flyCode))
		{
			 retorno = -2;//Error Opcion invalida
			if (!utn_getNumero(&statusFlight,
					"\n1) ACTIVO\n"
					"2) CANCELADO\n"
					"3) DEMORADO\n"
					"\nPor que estado de vuelo lo quieres cambiar ? : ", "\nError, Ingrese una opcion valida\n\n", 1, 3, 1))
			{
				retorno = 1; //Cancel Modificacion
				if (pass_confirmDecision(
						"\n--------------\n"
						"Confirmar\n"
						"---------------\n"
						"Estas seguro que quieres cambiar el estado de vuelo ?\n"
						"Escribi  (1) |Confirmar Baja|  -   Escribi (0)  |Cancelar Baja|\n"
						"Decisicion: "))
				{
					strcpy(buffer->flycode,flyCode);
					passenger_setStatusFlightToFlyCode(buffer->flycode, listFlyCode, len_flyCode, statusFlight);
					retorno = 0; //OK
				}
			}
		}
	}

	return retorno;
}
int pass_ModificarPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass){
{
	int retorno=-3; //Pointer NULL or len <0
	int idIngresado;
	int opcion;
	int index;

	if (list!=NULL && len>0 &&  listFlyCode != NULL && len_flyCode > 0 && listTypePass != NULL && len_typePass > 0)
	{
		printPassengers(list, len,listFlyCode,len_flyCode,listTypePass,len_typePass);

		if (!utn_getNumero(&idIngresado, "\nId Modificar: ", "\nError, Ingresa un numero valido\n\n", 100, INT_MAX, 1))
		{
			retorno=-1; // -1 Not found Id
			if((index= findPassengerById(list, len, idIngresado))>=0)
			{
				printfPassengerOptionsMenuModificar();

				retorno=-2; //Error Opcion invalida
				if(!utn_getNumero(&opcion,"Opcion:    ", "\nError, opcion invalida, vuelva intentarlo \n\n", 0, 6, 1))
				{
					retorno=2; // Back Menu opcion == 0
					if(opcion!=0)
					{
						retorno=1;// 1 Cancel Modificacion
						if (opcion == 6)
						{
							retorno = pass_ModificarEstadoVueloCodigoVuelo(listFlyCode, len_flyCode);

							if (!retorno) {

								retorno = 0; // 0 ok
							}
						}
						else{
							if(!pass_changePassengerSpace(list,opcion , index,listFlyCode, len_flyCode,  listTypePass, len_typePass))
							{
								return 0; // 0 ok
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}
int ModificarPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno = -1;
	int modificarPassengers;

	if (list != NULL && len > 0 && listFlyCode != NULL && len_flyCode  > 0 && listTypePass != NULL && len_typePass > 0 )
	{
		retorno = 0;

		if (pass_checkPassenger(list, len) == 0)
		{
			pass_sortPassengersById(list, len);

			modificarPassengers = pass_ModificarPassengers(list, len,listFlyCode,len_flyCode,listTypePass,len_typePass);

			switch (modificarPassengers)
			{
				case 0:
					printf("\n\t\tMODIFICAION COMPLETADA\n\n");
					break;
				case 1:
					printf("\n\t\tMODIFICACION CANCELADA\n\n");
					break;
				case 2:
					//Volver al menu anterior
					break;
				case -1:
					printf("\n\t\tNo existe ese id o fue dado antes de baja \n\n");
					break;
				case -2:
					printf("\n\t\t Error, mal ingreso de datos\n\n");
					break;
				case -3:
					printf("\n\t\t Error, NULL pointer or len < 0\n\n");
					break;
				case -4:
					printf("\n\t\tError, codigo de vuelo invalido \n\n");
					break;
			}
		}
	}
	else{
		printf("\n\tNo hay pasajeros en el sistema para modificar un Pasajero\n\n");
	}
	return retorno;
}



int pass_InformarPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno=-1;// Pointer NULL or len <0
	int opcionInformar;

	if (list!=NULL && len>=0 && listFlyCode != NULL && len_flyCode  > 0 && listTypePass != NULL && len_typePass > 0)
	{

		retorno = 2; // Opcion Invalida
		printfMenuInformar();
		if(!utn_getNumero(&opcionInformar, "Opcion: ", "\nError, opcion invalida \n", 0, 2, 1))
		{
			retorno=-2; // Back Menu
			if (opcionInformar > 0)
			{
				retorno = printfSubMenuInformar(opcionInformar,list,len,listFlyCode,len_flyCode,listTypePass,len_typePass);

			}
		}
	}
	return retorno;
}

int InformarPassenger (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass)
{
	int retorno =-1;
	int infomarPassengers;

	if (list != NULL && len > 0 && !pass_checkPassenger(list, len)  && listFlyCode != NULL && len_flyCode  > 0 && listTypePass != NULL && len_typePass > 0 )
	{
		pass_sortPassengersById(list, len);

		infomarPassengers = pass_InformarPassengers(list, len,listFlyCode,len_flyCode,listTypePass,len_typePass);

		switch (infomarPassengers)
		{
			case 0:
				printf("\n\t\tINFORMAR COMPLETADO\n\n");
				break;
			case -1:
				printf("\nError, lenth invalido o NULL pointer\n\n");
				break;
			case -2:
				//Back Menu
				break;
			case 2:
				printf("\nDatos Invalidos, Ingresa correctamente las opciones\n\n");
				break;
		}
	}
	else{
		printf("\n\tNo hay Passengers en el sistema para informar Passengers\n\n");
	}
	return retorno;
}


















