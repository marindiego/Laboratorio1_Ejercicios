

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

