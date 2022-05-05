/*
 ============================================================================
 Name        : Tp2.c
 Author      : Diego
 Version     : v1.01
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "ArrayPassenger.h"

#define t_pass 2000 // Change large for more Passenger

int main(void) {

	setbuf(stdout, NULL);

	Passenger arrayPassengers[t_pass];

	int opcion;
	int salir=1;

	pass_HardcodePassengers(arrayPassengers, t_pass); //Harcodear datos ACTIVAR funcion

	//initPassenger(arrayPassengers, t_pass);  //Hardcodear datos COMENTAR funcion


	printf( "Nombre: DIEGO MARIN 1(c)       \n"
			"Nro de TP:  2					\n"
			"Descripcion: A.B.M.I Passengers \n"
			"Semestre: 1                    \n");


	printf("\nEnjoy :,)\n\n");



	do {



			if(utn_getNumero(&opcion,
				    "\t\tPrograma de Passengers en C:\n\n"
				    "\t\t1) ALTA Pasajero\n\n"
					"\t\t2) MODIFICACIÓN Pasajero\n\n"
					"\t\t3) BAJA Pasajero\n\n"
					"\t\t4) INFORMAR Pasajero\n\n"

					"\t\t5) Salir\n"
					""
					"\n==============================================================================\n\n"
					"\t\tOpcion: ",
					"\nError, opcion invalida\n\n", 0, 5, INT_MAX)==0)
			{

				switch (opcion) {

				case 1:
					controller_AltaPassengers(arrayPassengers, t_pass);
					break;

				case 2:
					controller_ModificarPassengers(arrayPassengers, t_pass );
					break;

				case 3:
					controller_BajaPassengers(arrayPassengers, t_pass);
					break;

				case 4:
					controller_InformarPassenger (arrayPassengers, t_pass);
					break;

				case 5:

					printf("\nSalir Completado\n");
					system("pause");
					salir = 0;
					break;

				default:

					printf("\nOpcion Invalida\n");
					break;
				}
			}


		} while (salir);


	printf("\nAPLICACION CERRADA\n");

	return EXIT_SUCCESS;
}


