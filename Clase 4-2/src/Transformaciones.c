#include <stdio.h>
#include "validaciones.h"


void PedirTemperaturaF (char mensaje[]){

	float temperaturaF;
	float gradosFaC;
	float temperaturaFvalida;

	printf("%s", mensaje);
	scanf("%f", &temperaturaF);

	temperaturaFvalida=ValidacionTemperaturaFyC (temperaturaF);

	gradosFaC=(temperaturaF-32.00)*0.556;

	printf("%.2f °F son %.2f °C centigrados.\n", temperaturaFvalida,gradosFaC);


}

void PedirTemperaturaC (char mensaje[]){

	int temperaturaC;
    int gradosCaF;
	int temperaturaCvalida;

	printf("%s", mensaje);
	scanf("%d", &temperaturaC);

	temperaturaCvalida=ValidacionTemperaturaCyF (temperaturaC);

	gradosCaF=(temperaturaC*9/5)+32;

	printf("%d °C son %d °F centigrados.\n", temperaturaCvalida,gradosCaF);

}
