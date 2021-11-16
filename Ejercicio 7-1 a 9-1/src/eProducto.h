/*
 * eProducto.h
 *
 *  Created on: 29 oct. 2021
 *      Author: Usuario
 */

#ifndef EPRODUCTO_H_
#define EPRODUCTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "utn_funciones.h"

//Nacionalidad
#define EEUU 1
#define CHINA 2
#define OTRO 3

//Tipo
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCSESORIOS 4

//Estado
#define CARGADO 1
#define VACIO 0

typedef struct{

	int idProducto;
	char descripcion[50];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;

}eProducto;



eProducto APPLE_getProducto (void);
int APPLE_AltaProducto (eProducto lista[], int largo, int *pVereficarEspacio);
int APPLE_BuscarProductosDisponibles (eProducto lista[], int largo);
int APPLE_InicializarProducto (eProducto lista[], int largo );
int APPLE_MostrarUnProducto (eProducto unProducto);
int APPLE_MostrarProductos (eProducto lista[], int largo);
int APPLE_BajaProducto (eProducto lista[], int largo,int *pVerificarPuesto, int *pIdProductoBajado);
int APPLE_ModificarProducto (eProducto lista[], int largo, int *pVereficarId);
int APPLE_OrdenarProductosPorPrecio (eProducto lista[], int largo);
int APPLE_OrdenarProductosPorDescripcion (eProducto lista[], int largo);
int APPLE_MostrarProductosPorUnPrecio (eProducto lista[], int largo, float precioUnico, int *pPrecioDisponible);
int APPLE_MostrarProductosMasCaro (eProducto lista[], int largo);
int APPLE_TipoMasBarato (eProducto lista[], int largo, int tipoDeProducto, eProducto *unProducto );
int APPLE_MostrarNacionalidad (eProducto lista[], int largo, int nacionalidad);
int APPLE_MostrarTipoPrecioEspecifico (eProducto lista[], int largo, int tipoProducto, float precio);
int APPLE_MostrarTipoMasCaro (eProducto lista[], int largo, int tipo);

#endif /* EPRODUCTO_H_ */
