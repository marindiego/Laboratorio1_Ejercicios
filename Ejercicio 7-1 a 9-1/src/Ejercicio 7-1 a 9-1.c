
#include "eProducto.h"
/*

	Ejercicio 8-2:

	Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:

	idProducto (numerico)
	descripcion (alfanumérico)
	nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
	tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
	precio (numérico decimal)

	Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:

	ALTA producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
	BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
	MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
	LISTADO Productos.
	LISTADO ordenado por precio.
	LISTADO ordenado por descripción.

	El/los  productos más caros.
	Los productos que cuestan 700
	Precio promedio por tipo de producto.
	De los Iphone el más barato
	Los productos "MADE IN CHINA"
	Las MAC que cuestan más de 700 USD
	El/Los Accesorios más caros

 */
#define TAM 6 //Tamaño Array

int main(void) {

	setbuf(stdout, NULL);

	eProducto tipoMasBarato;

	eProducto listaProducto[TAM]=
			{{0,"",0,0,0,CARGADO},
			{1001,"Cargador",CHINA,ACCSESORIOS,3.000,CARGADO},
			{1002,"IPadProMax",CHINA, IPHONE, 2.000,CARGADO},
			{1003,"Cargador", CHINA, ACCSESORIOS, 3.000, CARGADO},
			{1004,"Cargador",EEUU,ACCSESORIOS, 800.00, CARGADO }};

	int opcion;
	char preguntar[10];
	int salirCarga=0;
	int vereficarEspacio;
	int vereficarBajaProducto;
	int IdProductoBajado;
	int vereficarID;
	int iteracionesPrecio;
	int iteracionesDescripcion;
	int precioDisponible;

	// i=1 no i=0 por un Bug en la Carga de Datos


	APPLE_InicializarProducto(listaProducto, TAM);

	do {


		printf("1) ALTA producto\n"
				"2) BAJA Producto\n"
				"3) MODIFICACIÓN Producto\n"
				"4) LISTADO Productos\n"
				"5) LISTADO ordenado por precio\n"
				"7) El/los  productos más caros\n"
				"8) Los productos que cuestan 700\n"
				"9) Precio promedio por tipo de producto\n"
				"10) De los Iphone el más barato\n"
				"11) Los productos MADE IN CHINA\n"
				"12) Las MAC que cuestan más de 700 USD\n"
				"13) El/Los Accesorios más caros\n14) Salir\n");

		printf("\n=================================================\n\n");

		if(utn_getNumero(&opcion, "Opcion: ", "\nError, opcion invalida\n", 0, 15, 1)==0){

			switch (opcion) {
			case 1:

				if(APPLE_AltaProducto(listaProducto, TAM, &vereficarEspacio)==0){

					if (vereficarEspacio==1) {

						printf("\nALTA COMPLETADO\n");

					}
					else{

						printf("\nESPACIO NO DISPONIBLE\n");
					}
				}
				break;

			case 2:

				if(APPLE_BajaProducto(listaProducto, TAM, &vereficarBajaProducto, &IdProductoBajado)==0){

					if (vereficarBajaProducto==1) {

						printf("\nID BAJADO: %d\n\n", IdProductoBajado);
					}
					else{

						if(vereficarBajaProducto==0){

							printf("\nNO EXISTE EL ID O FUE ELIMINADO \n\n");
						}
						else{

							printf("\nBAJA CANCELADA\n\n");
						}
					}
				}
				break;

			case 3:

				if(APPLE_ModificarProducto(listaProducto, TAM, &vereficarID)==0){

					if(vereficarID==1){

						printf("\nMODIFICAR PRODUCTO CONFIRMADO\n\n");
					}
					else{

						if(vereficarID==0){

							printf("\nNO EXISTE EL ID O FUE ELIMINADO \n\n");
						}
						else{

							printf("\nMODIFICACION CANCELADA\n\n");
						}
					}
				}

				break;

			case 4:

				APPLE_MostrarProductos(listaProducto, TAM);

				break;

			case 5:

				iteracionesPrecio=APPLE_OrdenarProductosPorPrecio(listaProducto, TAM);

				if(iteracionesPrecio>0){

					APPLE_MostrarProductos(listaProducto, TAM);
					printf("\nORDENAMIENTO PRECIO EXITOSO\n");

					printf("[ITERACIONES]: %d\n", iteracionesPrecio);
				}
				else{

					printf("\nOCURRIO UN ERROR, VERIFICA QUE CADA PRODUCTO ESTE CARGADO CORRECTAMENTE\n");
				}

				break;

			case 6:

				iteracionesDescripcion=APPLE_OrdenarProductosPorDescripcion(listaProducto, TAM);

				if(iteracionesDescripcion>0){

					APPLE_MostrarProductos(listaProducto, TAM);
					printf("\nORDENAMIENTO DESCRIPCION EXITOSO\n");

					printf("[ITERACIONES]: %d\n", iteracionesDescripcion);
				}
				else{

					printf("\nOCURRIO UN ERROR, VERIFICA QUE CADA PRODUCTO ESTE CARGADO CORRECTAMENTE\n");
				}

				break;

			case 7:

				if (APPLE_MostrarProductosMasCaro(listaProducto, TAM)==0) {

					printf("\nMOSTRAR PRODUCTO EXITOSO\n");
				}
				else{

					printf("\nOCURRIO UN ERROR, VERIFICA QUE CADA PRODUCTO ESTE CARGADO CORRECTAMENTE\n");
				}


				break;

			case 8:

				if(APPLE_MostrarProductosPorUnPrecio(listaProducto, TAM, 700.00, &precioDisponible)==0){

					if(precioDisponible>0){

						printf("\nMOSTRAR PRODUCTOS EXITOSO\n");
					}
					else{
						printf("\nNO HAY PRODUCTOS CON ESE PRECIO\n");
					}
				}
				else{

					printf("\nOCURRIO UN ERROR, VERIFICA QUE CADA PRODUCTO ESTE CARGADO CORRECTAMENTE\n");
				}

				break;

			case 9:

				break;

			case 10:

				if(APPLE_TipoMasBarato(listaProducto, TAM, IPHONE, &tipoMasBarato)==0){

					APPLE_MostrarUnProducto(tipoMasBarato);

					printf("\nMOSTRAR PRODUCTO EXITOSO\n");
				}
				else{

					printf("\nOCURRIO UN ERROR, VERIFICA QUE CADA PRODUCTO ESTE CARGADO CORRECTAMENTE\n");
				}

				break;

			case 11:

				if (APPLE_MostrarNacionalidad(listaProducto, TAM, CHINA)==0) {

					printf("\nMOSTRAR PRODUCTO EXITOSO\n");
				}
				else{

					printf("\nOCURRIO UN ERROR, VERIFICA QUE CADA PRODUCTO ESTE CARGADO CORRECTAMENTE\n");
				}
				break;

			case 12:

				if (APPLE_MostrarTipoPrecioEspecifico(listaProducto, TAM, MAC, 700.00)==0) {

					printf("\nMOSTRAR PRODUCTO EXITOSO\n");
				}
				else{

					printf("\nOCURRIO UN ERROR, VERIFICA QUE CADA PRODUCTO ESTE CARGADO CORRECTAMENTE\n");
				}
				break;

			case 13:

				if (APPLE_MostrarTipoMasCaro(listaProducto, TAM, ACCSESORIOS)==0) {

					printf("\nMOSTRAR PRODUCTO EXITOSO\n");
				}
				else{

					printf("\nOCURRIO UN ERROR, VERIFICA QUE CADA PRODUCTO ESTE CARGADO CORRECTAMENTE\n");
				}

				break;

			case 14:

				printf("\nSalir Completado\n");
				salirCarga=1;
				system("pause");
				break;

			default:

				printf("\nOpcion Invalida\n");

				break;
			}
		}
		else{

			printf("\nError \n");
		}

		if(salirCarga==0 && utn_getCharNombre(preguntar, "\nCualquier ingreso distinto de 'si' sera tomado como no. \nDesea continuar? : ", "\nERROR, INTENTA DE NUEVO \n", 10, 50)==0){

			continue;
		}

	} while ( salirCarga==0 && strcmp(preguntar, "si" )==0);

	printf("\nAPLICACION CERRADA\n");

	return EXIT_SUCCESS;
}



