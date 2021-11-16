/*
 * biblioteca.h
 *
 *  Created on: 12 sep. 2021
 *      Author: Usuario
 */

#ifndef FUNCIONES_STRING_H_
#define FUNCIONES_STRING_H_
#include <stdio.h>

float ValidacionTemperaturaFyC (float temperaturaF);
/// @param temperaturaC Recibe temperatura en Celsius
/// @return me devuelve la temperatura que no pase el rango minimo de congelacion y el maximo de ebullicion
int ValidacionTemperaturaCyF (float temperaturaC);
/// @param mensaje se le debe informar que no pase de de 0 y 100
void PedirTemperaturaC (char mensaje[]);
/// @param mensaje se le debe informar que no pase de de 0 y 210
void PedirTemperaturaF (char mensaje[]);






#endif /* FUNCIONES_STRING_H_ */
