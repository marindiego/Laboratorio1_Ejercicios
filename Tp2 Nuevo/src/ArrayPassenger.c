/*
 * Passenger.c
 *
 *  Created on: 10 nov. 2021
 *      Author: Usuario
 */

#include "ArrayPassenger.h"

static int idPassengers = 100;

static int pass__GenerarId (){

	return idPassengers++;
}

/*
 * |----- FUNCIONES EXTRAS------|
 *
 */
int pass_checkPassenger (Passenger* list, int len){

	int i;
	int respuesta=-1; // Pointer NULL or len < 0 or there is not space
	if (list!=NULL && len>0  ) {
		for (i = 0; i < len; i++) {
			if(list[i].isEmpty!= VACIO){
				respuesta=0; //There are space
				break;
			}
		}
	}

	return respuesta;
}

int pass_HardcodePassengers (Passenger *list, int len){

	int retorno=-1;
	int i;
	if(list!=NULL && len >= 0){

		retorno=0;
		Passenger buffer[1000]=
				{{101,"Diego","Marin",6000,"EQ315",1,CARGADO},
				{102,"Carla","Suarez", 8000,"XL1405",3, CARGADO},
				{103,"German","Scarafilo",6000,"EQ317",1,CARGADO},
				{104,"Carlos","Ramirez",4000,"AR140",8,CARGADO},
				{105,"Hector","Alvarez", 5500,"KL1766",9, CARGADO},
				{106,"Edgar","Facundo",9800,"LH6810",1,CARGADO},
				{107,"Fabian","Geopolis",5000,"PS408",5,CARGADO},
				{108,"David","Yiuta",4000,"CM158",6,CARGADO},
				{109,"Octavio","Lepez", 6000,"EQ179",1,CARGADO},
				{110,"Wilker","Fariñez",2000,"XL1371",CARGADO}};
				//Agregar Otro Passengers

		for (i = 0; i < len; i++) {
			list[i]=buffer[i];
		}
	}

	return retorno;
}

int pass_HardcodeTypePassenger (TypePassenger* list, int len_tpass)
{
	int retorno = -1;

	if(list!=NULL && len_tpass >= 0){

		retorno = 0;
		TypePassenger buffer[9]=
						   {{1,"Adulto.(ADT)"},
						    {2,"Menor"},
							{3,"Infantes"},
							{4,"Embarazadas"},
							{5,"Enfermos"},
							{6,"Niños solos"},
							{7,"En camilla"},
							{8,"Persona con sobrepeso"},
							{9,"Incapacidad visual o auditiva"}};

		for (int i = 0; i < len_tpass; i++) {
			list[i]=buffer[i];
		}

	}
	return retorno;
}


int initPassengers(Passenger* list, int len){

	int retorno=-1;
	int i;

	if(list!=NULL && len>0){
		retorno=0;
		for (i = 0; i < len; i++) {
			list[i].isEmpty=VACIO;
		}
	}

	return retorno;
}

int pass_findemptySpace (Passenger* list, int len){

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

	int confirmar=-1;
	int desicion;

	if(mensaje!=NULL && utn_getNumero(&desicion, mensaje, "\nSolo 1 o 0\n", 0, 1, 1)==0)
	{
		if (desicion == 0) {
			confirmar=0;
		}
	}

	return confirmar;
}

/*
 *
 * |--------- ALTA FUNCIONES ---------|
 *
*/


int addPassenger(Passenger* list, int len, int id, char name[], char lastName[],float price,int  typePassenger, char flycode[], int statusFlight){

	int retorno=-1;
	int index;
	if(list!=NULL && len>0 && name!=NULL && lastName!= NULL &&  price >0 &&  typePassenger>=0){

		index = pass_findpasstySpace(list, len);
		if (index!=-1) {
			retorno=0;
			list[index].id = id;
			list[index].isEmpty= CARGADO;
			strcpy(list[index].name, name);
			strcpy(list[index].lastName, lastName);
			list[index].price = price;
			list[index].typePassenger = typePassenger;
			strcpy(list[index].flycode, flycode);
			list[index].statusFlight = statusFlight;
		}
	}
	return retorno;
}
int pass_AltaPassengers(Passenger* list, int len){

	Passenger buffer;
	int retorno=-1;  //NULL or len <0


	if (list!=NULL && len > 0)
	{
		retorno=1; //bad data entry

		if( !utn_getCharNombre(buffer.name, "Nombre: ", "", 0, 50) &&
		    !utn_getCharNombre(buffer.lastName, "Apellido: ", "", 0,50) &&
			!utn_getFloat(&buffer.price, "Precio: ", "", 1, 10000000, 0) &&
			!utn_getNumero(&buffer.sector, "Sector: ", "", 0, INT_MAX, 0))
		{
			if (!addPassenger(list, len, idPassengers, buffer.name, buffer.lastName, buffer.salary, buffer.sector))
			{
				retorno=0; // Ok
				pass__GenerarId();
			}
		}
	}

	return retorno;
}

int controller_AltaPassengers (Passenger* arrayPassengers, int t_pass)
{
	int retorno=-1;
	int altaPassengers;

	if(arrayPassengers!=NULL && t_pass>0 ){

		retorno=0;

		if (pass_findpasstySpace(arrayPassengers, t_pass) >= 0)
		{

			if (!(altaPassengers = pass_AltaPassengers(arrayPassengers, t_pass))) {
				printf("\n\t\tALTA COMPLETADA\n\n");
			}
			else{

				if(altaPassengers == 1){
					printf("\nError, ingresa bien los datos, volve a intentarlo\n\n");
				}
				else{
					printf("\nError, lenth invalido o NULL pointer \n\n");
											}
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

int controller_BajaPassengers (Passenger* list, int t_pass)
{
	int retorno = -1;
	int bajaPassengers;

	if (list != NULL && t_pass >= 0) {

		retorno = 0;

		if(pass_checkPassenger(list, t_pass) == 0){

			pass_orderPassengersById(list, t_pass);

			bajaPassengers = pass_BajaPassengers(list, t_pass);

			switch (bajaPassengers) {
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
			printf("\n\tNo hay Passengers en el sistema para dar de baja\n\n");
		}
	}

	return retorno;
}

int pass_BajaPassengers (Passenger* list, int len){

	int retorno=-1; //NULL or len <0
	int idIngresado;
	if (list!=NULL && len>0 )
	{
		retorno=-3; // Its not a number
		printPassengers(list, len);
		if (utn_getNumero(&idIngresado, "\nId Baja: ", "\nError, intentalo de nuevo\n\n", 0, INT_MAX, 0)==0)
		{
			retorno=-2; // Not found id
			if(findPassengerById(list, len, idIngresado)>=0)
			{
				retorno=1;// Cancel remove id
				if(pass_confirmDecision("\tConfirmar Baja = 0       Cancelar Baja = 1:  ")==0)
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
		if( (index= findPassengerById(list, len, id)) >= 0 ){
			list[index].ispassty=VACIO;
			retorno=0;
		}
	}

	return retorno;
}


/*
 *  |------ MODIFICAR FUNCIONES--------|
 */
 int setNewName (Passenger* list, int index ){

	 int retorno = -1;
	 Passenger buffer;

	 if (list != NULL ) {

		 if(!utn_getCharNombre(buffer.name, "Nuevo Nombre: ", "\nError, intentalo de nuevo\n", 0, 50)){

			 if(pass_confirmDecision("\tConfimar Modificacion = 0    Cancelar Modificaion = 1: ")==0){

				 retorno = 0;
				 strcpy(list[index].name,buffer.name);
			 }
		 }
	 }

	 return retorno;
 }
int setNewLasName (Passenger* list, int index){

	int retorno = -1;
	Passenger buffer;

	if( utn_getCharNombre(buffer.lastName, "Nuevo Apellido: ", "\nError, intentalo de nuevo\n", 0, 50)==0){

		if(pass_confirmDecision("\tConfimar Modificacion = 0    Cancelar Modificaion = 1: ")==0){

			retorno = 0;
			strcpy(list[index].lastName,buffer.lastName);
		}
	}

	return retorno;
}
int setNewWage (Passenger* list, int index){

	int retorno = -1;
	Passenger buffer;

	if(utn_getFloat(&buffer.salary, "Nuevo Salario: ", "\nError, intentalo de nuevo\n", 0, INT_MAX, 0)==0){

		if(pass_confirmDecision("\tConfimar Modificacion = 0    Cancelar Modificaion = 1: ")==0){

			retorno = 0;
			list[index].salary=buffer.salary;
		}
	}
	return retorno;
}
int setNewSector (Passenger* list, int index){

	int retorno = -1;
	Passenger buffer;

	if(utn_getNumero(&buffer.sector, "Nuevo Sector: ", "\nError, intentalo de nuevo\n", 0, INT_MAX, 0)==0){

		if(pass_confirmDecision("\tConfimar Modificacion = 0    Cancelar Modificaion = 1: ")==0){

			retorno = 0;
			list[index].sector=buffer.sector;
		}
	}

	return retorno;
}
int pass_changePassengerSpace (Passenger* list,int opcion , int index){

	int cambio=-1;

	if (opcion>=1 && list[index].ispassty==CARGADO)
	{
		switch (opcion)
		{
			case 1:
				setNewName(list, index);
				break;
			case 2:
				setNewLasName(list, index);
				break;
			case 3:
				setNewWage(list, index);
				break;
			case 4:
				setNewSector(list, index);
				break;
		}
	}

	return cambio;
}

int pass_ModificarPassengers (Passenger* list, int len){

	int retorno=-3; //Pointer NULL or len <0
	int idIngresado;
	int opcion;
	int index;

	if (list!=NULL && len>0)
	{
		printPassengers(list, len);

		if ( utn_getNumero(&idIngresado, "\nId Modificar: ", "\nError, intentalo de nuevo\n\n", 0, INT_MAX, 0) ==0 )
		{
			retorno=-1; // -1 Not found Id

			if((index= findPassengerById(list, len, idIngresado))>=0)
			{
				retorno=-2; // -2 Wrong Seleccion
				if(utn_getNumero(&opcion,"\n0) Volver Menu\n"
										   "1) Nombre\n"
										   "2) Apellido\n"
										   "3) Salario\n"
										   "4) Sector\n"
										   "Opcion:    ",
										   "\nError, intentalo de nuevo\n\n", 0, 4, 0)==0)
				{

					retorno=2; // Back Menu
					if(opcion!=0)
					{
						retorno=1;// 1 Cancel Modificacion
						if(pass_changePassengerSpace(list,opcion , index)==0)
						{
							retorno=0; // 0 ok
						}
					}
				}
			}
		}
	}

	return retorno;
}
int controller_ModificarPassengers (Passenger* list, int t_clie){

	int retorno = -1;
	int modificarPassengers;

	if (list != NULL && t_clie ) {
		retorno = 0;

		if (pass_checkPassenger(list, t_clie) == 0)
		{
			pass_orderPassengersById(list, t_clie);

			modificarPassengers = pass_ModificarPassengers(list, t_clie);

			switch (modificarPassengers) {
			case 0:
				printf("\n\t\tMODIFICAION COMPLETADA\n\n");
				break;
			case 1:
				printf("\n\t\tMODIFICACION CANCELADA\n\n");
				break;
			case 2:
				printf("\n\n");
				break;
			case -1:
				printf("\n\t\tNo existe ese id o fue dado antes de baja \n\n");
				break;
			}
		}
		else{
			printf("\n\tNo hay pasajeros en el sistema para modificar un Pasajero\n\n");
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

int pass_orderPassengersById (Passenger* lista, int len){

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

							if(	lista[i].sector >= lista[i+1].sector)
							{
								flagSwap=1;
								auxPay.sector=lista[i].sector;
								lista[i].sector=lista[i+1].sector;
								lista[i+1].sector=auxPay.sector;
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
							if(	lista[i].sector <= lista[i+1].sector)
							{
								flagSwap=1;
								auxPay.sector=lista[i].sector;
								lista[i].sector=lista[i+1].sector;
								lista[i+1].sector=auxPay.sector;
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

int printPassenger(Passenger* list){

	int retorno=-1;

	if (list!=NULL && list->isEmpty== CARGADO )
	{
		retorno=0;
		printf("%4d  |    %-7s     |    %-9s     | %12.2f    |     %5d      |\n"
			   "______|________________|__________________|_________________|________________|\n" ,list->id ,list->name, list->lastName, list->salary, list->sector);
	}

	return retorno;
}


int printPassengers(Passenger* list, int length){

	int retorno=-1;
	int i;
	if (list!=NULL && length>0 ) {
		retorno=0;

		printf("\n                                                                            \n"
			   "_____________________________________________________________________________ \n"
			   "      |                |                  |                 |                |\n"
			   " Id   |    Nombre      |    Apellido      |      Salario    |      Sector    |\n"
	           "______|________________|__________________|_________________|________________|\n");


		for (i = 0; i < length; i++) {

			PrimerasLetrasMayuscula(list[i].name);
			PrimerasLetrasMayuscula(list[i].lastName);
			printPassenger(&list[i]);
		}
	}
	return retorno;
}

int pass_InformarPassengers (Passenger* list, int len){

	int retorno=-1;// Pointer NULL or len <0
	int opcionInformar;
	int order;
	int opcionSueldo;
	if (list!=NULL && len>=0 ) {
		retorno=-2; // Invalid opcion

		printPassengers(list, len);
		if(utn_getNumero(&opcionInformar,
				"\n0) Volver Menu anterior\n"
				"1) Listar Passengers por Apellido y Sector.\n"
				"2) Informar Sueldos.\n"
				""
				"\n\n==============================================================================\n\n"
				""
				"Opcion: ", "\nError, invalid opcion \n ", 0, 2, 0)==0 )
		{
			switch (opcionInformar)
			{
				case 1:
					if(utn_getNumero(&order, "\n1) Ordenar de la A a la Z\n"
							            	   "2) Ordenar de la Z a la A\n"
							            	   ""
							            	   "\n\n==============================================================================\n\n"
							            	   ""
							            	   "Opcion: ", "\nError, opcion invalida intentalo de nuevo\n", 1, 2, 0)==0)
					{
						sortPassengers(list, len, order);
						printPassengers(list, len);
						retorno=0; //OK
					}
					break;
				case 2:
					if(utn_getNumero(&opcionSueldo, "\n1) Total y Promedio de los salarios\n"
											 "2) Cuantos Passengers superan el salario promedio  \n"
							                 ""
							                 "\n\n==============================================================================\n\n"
							                 ""
							                 "Opcion: ", "\nError, opcion invalida intentalo de nuevo\n", 1, 2, 0)==0)
					{

						pass_checkPassengerSalary(list, len, opcionSueldo);
						retorno=0; //OK
					}

					break;
				case 0:
					retorno=1; // Back menu
					break;
			}
		}
	}

	return retorno;
}
int controller_InformarPassenger (Passenger* list, int t_clie)
{
	int retorno =-1;
	int infomarPassengers;

	if (list != NULL && t_clie) {

		if(pass_checkPassenger(list, t_clie) == 0)
		{
			pass_orderPassengersById(list, t_clie);

			infomarPassengers = pass_InformarPassengers(list, t_clie);

			if(infomarPassengers==0){
				printf("\n\t\tINFORMAR COMPLETADO\n\n");
			}
			else{
				if(infomarPassengers==-1){
					printf("\nError, lenth invalido o NULL pointer\n\n");
				}
			}
		}
	}
	else{
		printf("\n\tNo hay Passengers en el sistema para informar Passengers\n\n");
	}
	return retorno;

}
float pass_salaryPassengers (Passenger* list, int len){

	float salario=-1; // Pointer NULL or len < 0 or there is not space or no salary
	int i;
	if (list!=NULL && len>=0 && pass_checkPassenger(list, len) == 0) {

		for (i = 0; i < len; i++) {

			salario+=list[i].salary; // Return !=0 OK
		}
	}
	return salario;
}

float pass_promedyPassengers (Passenger* list, int len, float salario){

	float promedio=-1;// Pointer NULL or len < 0 or there is not space or no salary
	int contador=0;
	int i;
	if (list!=NULL && len>=0  && pass_checkPassenger(list, len) == 0 ) {

		for (i = 0; i < len; ++i) {
			contador++;
		}

		promedio=salario/contador; // !=0 OK
	}
	return promedio;
}



int pass_checkPassengerSalary (Passenger* list,int len, int order){

	int retorno=-1;// Pointer NULL or len and order <0 or there is not space
	float salario;
	float promedio;
	int i, contador;
	if (list!=NULL && len>=0 && pass_checkPassenger(list, len) == 0 ) {

		salario=pass_salaryPassengers(list, len);
		promedio=pass_promedyPassengers(list, len, salario);

		switch (order) {
			case 1:
				if(salario!=0 && promedio!=0)
				{
					printf("\nSalario Total: %.2f\n", salario);
					printf("\nSalario Promedio: %.2f\n", promedio);
					retorno=0; //OK
				}
				break;
			case 2:
				for (i = 0; i < len; ++i) {
					if (list[i].salary>= promedio ) {
						contador++;
						if(contador == 1){
							printf("_________________________________________________________________________\n");
						}
						printPassenger(&list[i]);
					}
				}

				printf("\nSalario Promedio: %.2f\n"
						"\nHay %d Passengers que superan el salario promedio\n", promedio, contador);
				break;
		}
	}

	return retorno;
}






