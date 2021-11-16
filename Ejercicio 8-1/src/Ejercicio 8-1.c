/*

 Marin Diego (1c)

 Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
 Crear una función que permita cargar los datos de un jugador y otra que los muestre.
 Una tercera función calculará el promedio de goles.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_funciones.h"

#define TAM 3

typedef struct{

	char nombreJugador[10];
	int goles;
	int partidos;
	float promedio;

}eJugador;

float CalcularPromedio_Jugador ( eJugador lista);
void CargarDatosjugador_Jugador (eJugador *ejugador, int tam );
void MostrarLista_Jugador (eJugador *lista, int tam);
void MostrarUnJugador_Jugador (eJugador unJugador);


int main(void) {

	setbuf(stdout, NULL);

	eJugador listaJugadores[TAM]=
			{{"Diego",5, 10, 0 },{"Maria", 6, 11, 0 },{"Carla", 29, 30, 0}};

	//CargarDatosjugador_Jugador(listaJugadores,TAM);

	MostrarLista_Jugador(listaJugadores, TAM);

	return EXIT_SUCCESS;
}




void CargarDatosjugador_Jugador (eJugador ejugador[], int tam ){

	for(int i=0; i<tam; i++){

		getString(ejugador[i].nombreJugador, "Player: ", sizeof(ejugador[i].nombreJugador));
		ejugador[i].goles=IngresarNumeroEntero("Goles: ", "ERROR\n", 0, 100);
		ejugador[i].partidos=IngresarNumeroEntero("Partidos: ", "ERROR \n", 0, 100);
		//ejugador[i].promedio=CalcularPromedio_Jugador(ejugador[i]);

	}
}
void MostrarUnJugador_Jugador (eJugador unJugador){

	printf("%4s |%8d | %9d | %10.2f \n", unJugador.nombreJugador, unJugador.goles, unJugador.partidos, unJugador.promedio);

}

void MostrarLista_Jugador (eJugador *lista, int tam){

	printf("Jugador    Goles   Partidos  Promedio  \n");

	for(int i=0; i<tam; i++){

		lista[i].promedio=CalcularPromedio_Jugador(lista[i]);
		MostrarUnJugador_Jugador(lista[i]);
	}
}
float CalcularPromedio_Jugador ( eJugador lista){

	float promedio;

	promedio = (float)lista.goles/lista.partidos;

	return promedio;
}
