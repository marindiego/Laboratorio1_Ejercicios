/*


 Marin Diego (1c)

 Armar un Menú de Opciones con las siguientes opciones
1-Inicializar
2-Cargar
3-Mostrar
4-Calcular Promedio
5-Ordenar
Al ingresar a cada opción del menú deberá imprimir en pantalla el nombre del mismo.
Ej: Si se presiona la opción 1 mostrar por pantalla “Ud. ha seleccionado lo opción 1-Inicializar”

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	int opcion;

	do{
		printf("1-Inicializar\n 2-Cargar \n 3-Mostrar\n 4-Calcular Promedio \n 5-Ordenar \n 6-Salir \n");

		printf("\n Ingrese una opcion 1-2-3-4-5-6: ");
		scanf("%d", &opcion);

		switch(opcion){

		case 1:
			printf("Ud. ha seleccionado lo opción 1-Inicializar \n");
			system("pause");
			system("cls");
			break;

		case 2:
			printf("“Ud. ha seleccionado lo opción 2-Cargar \n");
			system("pause");
			system("cls");
			break;

		case 3:
			printf("“Ud. ha seleccionado lo opción 3-Mostrar \n");
			system("pause");
			system("cls");
			break;

		case 4:
			printf("“Ud. ha seleccionado lo opción 4-Calcular Promedio \n");
			system("pause");
			system("cls");
			break;

		case 5:
			printf("“Ud. ha seleccionado lo opción 5-Ordenar \n");
			system("pause");
			system("cls");
			break;

		case 6:
			printf("(---| ** Gracias por Operar ** |---)");
			system("pause");
			system("cls");
			break;
		}


	}while(opcion!=6);




	return EXIT_SUCCESS;
}
