/*
 * Empleado.h
 *
 *  Created on: 24 oct. 2021
 *      Author: Usuario
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct{

	int idEmpleado;
	char nombre[50];
	float sueldo;
	char puesto[50];
	int isEmpty;

} eEmpleado;

eEmpleado EMP_IngresarEmpleado (void);
int EMP_CargaEmpleados (eEmpleado lista[], int largo);
int EMP_MostrarUnEmpleado (eEmpleado unEmpleado);
int EMP_MostrarEmpleados (eEmpleado lista[], int largo);
int EMP_Inicializar_Empleados (eEmpleado lista[], int largo);
int EMP_ValidarString (char *stringPuesto);
int EMP_PrimerLetraMayusculaUnEmpleado (char nombreEmpleado []);
int EMP_OrdenaPuesto (eEmpleado *lista, int largo);
int EMP_MostrarPorPuesto (eEmpleado *lista, int largo, char *puesto);
int EMP_ContaPuestos (eEmpleado *lista, int largo, char *puesto, int *contadorPuestos);
int EMP_OrdenarEmpleadosMayorSueldo (eEmpleado *lista, int largo);
int EMP_CalcularPromedioEmpleados (eEmpleado *lista, int largoArray, float *pPromedioSueldo);

#endif /* EMPLEADO_H_ */
