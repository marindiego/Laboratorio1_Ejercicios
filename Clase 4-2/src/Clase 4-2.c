/*

 Marin Diego(1c)

 Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit ,
validando que las temperaturas ingresadas est�n entre
el punto de congelaci�n y ebullici�n del agua para cada tipo de escala.
Las validaciones se hacen en una biblioteca.
Las funciones de transformaci�n de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.
 =====================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Transformaciones.h"
#include "validaciones.h"

int main (void) {

	setbuf(stdout,NULL);


	PedirTemperaturaF("Ingrese temperatura en fahrenheit entre 32�F y 211.3�F: ");
	PedirTemperaturaC("Ingrese temperatura en celsius entre 1�C y 99�C: ");

	return EXIT_SUCCESS;
}
