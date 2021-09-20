/*
 * validaciones.c
 *
 *  Created on: 17 sep. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include "Transformaciones.h"

float ValidacionTemperaturaFyC (float temperaturaF){


	while(temperaturaF<=0 || temperaturaF>=211 ){

		printf("Error, reingrese una temperatura en fahrenheit entre 32ºF y 211.3ºF: ");
		scanf("%f", &temperaturaF);
	}

	return temperaturaF;

}
int ValidacionTemperaturaCyF (float temperaturaC){


	while(temperaturaC<=0 || temperaturaC>=100 ){

		printf("Error, reingrese una temperatura en celsius entre 1ºC y 99ºC: ");
		scanf("%f", &temperaturaC);
	}

	return temperaturaC;

}


