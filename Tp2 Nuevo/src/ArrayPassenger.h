/*
 * Passenger.h
 *
 *  Created on: 10 nov. 2021
 *      Author: Usuario
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "utn_funciones.h"
#include "ValidacionesGenericos.h"

#define t_pass 12
#define t_typePass 10
#define t_flyCodesPass 3

#define CARGADO 0
#define VACIO 1

#define ACTIVO 0
#define CANCELADO -1
#define DEMORADO 1


typedef struct{
	char flycode[10];//PK
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



/*	     ______________________________
 *		|                              |
 *      |  		FUNCIONES TP2   	   |
 *      |______________________________|
 */

/*___________________________________

			HARDCODE  FUNCIONES
_____________________________________
*/
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
/// @brief forced passenger check-in
///
/// @param arrayPassengersHardcode
/// @param len
/// @param listFlyCodeHardcode
/// @param len_flyCode
/// @param listTypePassHardcode
/// @param len_typePass
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int AltaForzada (Passenger* arrayPassengersHardcode, int len,FlyCode* arrayFlyCodes, int len_flyCode, TypePassenger* arrayTypePassengers, int len_typePass);
/*__________________________________

			SUB FUNCIONES
_____________________________________
*/
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isempty) in TRUE in all
 * position of the array
 * \param list Passenger* Pointer to array of Passengers
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initPassengers(Passenger* list, int len);
/** \brief find an Passenger by Id en returns the index position in array.
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return Return Passenger index position or (-1) if [Invalid length or NULL
pointer received or Passenger not found]
 *
 */
int findPassengerById(Passenger* list, int len,int id);
/** \brief  Return the Index position
 *
 * \param list Passenger*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - () if it found a free space
 *
 */
int pass_findEmptySpace (Passenger* list, int len);
/** \brief Asks a number
 *
 * \param mensaje char*
 * \return int Return (-1) if NULL masage - (0) if cancelled - (1) if continues
 *
 */
int pass_confirmDecision (char* mensaje);
/** \brief  Verify that there is at least one Passenger in the system
 *
 * \param list Passenger*
 * \param len int
 * \return int Return (-1) if it found a Passenger - (0) if it doesnt
 *
 */
int pass_checkPassenger (Passenger* list, int len);

//A.B.M

/*__________________________________

		    	ALTA
_____________________________________
*/
/** \brief add in a existing list of Passengers the values received as parameters
 * in the first passty position
 * \param list Passenger*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
*/
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[],float price,
		int  typePassenger, char flycode[],FlyCode* listFlyCode, int len_flyCode);
/// @brief Sub funcion to registrer a passenger into the list
///
/// @param list
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return -1 //NULL or len <0 - (1) invalid input data - 0 Ok
int pass_AltaPassengers(Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);
/// @brief Prints the possible messages returned by the function ( pass_AltaPassengers ).´
///
/// @param arrayPassengers
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return  int Return (-1) if Error [Invalid lengths or any NULL pointer ] - (0) if Ok
int AltaPassengers (Passenger* arrayPassengers, int len,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

/*__________________________________

	        	BAJA
____________________________________
*/
/** \brief Remove a Passenger by Id (put ispassty Flag in 1)
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a Passenger] - (0) if Ok
 *
 */
int removePassenger(Passenger* list, int len, int id);
/** \brief The main function that remove an Passenger with the call of other functions
 *
 * \param list Passenger*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or (-3) if it can't get a number or (-2) if can't
find a Passenger - (1) if the usuary does not want to removee the id - (0) if Ok
 *
 */
int pass_BajaPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);
/// @brief Prints the possible messages returned by the function ( pass_BajaPassengers ).
///
/// @param list
/// @param len
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return int Return (-1) if Error NULL pointer or any length < 0 - (0) if Ok
int BajaPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);


/*__________________________________

	      MODIFICACIONES
_____________________________________
*/

/** \brief  The main function that is responsible for modifying any field of an Passenger
 *
 * \param list Passenger*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or (-2) if Its an
  invalid opcion - (1) if the usuary does not want to change the Passenger  - (-3) Not found if - (0) if ok
 *
 */
int pass_ModificarPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);
/** \brief Resets a new value to an attribute of a passenger
 *
 * \param list Passenger*
 * \param int opcion
 * \return int return (-1) if Error [Invalid length or NULL pointer or Cancel Modification] or - (0) if ok
 *
 */
int pass_changePassengerSpace (Passenger* list,int opcion , int index,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);
/// @brief shows the flight codes already loaded in the code list and asks you to enter one,
/// then asks for a new flight status,
/// asks if you want to confirm the decision and reset a new flight status
///
/// @param listFlyCode
/// @param len_flyCode
/// @return int return (-1) if Error Pointer NULL or len <0 or (1) if Error, codigo de vuelo invalido - (2) if Error Opcion invalida - (3) if Cancel Modificacion - (0) if OK
int pass_ModificarEstadoVueloCodigoVuelo (FlyCode*listFlyCode,int len_flyCode);
/// @brief
///
/// @param list
/// @param t_clie
/// @return
int ModificarPassengers (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

//_________Getters__________

/// @brief Get a name through a pointer to the entity
///
/// @param this
/// @return int Return (-1) if Error getting a name - (0) if Ok
int passenger_getNameFromStdIn (Passenger* this);
/// @brief Get a lastname through a pointer to the entity
///
/// @param this
/// @return int Return (-1) if Error getting a lastname - (0) if Ok
int passenger_getLastNameFromStdIn (Passenger* this);
/// @brief  Get a price through a pointer to the entity
///
/// @param this
/// @return int Return (-1) if Error getting a price- (0) if Ok
int passenger_getPriceFromStdIn (Passenger* this);
/// @brief Get a flyCode through a pointer to the entity
///
/// @param this
/// @param listFlyCode
/// @param len_flyCode
/// @return int Return (-1) if Error this is NULL or listFlyCode is NULL or len <= 0 - (0) if Ok
int passenger_getFlyCodeFromStdIn(Passenger* this, FlyCode* listFlyCode, int len_flyCode);
/// @brief Get a TypePassenger through a pointer to the entity
///
/// @param this
/// @param listTypePass
/// @param len_typePass
/// @return int Return (-1) if Error (this) is NULL or (listTypePass) is NULL or len < 0 - (0) if Ok
int passenger_getTypePassengerFromStdIn (Passenger* this,TypePassenger* listTypePass, int len_typePass);
/// @brief load 1 passager into the list
///
/// @param list
/// @param len
/// @return int Return (-1) if Error Failed to get a passenger - (0) if Ok
int pass_getPassengerFromStdIn (Passenger* buffer,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

/* _______New_Setters__________
 *
*/
/// @brief Set a new name of the listPassenger
///
/// @param list
/// @param index
/// @return int retorno (-1) if it could do it - (0) if ok
int passengersetNewName (Passenger* list, int index );
/// @brief Set a new last name of the listPassenger
///
/// @param list
/// @param index
/// @return int retorno (-1) if it could do it - (0) if ok
int passenger_setNewLasName (Passenger* list, int index);
/// @brief Set a new price of the list for another one
///
/// @param list
/// @param index
/// @return int retorno (-1) if it could do it - (0) if ok
int passenger_setNewPrice (Passenger* list, int index);
/// @brief  Set a new flyCode of the listPassenger
///
/// @param list
/// @param index
/// @param listFlyCode
/// @param len_flyCode
/// @return int retorno (-1) if Error NULL pointer or inde - (0) if ok
int passenger_setNewFlyCode (Passenger* list, int index,FlyCode* listFlyCode, int len_flyCode );
/// @brief Set a new type passenger of the listPassenger
///
/// @param list
/// @param index
/// @param listTypePass
/// @param len_typePass
/// @return  int retorno (-1) if Error NULL pointer or inde - (0) if ok
int passenger_setNewTypePassenger (Passenger* list,int index,TypePassenger* listTypePass, int len_typePass);
/* ________Setters__________
 *
*/

/// @brief Sets the (id) to a list item
///
/// @param this
/// @param id
/// @return int Return (-1) if Cant set the id - (0) if Ok
int passenger_setId (Passenger* this, int id);
/// @brief Sets the (name) to a list item
///
/// @param this
/// @param name
/// @return int Return (-1) if Cant set the name - (0) if Ok
int passenger_setName (Passenger* this, char* name);
/// @brief Sets the (lastname) to a list item
///
/// @param this
/// @param lastName
/// @return int Return (-1) if Cant set the lastname - (0) if Ok
int passenger_setLastName (Passenger* this, char* lastName);
/// @brief  Sets the (price) to a list item
///
/// @param this
/// @param price
/// @return int Return (-1) if Cant set the price - (0) if Ok
int passenger_setPrice (Passenger* this, float price);
/// @brief Sets the (flyCode) to a list item
///
/// @param this
/// @param flycode
/// @param listFlyCode
/// @param len_flyCode
/// @return  int Return (-1) if Cant set the flyCode - (0) if Ok
int passenger_setFlyCode (Passenger* this, char* flycode, FlyCode* listFlyCode, int len_flyCode);
/// @brief  Sets the (TypePassenger) to a list item
///
/// @param this
/// @param typePassenger
/// @return int Return (-1) if Cant set the typePasenger - (0) if Ok
int passenger_setTypePassenger (Passenger* this, int typePassenger);
/// @brief  Resets a new flight status to an entered flight code.
///
/// @param flycode
/// @param listFlyCode
/// @param len_flyCode
/// @param statusFlight (0) - ACTIVO - (1) DEMORADO - (-1) Cancelado
/// @return int Return (-1) if no coicide el codigo ingresado con uno de la lista  pointer NULL or len < 0 or status Flight < 0- (0) if Ok
int passenger_setStatusFlightToFlyCode (char* flycode, FlyCode* listFlyCode, int len_flyCode,  int statusFlight);

/*__________________________________

	     INFORMAR
_____________________________________
*/

/// @brief
///
/// @param list
/// @param len
/// @return
int	pass_InformarPassengers (Passenger* list, int len,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);
/// @brief Prints the possible messages returned by the function ( pass_InformarPassengers ).
///
/// @param list
/// @param t_clie
int InformarPassenger (Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);

/*------------------------------------
 * 			Sort
 * -----------------------------------
 */
/** \brief Sort the elements in the array of Passengers, the argument order
indicate UP or DOWN order
 *
 * \param list Passenger*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortPassengers(Passenger* list, int len, int order);
/** \brief Sort Passengers by their Id
 *
 * \param list Passenger*
 * \param int opcion
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (o) if OK
 *
 */
int pass_sortPassengersById (Passenger* lista,int len);
/// @brief  Sort Passengers by their flyCode (always ACTIVE status)
///
/// @param lista
/// @param len
/// @param order order int [1] indicate UP - [0] indicate DOWN
/// @param listFlyCode
/// @param len_flycode
/// @return int Return (-1) if Error [Invalid length or NULL pointer] or (0) if ok
int pass_sortPassengersByCode (Passenger* lista, int len, int order, FlyCode* listFlyCode, int len_flycode);
/*
 * --------------------------------------
 * 			Mis Printf
 * ----------------------------------------
 */

/// @brief Main options menu
///
void printfPassengerOptionsMenu ();
/// @brief Sub menu modificar
///
void printfPassengerOptionsMenuModificar ();
/// @brief Cover of all lists
///
void pass_printCoverListPassengerListFlyCodeListTypePassenger ();
/// @brief print the content of Passengers array and ListFlyCode array and ListTypePass array
///
/// @param list
/// @param length
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return int return (-1) if No passanger load or any len < 0 or pointer NULL
int printPassengers(Passenger* list,int length, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass,int len_typePass);
/** \brief print the content of 1 Passenger
 *
 * \param list Passenger*
 * \return int
 *
 */
int printPassenger(Passenger* this,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass,int len_typePass,int* contadorFlyCode, int* contadorTypePassenger);
/// @brief print all available flight codes
///
/// @param listFlyCode
/// @param len_flyCode
/// @return 0 ok -1 wrong
int pass_printfFlyCodes (FlyCode* listFlyCode, int len_flyCode);
/// @brief print all available  type passenger
///
/// @param listTypePass
/// @param len_typePass
/// @return
int pass_prinfTypePassenger (TypePassenger* listTypePass, int len_typePass);
/// @brief Muestra Listados
///
void printfListados ();
/// @brief Main menu informar
///
void printfMenuInformar ();
/// @brief Sub menu informar
///
/// @param opcionInformar
/// @param listFlyCode
/// @param len_flyCode
/// @param listTypePass
/// @param len_typePass
/// @return  int Return (-1) if Error  NULL pointer or len < 0 - (0) if Ok
int printfSubMenuInformar (int opcionInformar,Passenger* list, int len, FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);
/// @brief Informar Listado
///
/// @return  int Return (-1) if Error  NULL pointer or len < 0 - (0) if Ok
int printfSubMenuInformarListar (Passenger* list, int len,FlyCode* listFlyCode, int len_flyCode, TypePassenger* listTypePass, int len_typePass);
/// @brief  Sub menu informar Precios
///
/// @param opcionInformar
/// @return
void printfSubMenuInformarPrice ();
/*___________________________________

	  	  Flight Cost
_____________________________________
*/
/** \brief  administers and reports everything related to the salary of an Passenger
 *
 * \param list Passenger*
 * \param int len
 * \return int (-1) if Error Pointer NULL or len and order <0 or there is not space or - (0) if ok
 */
int pass_checkPassengerPrice (Passenger* list,int len, int order);
/** \brief  Operate Passengers's salary
 *
 * \param list Passenger*
 * \param int len
 * \param inr order
 * \return int Return (-1) if Error [Invalid length or NULL pointer or No space] (0) if Ok
 */
float pass_pricePassengers (Passenger* list, int len);
/** \brief  Operate Passengers's salary
 *
 * \param list Passenger*
 * \param int len
 * \param int salario
 * \return int Return (-1) if Error [Invalid length or NULL pointer or No space] (0) if Ok
 */
float pass_promedyPassengers (Passenger* list, int len, float price);

#endif /* ARRAYPASSENGER_H_ */
