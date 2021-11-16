/*


Marin diego (1c)

 Realizar un programa que desde el main llame o invoque a la función que muestre el Menú del punto anterior.
 Utilizar funciones y bibliotecas.

 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones_matematicas.h"

int main(void) {

	setbuf(stdout,NULL);

	int cantidadVectores;

	cantidadVectores=IngresarNumeroEntero(" Cantidad Maxima del Array: ", "Reingrese un entero: ");

	int listaEnteros[cantidadVectores-1];

	MenuEnteros(listaEnteros, cantidadVectores);


	return EXIT_SUCCESS;
}
