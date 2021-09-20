/*

 Marin Diego(1c)

 Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit ,
validando que las temperaturas ingresadas estén entre
el punto de congelación y ebullición del agua para cada tipo de escala.
Las validaciones se hacen en una biblioteca.
Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.
 =====================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Transformaciones.h"
#include "validaciones.h"

int main (void) {

	setbuf(stdout,NULL);


	PedirTemperaturaF("Ingrese temperatura en fahrenheit entre 32ºF y 211.3ºF: ");
	PedirTemperaturaC("Ingrese temperatura en celsius entre 1ºC y 99ºC: ");

	return EXIT_SUCCESS;
}
