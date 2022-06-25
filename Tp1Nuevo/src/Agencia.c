/*
 * Agencia.c
 *
 *  Created on: 8 may. 2022
 *      Author: Usuario
 */

#include "Agencia.h"



int InformarOpcionesCostosAgencia (int porcentajeDescuento, int porcentajeAumento, char* agencia1, char* agencia2)
{
	int retorno = -1;

	if (porcentajeAumento > 0 && porcentajeDescuento > 0 ) {

		retorno = 0;
		//Mostrar lo que se va a calcular
		printf(
				"\nCalcular: \n"
				"\na) Tarjeta de débito (descuento %d porciento ) \n"
				"b) Tarjeta de crédito (interés %d porciento )  \n"
				"c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
				"d) Mostrar precio por km (precio unitario)\n"
				"e) Mostrar diferencia de precio ingresada (%s - %s)\n",
				porcentajeDescuento,
				porcentajeAumento,
				agencia1,
				agencia2);


		printf("\nTodos los costos calculados!!!\n\n");
	}
	return retorno;
}
int CalcularCostosAgencia (char* nombreAgencia,float precio, float kilometros, int porcentajeDescuento, int porcentajeAumento, float* descuento ,float* aumento ,float* convercionBitcoin, float* precioUnitario)
{
	int retorno = -1;

	if(	kilometros > 0
			&&
			precio > 0
			&&
			nombreAgencia != NULL
			&&
			porcentajeDescuento > 0
			&&
			porcentajeAumento > 0
			&&
			descuento != NULL
			&&
			aumento != NULL
			&&
			convercionBitcoin !=NULL
			&&
			precioUnitario !=NULL
	 )

	{
		if (
				!CalcularDescuento(precio, porcentajeDescuento, descuento)
				&&
				!CalcularAumento(precio, porcentajeAumento, aumento)
				&&
				!DePesosAbitcoin(precio, convercionBitcoin )
				&&
				!CalcularPrecioUnitario(precio, kilometros,precioUnitario)
		)
		{

			retorno = 0;
		}
	}

	return retorno;
}

int printfCostosAgencia(char* nombreAgencia,float precio, float descuento, float aumento, float convercionBitcoin, float precioUnitario )
{
	int retorno = -1;

	if (nombreAgencia != NULL
			&&
			precio > 0
			&&
			descuento > 0
			&&
			aumento > 0
			&&
			convercionBitcoin > 0
			&&
			precioUnitario > 0)
	{

		retorno = 0;


		printf(	"\nPrecio %s: $%0.2f\n"
				"Precio con tarjeta de débito: $ %0.2f\n"
				"Precio con tarjeta de crédito: $ %0.2f\n"
				"Precio pagando con bitcoin: %0.10f BTC\n"
				"Precio unitario: $ %0.2f\n\n",
				nombreAgencia,precio,
				descuento,
				aumento,
				convercionBitcoin,
				precioUnitario);
	}

	return retorno;
}

int HardcodearDatosAgenciasDeVuelo (char* nombreAgencia, float kilometros, float precio, float porcentajeDescuento, float porcentajeAumento )
{
	int retorno = -1;
	float descuento;
	float aumento;
	float convercionBTC;
	float precioUnitario;

	if (nombreAgencia != NULL
			&&
			precio > 0
			&&
			kilometros > 0)
	{

		// Funcion 3)

		if (!CalcularCostosAgencia(nombreAgencia, precio, kilometros, porcentajeDescuento, porcentajeAumento, &descuento, &aumento, &convercionBTC, &precioUnitario)) {

			// Funcion 4
			printfCostosAgencia(nombreAgencia, precio,  descuento, aumento, convercionBTC, precioUnitario);
			retorno = 0;
		}
	}

	return retorno;
}
