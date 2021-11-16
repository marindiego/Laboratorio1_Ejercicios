
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "utn_funciones.h"
#include "Empleado.h"
/*
 	Marin Diego (1c)

 	Crear la estructura empleado con idEmpleado, nombre, sueldo y puesto
 	(programador,analista, tester).

	Crear un menu con las siguientes opciones:
	1. Cargar empleados. Carga secuencial.
	2. Mostrar empleados. Ordenados por puesto.
	3. Mostrar solo los empleados analistas.
	4. Mostrar cuantos empleados tester hay.
	5. Mostrar los datos de los empleados analistas con mayor sueldo
	6.Calcular Promedio Empleados
 */

#define TAM 5

int main(void) {

	setbuf(stdout, NULL);

	//EMP_Inicializar_Empleados(listaEmpleados, TAM); Carga Aleatoria

	int opcion;
	int contadorTesters=0, contadorAnalistas=0;
	float promedioSueldoEmpleados;

	eEmpleado listaEmpleados[TAM]=
	{{1,"Diego",150.000,"Programador",0},{2,"Jordeany",10.000,"Analista", 0},{3,"Maria", 100.000,"Tester",0}, {4,"German", 50.000,"Analista",0}, {5,"Pedro",89.000,"Analista",0}};

	do{
		printf("\n1 Cargar empleados \n2 .Mostrar empleados\n3. Mostrar Analistas\n4. Contar Tester \n5. Mostrar Analistas Mayor Sueldo \n6. Calcular Promedio Empleados \n10. Salir \n");

		utn_getNumero(&opcion, "Opcion: ", "Error \n", 0, 11, 1);

		switch(opcion){

			case 1
			:
				EMP_CargaEmpleados(listaEmpleados, TAM);
				break;
			case 2:

				EMP_OrdenaPuesto(listaEmpleados, TAM);
				EMP_MostrarEmpleados(listaEmpleados, TAM);
				break;

			case 3:

				EMP_MostrarPorPuesto(listaEmpleados, TAM, "Analista");
				break;

			case 4:

				if(EMP_ContaPuestos(listaEmpleados, TAM, "Tester", &contadorTesters)==0 && contadorTesters!=0){

					EMP_MostrarPorPuesto(listaEmpleados, TAM, "Tester");
					printf("\nTester: %d \n", contadorTesters);
				}
				else{

					printf("\nNo Tester\n");
				}

				break;
			case 5:

				EMP_OrdenarEmpleadosMayorSueldo(listaEmpleados, TAM);
				EMP_MostrarPorPuesto(listaEmpleados, TAM, "Analista");

				if(EMP_ContaPuestos(listaEmpleados, TAM, "Analista", &contadorAnalistas)==0 && contadorAnalistas!=0){

					printf("\nAnalistas: %d \n", contadorAnalistas);
				}
				else{

					printf("\nNo Analistas\n");
				}

				break;

			case 6:

				if(EMP_CalcularPromedioEmpleados(listaEmpleados, TAM, &promedioSueldoEmpleados)==0 && promedioSueldoEmpleados!=0){

					printf("Sueldo Promedio Empleados %.3f", promedioSueldoEmpleados);
				}


				break;

			case 10:
				printf("Salir Completado");
				system("pause");
				break;
		}


	}while(opcion!=10);




	return EXIT_SUCCESS;
}





