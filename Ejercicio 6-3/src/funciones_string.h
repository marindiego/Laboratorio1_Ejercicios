/*
 * biblioteca.h
 *
 *  Created on: 12 sep. 2021
 *      Author: Usuario
 */

#ifndef FUNCIONES_STRING_H_
#define FUNCIONES_STRING_H_
#include <stdio.h>

int myGets(char* cadena,int tam);
int myGetsChar( char *buffer, int tamMax);
int getInt(int* pResultado);
int getChar(char* pResultado, int tam);
int esNumerica(char* cadena);
int esTextoBasico(char* cadena);
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos);
int utn_getCharNombre(char* pResultado, char* mensaje,char* mensajeError, int reintentos, int tamMax);
int utn_getFloat(float* pResultado, char* mensaje,char* mensajeError, float minimo, float maximo, int reintentos);
int PrimerasLetrasMayuscula(char*mensaje);
int ConcatenarNombreYApellido(char*nombre,char*apellido,char*nombreCompleto,int tam);
int getFloat(float* pResultado);
int validarFloat (char *stringRecibido);



#endif /* FUNCIONES_STRING_H_ */
