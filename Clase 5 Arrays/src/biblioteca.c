#include <stdio.h>
#include "funciones_matematicas.h"
#include <windows.h>

float ValidacionTemperaturaFyC (float temperaturaF){


	while(temperaturaF<=0 || temperaturaF>=211 ){

		printf("Error, reingrese una temperatura en fahrenheit entre 32�F y 211.3�F: ");
		scanf("%f", &temperaturaF);
	}

	return temperaturaF;

}
int ValidacionTemperaturaCyF (float temperaturaC){


	while(temperaturaC<=0 || temperaturaC>=100 ){

		printf("Error, reingrese una temperatura en celsius entre 1�C y 99�C: ");
		scanf("%f", &temperaturaC);
	}

	return temperaturaC;

}
void PedirTemperaturaF (char mensaje[]){

	float temperaturaF;
	float gradosFaC;
	float temperaturaFvalida;

	printf("%s", mensaje);
	scanf("%f", &temperaturaF);

	temperaturaFvalida=ValidacionTemperaturaFyC (temperaturaF);

	gradosFaC=(temperaturaF-32.00)*0.556;

	printf("%.2f �F son %.2f �C centigrados.\n", temperaturaFvalida,gradosFaC);


}

void PedirTemperaturaC (char mensaje[]){

	int temperaturaC;
    int gradosCaF;
	int temperaturaCvalida;

	printf("%s", mensaje);
	scanf("%d", &temperaturaC);

	temperaturaCvalida=ValidacionTemperaturaCyF (temperaturaC);

	gradosCaF=(temperaturaC*9/5)+32;

	printf("%d �C son %d �F centigrados.\n", temperaturaCvalida,gradosCaF);

}


