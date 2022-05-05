/*
 * Passenger.h
 *
 *  Created on: 10 nov. 2021
 *      Author: Usuario
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_


#include "utn_funciones.h"

#define CARGADO 0
#define VACIO 1

#define ACTIVO 0
#define ESPERA 1

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}Passenger;

typedef struct{

	int idPassenger;
	char descripcionPasenger [10];
}TypePassenger;


/*
 *
 *  Funciones que pide el tp
 * _________________________________________
 */

/** \brief To indicate that all position in the array are passty,
 * this function put the flag (ispassty) in TRUE in all
 * position of the array
 * \param list Passenger* Pointer to array of Passengers
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initPassengers(Passenger* list, int len);
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
int addPassenger(Passenger* list, int len, int id, char name[],
char lastName[],float salary,int sector);

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
/** \brief print the content of Passengers array
 *
 * \param list Passenger*
 * \param length int
 * \return int
 *
 */
int printPassengers(Passenger* list, int length);




/*	     ______________________________
 *		|                              |
 *      |  MIS FUNCIONES PARA EL TP2   |
 *      |______________________________|
 */

//____ALTA FUNCIONES_______

int pass_AltaPassengers(Passenger* list, int len);
/// @param arrayPassengers
/// @param t_pass
/// @return
int controller_AltaPassengers (Passenger* arrayPassengers, int t_pass);
/** \brief The main function that remove an Passenger with the call of other functions
 *
 * \param list Passenger*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or (-2) if can't
find a Passenger - (1) if the usuary does not want to removee the id - (0) if Ok
 *
 */
//____BAJA FUNCIONES__________
int pass_BajaPassengers (Passenger* list, int len);
/// @brief
///
/// @param list
/// @param t_passl
/// @return
int controller_BajaPassengers (Passenger* list, int t_pass);

//____MODIFICACIONES FUNCIONES_____
/** \brief  The main function that is responsible for modifying any field of an Passenger
 *
 * \param list Passenger*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or (-2) if Its an
  invalid opcion - (1) if the usuary does not want to change the Passenger  - (-3) Not found if - (0) if ok
 *
 */
int pass_ModificarPassengers (Passenger* list, int len);
/// @brief
///
/// @param list
/// @param t_clie
/// @return
int controller_ModificarPassengers (Passenger* list, int t_clie);
/** \brief Modify any field in the Passenger structure that was loaded before
 *
 * \param list Passenger*
 * \param int opcion
 * \return int Index (-1) if Error [Invalid length or NULL pointer or Cancel Modification] or - (0) if ok
 *
 */
int pass_changePassengerspace (Passenger* list,int opcion , int index);

// Setters
/// @brief Set the name of the list for another one
///
/// @param list
/// @param index
/// @return int retorno (o) if it could do it - (0) if it doesnt
int setNewName (Passenger* list, int index );
/// @brief Set the last name of the list for another one
///
/// @param list
/// @param index
/// @return int retorno (o) if it could do it - (0) if it doesnt
int setNewLasName (Passenger* list, int index);
/// @brief Set the salary of the list for another one
///
/// @param list
/// @param index
/// @return int retorno (o) if it could do it - (0) if it doesnt
int setNewWage (Passenger* list, int index);
/// @brief Set the sector of the list for another one
///
/// @param list
/// @param index
/// @return int retorno (o) if it could do it - (0) if it doesnt
int setNewSector (Passenger* list, int index);

//____INFORMAR FUNCIONES_____

/// @brief
///
/// @param list
/// @param len
/// @return
int	pass_InformarPassengers (Passenger* list, int len);
/// @brief
///
/// @param list
/// @param t_clie
int controller_InformarPassenger (Passenger* list, int t_clie);


/*__________________________________

			SUB FUNCIONES
_____________________________________
*/
/** \brief  Return the Index position
 *
 * \param list Passenger*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - () if it found a free space
 *
 */
int pass_findEmptySpace (Passenger* list, int len);
/** \brief  asks for passage by reference 0 if it continues 1 if it cancels
 *
 * \param mensaje char*
 * \return int Return (-1) if cancel - (0) if continue
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

/** \brief Load 10 Passengers sequentially or if you want adding another Passenger will load in the array
 *
 * \param list Passenger*
 * \param int Passengers
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or (0) if ok
 *
 */
int pass_HardcodePassengers (Passenger* list, int Passengers);
/** \brief Order Passengers by their Id
 *
 * \param list Passenger*
 * \param int opcion
 * \return int Return (-1) if Error [Invalid length or NULL pointer] or how many iterations the function did it
 *
 */
int pass_orderPassengersById (Passenger* lista,int len);
/** \brief  administers and reports everything related to the salary of an Passenger
 *
 * \param list Passenger*
 * \param int len
 * \return int (-1) if Error Pointer NULL or len and order <0 or there is not space or - (0) if ok
 */
int pass_checkPassengersalary (Passenger* list,int len, int order);
/** \brief  Operate Passengers's salary
 *
 * \param list Passenger*
 * \param int len
 * \param inr order
 * \return int Return (-1) if Error [Invalid length or NULL pointer or No space] (0) if Ok
 */
float pass_salaryPassengers (Passenger* list, int len);
/** \brief  Operate Passengers's salary
 *
 * \param list Passenger*
 * \param int len
 * \param int salario
 * \return int Return (-1) if Error [Invalid length or NULL pointer or No space] (0) if Ok
 */
float pass_promedyPassengers (Passenger* list, int len, float salario);
/** \brief print the content of 1 Passenger
 *
 * \param list Passenger*
 * \return int
 *
 */
int printPassenger(Passenger* list);

#endif /* ARRAYPASSENGER_H_ */
