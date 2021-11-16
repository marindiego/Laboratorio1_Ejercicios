/*
 * eProducto.c
 *
 *  Created on: 29 oct. 2021
 *      Author: Usuario
 */

#include "eProducto.h"


eProducto APPLE_getProducto (void){

	setbuf(stdout, NULL);

	eProducto dato;
	int error=1;
	int contador=0;

	do{

		if( contador==0 && utn_getNumero(&dato.idProducto, "ID: ", "ERROR \n", 1, 10000, 1)==0){

			contador++;
		}

		if( contador==1 && utn_getCharNombre(dato.descripcion, "Descripcion: ",  "ERROR \n", 1, 50)==0){

			contador++;
		}

		if(contador==2 && utn_getNumero(&dato.nacionalidad, "1 EE.UU - 2 CHINA - 3 OTRO ", "ERROR \n", 1, 3, 1)==0){

			contador++;
		}

		if(contador==3 && utn_getNumero(&dato.tipo, "1 IPHONE - 2 MAC - 3 IPAD - 4 ACCESORIOS: ", "ERROR\n", 1, 4, 1)==0){

			contador++;
		}
		if(contador==4 && utn_getFloat(&dato.precio, "Precio Producto: ", "ERROR \n", 10, 100000, 1)==0 ){

			dato.isEmpty=CARGADO;
			error=0;
		}

	}while(error==1);



	return dato;
}

int APPLE_AltaProducto (eProducto lista[], int largo, int *pVereficarEspacio){

	int retorno=-1;
	int i;

	if(lista!=NULL && largo>0){

		APPLE_BuscarProductosDisponibles(lista, largo);

		*pVereficarEspacio=0;

		for(i=1; i<largo ; i++){

			if(lista[i].isEmpty!=CARGADO){

				lista[i]=APPLE_getProducto();
				*pVereficarEspacio=1;
				break;
			}
		}

		retorno=0;
	}

	return retorno;
}

int APPLE_InicializarProducto (eProducto lista[], int largo ){


	int retorno=-1;
	int i;

	if(lista!=NULL && largo>0){

		for(i=0; i<largo ; i++ ){

			lista[i].isEmpty=VACIO;
		}

		retorno=0;
	}

	return retorno;
}

int APPLE_BuscarProductosDisponibles (eProducto lista[], int largo){

	int retorno=-1;

	if(lista!=NULL && largo>0 ){

		for (int i = 1; i < largo; i++) {

			if (lista[i].isEmpty!=CARGADO) {

				lista[i].isEmpty=VACIO;
			}
		}
		retorno=0;
	}

	return retorno;
}

int APPLE_MostrarUnProducto (eProducto unProducto){


	if(unProducto.precio< 9.000){

		printf("%3d      %7s    %10d    %10d       %6.3f$\n", unProducto.idProducto, unProducto.descripcion,
			unProducto.nacionalidad, unProducto.tipo, unProducto.precio);
	}
	else{

		printf("%3d      %7s    %10d    %10d       %6.2f$\n", unProducto.idProducto, unProducto.descripcion,
					unProducto.nacionalidad, unProducto.tipo, unProducto.precio);
	}



	return 0;
}

int APPLE_MostrarProductos (eProducto lista[], int largo){

	int retorno=-1;

	if(lista!=NULL && largo>0){

		for(int i=1; i<largo; i++){

			if(lista[i].isEmpty!=VACIO){

				//EMP_PrimerLetraMayusculaUnEmpleado(lista[i].nombre);
				APPLE_MostrarUnProducto(lista[i]);
			}
		}
		retorno=0;
	}

	return retorno;
}

int APPLE_BajaProducto (eProducto lista[], int largo, int *pVerificarPuesto, int *pIdProductoBajado){

	int retorno=-1;         //-1 CANCEL - 1 BAJA  -  0 NO BAJA NO EXIST
	int IdProducto;
	int error=0;
	int i;
	char verificar[10];



	if(lista!=NULL && largo>0 && pVerificarPuesto!=NULL){

		APPLE_MostrarProductos(lista, largo);
		*pVerificarPuesto=0;

		do {

			if(utn_getNumero(&IdProducto, "ID BAJA: ", "ERROR, ID INVALIDO \n", 0, 100000, 1)==0){

				error=1;

				for (i = 1; i < largo; i++) {

					if (lista[i].idProducto == IdProducto  && lista[i].isEmpty!=VACIO) {

						if(utn_getCharNombre(verificar, "[WARNIG] = sino es 'si' cualquier Ingreso sera tomado como 'no'\nEsta seguro de continuar?: ", "\nERROR\n", 1,10)==0){

							if(strcmp(verificar, "si")==0){

								lista[i].isEmpty=VACIO;
								*pVerificarPuesto=1;
								*pIdProductoBajado=IdProducto;

							}
							else
							{
								*pVerificarPuesto=-1;
								break;
							}
						}
					}
				}
			}

		} while (error==0);

		retorno=0;
	}

	return retorno;
}
int APPLE_ModificarProducto (eProducto lista[], int largo, int *pVereficarId){

	int retorno=-1;         //-1 CANCEL - 1 CANCEL CONFIRM  -  0 NO CANCEL NO EXIST
	int IdProducto;
	int error=0;
	int i;
	int opcion;
	int seguir=0;
	char vereficar[10];
	int nuevaNacionalidad;
	int nuevoTipo;
	float nuevoPrecio;

	if(lista!=NULL && largo>0 && pVereficarId!=NULL){

		APPLE_MostrarProductos(lista, largo);
		*pVereficarId=0;

		do {

			if(utn_getNumero(&IdProducto, "\nID MODIFICAR: ", "\nERROR, NO NUMBER\n", 0, 1000000, 1)==0){

				error=1;

				for (i = 0; i < largo && seguir==0 ; i++) {

					if(lista[i].idProducto==IdProducto && lista[i].idProducto== CARGADO &&
							utn_getNumero(&opcion, "\n1) Descripcion\n2) Nacionalidad\n3) Tipo \n4) Precio\nOpcion: ", "ERROR, OPCION INVALIDA\n ", 0, 4, 1)==0)
					{


						switch (opcion) {

							case 1:

								do {
									if (utn_getCharNombre(lista[i].descripcion, "\nNUEVA DESCRIPCION: ", "ERROR \n", 1 , 20)==0) {

										if(utn_getCharNombre(vereficar, "\n[WARNIG] = sino es 'si' cualquier Ingreso sera tomado como 'no', Esta seguro de continuar?:  ", "\nERROR\n", 1,10)==0){

											if(stricmp(vereficar,"si")==0){

												strcpy(lista[i].descripcion, vereficar);
												seguir=1;
												*pVereficarId=-1;
											}
											else
											{
												*pVereficarId=-1;
												seguir=1;
											}

										}
										else{

											*pVereficarId=-1;
											seguir=1;
										}
									}

								} while (seguir==0);

								break;

							case 2:

								do {
									if(utn_getNumero(&nuevaNacionalidad, "\nNUEVA NACIONALIDAD (1 EE.UU - 2 CHINA - 3 OTRO):  ", "ERROR \n", 0, 4, 1)==0){

										if(utn_getCharNombre(vereficar, "[WARNIG] = sino es 'si' cualquier Ingreso sera tomado como 'no', Esta seguro de continuar?:  ", "\nERROR\n", 1,10)==0){

											if(stricmp(vereficar, "si")==0){

												lista[i].nacionalidad=nuevaNacionalidad;
												seguir=1;
												*pVereficarId=1;
											}
											else
											{
												*pVereficarId=-1;
												seguir=1;
											}
										}
										else{

											*pVereficarId=-1;
											seguir=1;
										}
									}

								} while (seguir==0);

								break;

							case 3:

								do {

									if(utn_getNumero(&nuevoTipo, "\nNUEVO TIPO ( 1 IPHONE - 2 MAC - 3 IPAD - 4 ACCESORIOS): ", "ERROR \n", 0, 4, 1)==0){

										if(utn_getCharNombre(vereficar, "[WARNIG] = sino es 'si' cualquier Ingreso sera tomado como 'no', Esta seguro de continuar?:  ", "\nERROR\n", 1,10)==0){

											if(stricmp(vereficar, "si")==0){

												lista[i].tipo=nuevoTipo;
												seguir=1;
												*pVereficarId=1;
											}
											else
											{
												*pVereficarId=-1;
												seguir=1;
											}
										}
										else{

											*pVereficarId=-1;
											seguir=1;
										}
									}

								} while (seguir==0);

								break;

							case 4:

								do {

									if(utn_getFloat(&nuevoPrecio, "\nNUEVO PRECIO", "ERROR\n", 0, 10.000, 1)==0){

										if(utn_getCharNombre(vereficar, "[WARNIG] = sino es 'si' cualquier Ingreso sera tomado como 'no', Esta seguro de continuar?:  ", "\nERROR\n", 1,10)==0){

											if(stricmp(vereficar, "si")==0){

												lista[i].precio=nuevoPrecio;
												seguir=1;
												*pVereficarId=1;
											}
											else
											{
												*pVereficarId=-1;
												seguir=1;
											}
										}
										else{

											*pVereficarId=-1;
											seguir=1;
										}
									}

								} while (seguir==0);

								break;

							default:

								printf("\n[ERROR] OPCION INVALIDA\n");
								break;
						}
					}
				}
			}

		} while (error==0);

		retorno=0;
	}

	return retorno;
}

static int APPLE_VereficarPrecio (eProducto lista[], int largo){

	int retorno=-1;

	for (int i= 1; i < largo; i++) {

		if(lista[i].precio != 0 &&
				lista[i+1].precio != 0)
		{

			retorno=0;
		}
	}

	return retorno;
}

int APPLE_OrdenarProductosPorPrecio (eProducto lista[], int largo){

	int retorno=-1;
	int i;
	int contador=0;
	int flagSwap;
	eProducto auxPay;


	if(lista!=NULL &&  largo>0 && APPLE_VereficarPrecio(lista, largo)==0){

		do{
			flagSwap=0;

			for(i=1; i<largo-1 ; i++){

				contador++;

				if(lista[i].isEmpty == CARGADO &&
						lista[i+1].isEmpty == CARGADO &&
						lista[i].precio < 9.999 &&
						lista[i+1].precio < 9.999 &&
						lista[i].precio < lista[i+1].precio  )
				{

					flagSwap=1;
					auxPay=lista[i];
					lista[i]=lista[i+1];
					lista[i+1]=auxPay;
				}
				else{

					if(lista[i].isEmpty == CARGADO &&
							lista[i+1].isEmpty == CARGADO &&
							lista[i].precio < lista[i+1].precio){

						flagSwap=1;
						auxPay=lista[i];
						lista[i]=lista[i+1];
						lista[i+1]=auxPay;
					}
				}
			}

		}while(flagSwap);


		retorno=contador;
	}

	return retorno;
}

int APPLE_OrdenarProductosPorDescripcion (eProducto lista[], int largo){

	int retorno=-1;
	int i;
	int contador=0;
	int flagSwap;
	eProducto auxPay;


	if( lista!=NULL &&  largo>0 && lista[i].isEmpty == CARGADO &&
	     lista[i+1].isEmpty == CARGADO  ){

		do{
			flagSwap=0;

			for(i=1; i<largo-1 ; i++){

				contador++;

				if( lista[i].isEmpty == CARGADO &&
						lista[i+1].isEmpty == CARGADO &&
						stricmp(lista[i].descripcion,lista[i+1].descripcion) > 0)
				{

					flagSwap=1;
					auxPay=lista[i];
					lista[i]=lista[i+1];
					lista[i+1]=auxPay;
				}
			}

			largo--;

		}while(flagSwap);

		retorno=contador;
	}

	return retorno;
}

static float APPLE_BuscarMayorPrecio1 (eProducto lista[], int largo){

	int i;
	int flagMayor=0;
	float precioMayor;

	if(lista !=NULL && largo>0 ){

		for (i = 1; i < largo ; i++) {

			if (lista[i].isEmpty==CARGADO &&
					lista[i].precio < 9.999 &&
					(flagMayor==0 || lista[i].precio > precioMayor)) {

				flagMayor=1;
				precioMayor=lista[i].precio;
			}
		}
	}

	return precioMayor;
}

static float APPLE_BuscarMayorPrecio2 (eProducto lista[], int largo){

	int i;
	int flagMayor=0;
	float precioMayor;

	if(lista !=NULL && largo>0 ){

		for (i = 1; i < largo ; i++) {

			if (lista[i].isEmpty==CARGADO &&
					(flagMayor==0 || lista[i].precio > precioMayor)) {

				flagMayor=1;
				precioMayor=lista[i].precio;
			}
		}
	}

	return precioMayor;
}


int APPLE_MostrarProductosMasCaro (eProducto lista[], int largo){

	int retorno=-1;
	int i;
	float precioAbuscar1=APPLE_BuscarMayorPrecio1(lista, largo);
	float precioAbuscar2=APPLE_BuscarMayorPrecio2(lista, largo);
	int flagOrdenamiento=0;

	if(lista!=NULL && largo > 0  ){

		for (i = 1; i < largo; i++) {

			if(lista[i].precio < 9.999  &&
					lista[i].isEmpty==CARGADO){

				flagOrdenamiento=1;

				for (i = 1; i < largo; ++i) {

					if(lista[i].precio == precioAbuscar1){

						APPLE_MostrarUnProducto(lista[i]);
					}
				}
				break;
			}
		}


		if (flagOrdenamiento==0) {

			for (i = 1; i < largo; i++) {

				if(lista[i].isEmpty==CARGADO){

					if(lista[i].precio == precioAbuscar2 ){

						APPLE_MostrarUnProducto(lista[i]);
					}
				}
			}
		}

		retorno=0;
	}
	return retorno;
}

int APPLE_MostrarProductosPorUnPrecio (eProducto lista[], int largo, float precioUnico, int *pPrecioDisponible){

	int retorno=-1;

	if(lista !=NULL && largo>0 && precioUnico!=0){

		*pPrecioDisponible=0;

		for(int i=1; i < largo; i++){

			if( lista[i].isEmpty == CARGADO &&
					lista[i].precio == precioUnico){

				*pPrecioDisponible=1;
				APPLE_MostrarUnProducto(lista[i]);
			}
		}

		retorno=0;
	}

	return retorno;
}

int APPLE_TipoMasBarato (eProducto lista[], int largo, int tipoDeProducto, eProducto *unProducto ){

	int retorno=-1;
	int i;
	int flagMasBarato=0;
	float precioMasBaratoTipo;

	if(lista !=NULL && largo>0 && unProducto != NULL){

		for (i = 1; i < largo; ++i) {

			if(lista[i].isEmpty==CARGADO &&
					lista[i].tipo == tipoDeProducto &&
					 lista[i].precio < 9.999 &&
					(flagMasBarato==0 || lista[i].precio > precioMasBaratoTipo)){

				flagMasBarato=1;
				precioMasBaratoTipo=lista[i].precio;
				*unProducto=lista[i];
			}

			if(lista[i].isEmpty==CARGADO &&
					lista[i].tipo == tipoDeProducto &&
					 lista[i].precio > 9.999 &&
					(flagMasBarato==0 || lista[i].precio < precioMasBaratoTipo)){

				flagMasBarato=1;
				precioMasBaratoTipo=lista[i].precio;
				*unProducto=lista[i];
			}

		}
		retorno=0;
	}

	return retorno;
}

int APPLE_MostrarNacionalidad (eProducto lista[], int largo, int nacionalidad){

	int retorno=-1;
	int i;

	if(lista != NULL && largo > 0 ){

		for (i = 0; i < largo; ++i) {

			if( lista[i].isEmpty == CARGADO &&
					lista[i].nacionalidad == nacionalidad){

				APPLE_MostrarUnProducto(lista[i]);
			}
		}

		retorno=0;
	}
	return retorno;
}

int APPLE_MostrarTipoPrecioEspecifico (eProducto lista[], int largo, int tipoProducto, float precio){

	int retorno=-1;
	int i;

	if(lista != NULL && largo > 0 ){

		for (i = 0; i < largo; ++i) {

			if( lista[i].isEmpty == CARGADO &&
					lista[i].tipo == tipoProducto &&
					lista[i].precio > 9.999 &&
					lista[i].precio >= precio){

				APPLE_MostrarUnProducto(lista[i]);
			}
			if( lista[i].isEmpty == CARGADO &&
					lista[i].tipo == tipoProducto &&
					lista[i].precio < 9.999 ){

				APPLE_MostrarUnProducto(lista[i]);
			}
		}
		retorno=0;
	}

	return retorno;
}

int APPLE_MostrarTipoMasCaro (eProducto lista[], int largo, int tipo){

	int retorno=-1;
	int i;
	float precioAbuscar1=APPLE_BuscarMayorPrecio1(lista, largo);
	float precioAbuscar2=APPLE_BuscarMayorPrecio2(lista, largo);
	int flagOrdenamiento=0;

	if(lista != NULL && largo > 0 ){

		for (i = 1; i < largo; i++) {

					if(lista[i].precio < 9.999  &&
							lista[i].isEmpty==CARGADO){

						flagOrdenamiento=1;

						for (i = 1; i < largo; ++i) {

							if(lista[i].precio == precioAbuscar1 &&
									lista[i].tipo == tipo){

								APPLE_MostrarUnProducto(lista[i]);
							}
						}
						break;
					}
				}


				if (flagOrdenamiento==0) {

					for (i = 1; i < largo; i++) {

						if(lista[i].isEmpty==CARGADO){

							if(lista[i].precio == precioAbuscar2 &&
									lista[i].tipo == tipo){

								APPLE_MostrarUnProducto(lista[i]);
							}
						}
					}
				}
		retorno=0;
	}

	return retorno;
}

