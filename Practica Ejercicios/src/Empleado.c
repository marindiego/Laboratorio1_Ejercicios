/*
 * Empleado.c
 *
 *  Created on: 24 oct. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "utn_funciones.h"
#include "Empleado.h"

eEmpleado EMP_IngresarEmpleado (void){

	setbuf(stdout, NULL);

	eEmpleado dato;
	int error=1;
	int contador=0;

	do{

		if( contador==0 && utn_getNumero(&dato.idEmpleado, "ID: ", "ERROR \n", 1, 100, 1)==0){

			contador++;
		}

		if( contador==1 && utn_getCharNombre(dato.nombre, "Nombre: ", "ERROR \n", 1, 10)==0){

			contador++;
		}

		if(contador==2 && utn_getFloat(&dato.sueldo, "Sueldo: ", "ERROR \n ",  0, 999.999, 1)==0){

			contador++;
		}

		if(contador==3 &&
				utn_getCharNombre(dato.puesto, " (Programador / Analista / Tester): ", "ERROR \n ", 1, 12)==0 &&
				EMP_ValidarString(dato.puesto)==0)
		{

			dato.isEmpty=0;
			error=0;
		}

	}while(error==1);



	return dato;
}

int EMP_CargaEmpleados (eEmpleado lista[], int largo){

	int retorno=-1;
	int i;

	if(lista!=NULL && largo>0){

		retorno=0;

		for(i=0; i<largo ; i++ ){

			lista[i]=EMP_IngresarEmpleado();
		}
	}

	return retorno;
}

int EMP_MostrarUnEmpleado (eEmpleado unEmpleado){

	printf("  %5d |  %15s  |  %1.3f  |  %-8s \n ", unEmpleado.idEmpleado, unEmpleado.nombre, unEmpleado.sueldo, unEmpleado.puesto );

	return 0;
}

int EMP_MostrarEmpleados (eEmpleado lista[], int largo){

	int retorno=-1;

	if(lista!=NULL && largo>0){

		printf("\n    idEmpleado       Nombre      Sueldo     Puesto\n");

		for(int i=0; i<largo; i++){

			if(	lista[i].isEmpty==0){

				EMP_PrimerLetraMayusculaUnEmpleado(lista[i].nombre);
				EMP_MostrarUnEmpleado(lista[i]);
			}
		}

		retorno=0;
	}

	return retorno;
}
int EMP_Inicializar_Empleados  (eEmpleado lista[], int largo){

	int retorno=-1;
	int i;

	if(lista!=NULL && largo>0){

		for(i=0; i<largo ; i++ ){

			lista[i].isEmpty=1;
		}

		retorno=0;
	}

	return retorno;
}

int EMP_ValidarString ( char *stringPuesto){

	int retorno=1;

	if(stringPuesto!=NULL ){

		strlwr(stringPuesto);

		stringPuesto[0]=toupper(stringPuesto[0]);

		if(strcmp(stringPuesto, "Analista")==0 || strcmp(stringPuesto, "Programador")==0 || strcmp(stringPuesto, "Tester")==0 ){

			retorno=0;
		}
	}

	return retorno;
}

int EMP_PrimerLetraMayusculaUnEmpleado (char nombreEmpleado []){

	strlwr(nombreEmpleado);

	nombreEmpleado[0]=toupper(nombreEmpleado[0]);

	for(int i=0; i< strlen(nombreEmpleado) && nombreEmpleado[i]!='\0'; i++){

		if(isspace(nombreEmpleado[i])){

			nombreEmpleado[i+1]=toupper(nombreEmpleado[i+1]);
		}

	}

	return 0;
}
int EMP_OrdenaPuesto (eEmpleado *lista, int largo){

	int flagSwap;
	int i;
	int contador=0;
	int retorno;

	eEmpleado auxString;

	if(lista!=NULL && largo>=0){

		do{
			flagSwap=0;
			for(i=0; i<largo-1 ; i++){

				contador++;
				if(strcmp(lista[i].puesto, lista[i+1].puesto)>0){

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

int EMP_MostrarPorPuesto (eEmpleado *lista, int largo, char *puesto){

	int retorno=-1;

	if(lista!=NULL && puesto!=NULL && largo>0){

		for(int i=0; i<largo; i++){

			if(strcmp(lista[i].puesto, puesto)==0){

				EMP_MostrarUnEmpleado(lista[i]);
			}
		}

		retorno=0;
	}

	return retorno;
}
int EMP_ContaPuestos (eEmpleado *lista, int largo, char *puesto, int *contadorPuestos){

	int retorno=-1;
	int contarP=0;

	if(lista!=NULL && puesto!=NULL && contadorPuestos!=NULL && largo>0){

		for(int i=0; i<largo; i++){

			if(strcmp(lista[i].puesto, puesto)==0){

				contarP++;
			}
		}
		*contadorPuestos=contarP;
		retorno=0;
	}

	return retorno;
}
int EMP_CargarMostrarEmpleadosMayorSueldo (eEmpleado *lista, int largo){

	int retorno=-1;
	int i;
	int contador=0;
	int flagSwap;
	eEmpleado auxPay;

	if(lista!=NULL &&  largo>0){

		do{
			flagSwap=0;

			for(i=0; i<largo-1 ; i++){

				contador++;

				if(lista[i].sueldo < lista[i+1].sueldo){

					flagSwap=1;
					auxPay=lista[i];
					lista[i]=lista[i+1];
					lista[i+1]=auxPay;
				}
			}

		}while(flagSwap);


		retorno=contador;
	}

	return retorno;
}



