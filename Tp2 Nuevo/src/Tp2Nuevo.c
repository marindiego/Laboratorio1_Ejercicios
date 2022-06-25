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


int main(void) {

	setbuf(stdout, NULL);

	Passenger arrayPassengers[t_pass];
	TypePassenger arrayTypePassengers[t_typePass];
	FlyCode arrayFlyCodes[t_flyCodesPass];


	int opcion;
	int salir=1;

	initPassengers(arrayPassengers, t_pass);

	printf( "Nombre: DIEGO MARIN 1(c)       \n"
			"Nro de TP:  2					\n"
			"Descripcion: A.B.M.I Passengers \n"
			"Semestre: 1                    \n"
			""
			"\nEnjoy :,)\n\n");


	do {

		printfPassengerOptionsMenu();

			if(utn_getNumero(&opcion, "\t\tOpcion: ", "\nError, opcion invalida\n\n", 1, 6, INT_MAX)==0)
			{
				switch (opcion)
				{
					case 1:
						AltaPassengers(arrayPassengers, t_pass, arrayFlyCodes, t_flyCodesPass, arrayTypePassengers,t_typePass);
						break;
					case 2:
						ModificarPassengers(arrayPassengers, t_pass, arrayFlyCodes, t_flyCodesPass, arrayTypePassengers,t_typePass );
						break;
					case 3:
						BajaPassengers(arrayPassengers, t_pass, arrayFlyCodes, t_flyCodesPass, arrayTypePassengers,t_typePass);
						break;
					case 4:
						InformarPassenger (arrayPassengers, t_pass, arrayFlyCodes, t_flyCodesPass, arrayTypePassengers,t_typePass);
						break;
					case 5:
						AltaForzada(arrayPassengers, t_pass,arrayFlyCodes, t_flyCodesPass, arrayTypePassengers,t_typePass);
						break;
					case 6:
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


