#include <stdio.h>

int CalcularFactorial (int numeroIngresado){

	int factorial;

	if(numeroIngresado==1){

		return 1;
	}
	else{

		factorial=numeroIngresado* CalcularFactorial (numeroIngresado-1);
	}

	return factorial;

}

int PedirNumero(char mensaje[]){

	int numero;

	printf("%s",mensaje);
	scanf("%d", &numero);

	while(numero<0 || numero>10){

		printf("ERROR, reingrese el numero entre el 1 y el 10");
		scanf("%d", &numero);
	}

	return numero;

}

