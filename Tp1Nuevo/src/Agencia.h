/*
 * Agencia.h
 *
 *  Created on: 8 may. 2022
 *      Author: Usuario
 */

#ifndef AGENCIA_H_
#define AGENCIA_H_

#include "utn_funciones.h"



 // Funciones del Tp1 (Nuevo)
/// @param porcentajeDescuento
/// @param porcentajeAumento
/// @return -1 No se pudo usar la funcion - 0 Todo bien
int InformarOpcionesCostosAgencia (int porcentajeDescuento, int porcentajeAumento, char* agencia1, char* agencia2 );
/// @param nombreAgencia
/// @param precio
/// @param kilometros
/// @param porcentajeDescuento
/// @param porcentajeAumento
/// @return
int CalcularCostosAgencia (char* nombreAgencia,float precio, float kilometros, int porcentajeDescuento, int porcentajeAumento,  float* descuento ,float* aumento ,float* convercionBitcoin, float* precioUnitario);
/// @param nombreAgencia
/// @param precio
/// @param kilometros
/// @param descuento
/// @param aumento
/// @param convercionBitcoin
/// @param precioUnitario
/// @return  -1 No se pudo usar la funcion - 0 Todo bien
int printfCostosAgencia(char* nombreAgencia,float precio, float descuento, float aumento, float convercionBitcoin, float precioUnitario );
/// @param nombreAgencia
/// @param kilometros
/// @param precio
/// @param porcentajeDescuento
/// @param porcentajeAumento
/// @return -1 No se pudo usar la funcion - 0 Todo bien
int HardcodearDatosAgenciasDeVuelo (char* nombreAgencia, float kilometros, float precio, float porcentajeDescuento, float porcentajeAumento );

#endif /* AGENCIA_H_ */
