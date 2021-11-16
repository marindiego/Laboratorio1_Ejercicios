/*
 ============================================================================
 Name        : Clase.c
 Author      : DIego
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "utn_funciones.h"

int main(void) {

	//Anidamiento de estructuras
	typedef struct{

		int dia;
		int mes;
		int anio;

	}eFecha;

	typedef struct{

		int id;
		char descripcion[50];
		eFecha fechaElaboracion;
		eFecha fechaCompra;

	}eProducto;

	eProducto miProducto={100,"Coca cola", {10,9,2021}};

	printf("%d %s  %d/%d/%d", miProducto.id, miProducto.descripcion, miProducto.fechaElaboracion.dia,
			miProducto.fechaElaboracion.mes, miProducto.fechaElaboracion.anio);

	return EXIT_SUCCESS;
}
