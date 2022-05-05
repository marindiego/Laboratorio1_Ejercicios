/*
 * Productos.c
 *
 *  Created on: 2 may. 2022
 *      Author: Usuario
 */

/*
 * Productos.h
 *
 *  Created on: 19 abr. 2022
 *      Author: Nani
 */

#include <stdio.h>
#include <string.h>
#include "Productos.h"

sProducto CargarUnProducto(stipoProducto listaTipos[], int tam)
{
	int validarTipo;
	validarTipo = 0;
	int opcion;
	sProducto unProducto;
	printf("Ingrese el ID del producto: ");
	scanf("%d", &unProducto.idProducto);
	printf("Ingrese la descripcion del producto: ");
	fflush(stdin);
	scanf("%s", unProducto.descripcion);
	printf("Ingrese la nacionalidad del producto (EEUU (0) - CHINA(1) - OTRO(-1)): ");
	scanf("%d", &unProducto.nacionalidad);
	printf("Seleccione el tipo de producto: \n");

	while(validarTipo!=1)
	{
	for(int i=0; i<tam; i++)
	{
		printf("%d %10s\n", listaTipos[i].idTipo, listaTipos[i].descripcionTipo);
	}
	printf("Elija el producto: ");
	scanf("%d", &opcion);
	for(int i=0; i<tam; i++)
	{
		if(opcion == listaTipos[i].idTipo)
		{
			validarTipo= 1;
			break;
		}
	}
	if(validarTipo==1)
	{
		unProducto.idTipo = opcion;
	}
	else
	{
		printf("Error, el id de tipo de producto no es válido.\n");
	}
	}

	printf("Ingrese el precio del producto: ");
	scanf("%f", &unProducto.precio);



	unProducto.estado=1;
	return unProducto;
}

void MostrarUnProducto(sProducto unProducto, stipoProducto listaTipos)
{
	printf("%4d %-15s %6d %d %s %.2f\n", unProducto.idProducto, unProducto.descripcion, unProducto.nacionalidad, unProducto.idTipo, listaTipos.descripcionTipo, unProducto.precio);

}

int BuscarLibre(sProducto listaProductos[], int tam)
{
	int index;
	index = -1;

	for(int i=0; i<tam; i++)
	{
		if(listaProductos[i].estado==0)
		{
			index = i;
			break;
		}
	}

	return index;
}

int CargarUnProductoEnLista(sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizelista)
{
	int index;
	index = BuscarLibre(listaProductos, tam);

	if(index!=-1)
	{
		listaProductos[index] = CargarUnProducto(listaTipos, sizelista);
	}

	return index;
}
int EliminarUnProducto(sProducto listaProductos[], int tam)
{
	int ID;
	int bandera;
	char confirmacion;
	bandera = 0;

	printf("Ingrese el ID del producto a eliminar: ");
	scanf("%d", &ID);

	for(int i=0; i<tam; i++)
	{
		if(listaProductos[i].estado==1 && listaProductos[i].idProducto == ID)//lo encontró.
		{
			printf("Está seguro de que desea eliminar el producto? s/n: ");
			fflush(stdin);
			scanf("%c", &confirmacion);
			while(confirmacion!='s' && confirmacion!='n')
			{
				printf("Ingrese si o no: s/n: ");
				fflush(stdin);
				scanf("%c", &confirmacion);
			}
			if(confirmacion=='s')
			{
				listaProductos[i].estado=0;
				bandera=1;
			}
		}
	}
	return bandera;
}

void MostrarListadoProductos(sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizelista)
{
	for(int i=0; i<tam; i++)
	{
		for(int j=0; j<sizelista; j++)
		{
			if(listaProductos[i].estado==1 && (listaProductos[i].idTipo==listaTipos[j].idTipo))
			{
				MostrarUnProducto(listaProductos[i], listaTipos[j]);
			}
		}
	}
}

void MostrarListadoPorPrecio(sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizeTipos)
{
	sProducto auxiliar;

	for(int i=0; i<tam-1; i++)
	{
		for(int j= i+1; j<tam; j++)
		{
			if(listaProductos[i].precio > listaProductos[j].precio)
			{
				auxiliar = listaProductos[i];
				listaProductos[i] = listaProductos[j];
				listaProductos[j] = auxiliar;

			}
		}
	}
	MostrarListadoProductos(listaProductos, tam, listaTipos, sizeTipos);
}

void MostrarListadoPorDescripcion(sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizeTipos)
{
	sProducto auxiliar;

	for(int i=0; i<tam-1; i++)
	{
		for(int j= i+1; j<tam; j++)
		{
			if(strcmp(listaProductos[i].descripcion, listaProductos[j].descripcion)>0)
			{
				auxiliar = listaProductos[i];
				listaProductos[i] = listaProductos[j];
				listaProductos[j] = auxiliar;
			}
		}
	}
	MostrarListadoProductos(listaProductos, tam, listaTipos, sizeTipos);
}


int ModificarUnProducto(sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizeTipos)
{
	int ID;
	int bandera;
	int opcion;
	int opcionTipo;
	int validarTipo;
	int index;
	validarTipo = 0;
	bandera = 0;

		printf("Ingrese el ID del producto a modificar: ");
		scanf("%d", &ID);

		for(int i=0; i<tam; i++)
		{
			if(listaProductos[i].estado==1 && listaProductos[i].idProducto == ID)//lo encontró.
			{
				do
				{
					printf("1. Modificar descripción \n");
					printf("2. Modificar nacionalidad \n");
					printf("3. Modificar tipo \n");
					printf("4. Modificar precio \n");
					printf("5. Salir.\n");
					printf("Elija una opcion: ");
					scanf("%d", &opcion);
					switch(opcion)
					{
						case 1:
							printf("Ingrese la nueva descripcion del producto: ");
							fflush(stdin);
							scanf("%s", listaProductos[i].descripcion);
							bandera=1;
							break;

						case 2:
							printf("Ingrese la nueva nacionalidad del producto (EEUU (0) - CHINA(1) - OTRO(-1)): ");
							scanf("%d", &listaProductos[i].nacionalidad);
							bandera=1;
							break;

						case 3:
							printf("Seleccione el nuevo tipo de producto: \n");

								while(validarTipo!=1)
								{
								for(int i=0; i<sizeTipos; i++)
								{
									printf("%d %10s\n", listaTipos[i].idTipo, listaTipos[i].descripcionTipo);
								}
								printf("Elija el producto: ");
								scanf("%d", &opcionTipo);
								for(int i=0; i<sizeTipos; i++)
								{
									if(opcionTipo == listaTipos[i].idTipo)
									{
										validarTipo= 1;
										index=i;
										break;
									}
								}
								if(validarTipo==1)
								{
									listaProductos[index].idTipo = opcionTipo;

								}
								else
								{
									printf("Error, el id de tipo de producto no es válido.\n");
								}
								}

							bandera=1;
							break;

						case 4:
							printf("Ingrese el nuevo precio del producto ");
							scanf("%f", &listaProductos[i].precio);
							bandera=1;
							break;

						case 5:
							printf("Volviendo al menú principal...");
							break;

						default:
							printf("Ingrese una opcion valida...");
							break;
					}

				}while(opcion!=5);
			}
		}
		return bandera;
}
void MostrarProductosMasCaros(sProducto listaProductos[], int tam, stipoProducto listaTipos[])
{
	float precioMaximo;

	precioMaximo = BuscarPrecioMaximo(listaProductos, tam);
	for(int i=0; i<tam; i++){
		if(listaProductos[i].estado==1 && listaProductos[i].precio == precioMaximo){
			MostrarUnProducto(listaProductos[i], listaTipos[i]);
		}
	}
}

float BuscarPrecioMaximo(sProducto listaProductos[], int tam){
	int bandera;
	float precioMaximo;

	bandera = 0;
	for(int i=0; i<tam; i++)
	{
		if(listaProductos[i].estado==1 && (bandera == 0 || listaProductos[i].precio > precioMaximo))
		{
			precioMaximo = listaProductos[i].precio;
			bandera = 1;
		}
	}
	return precioMaximo;
}
void MostrarPromedioYTipo(sProducto listaProductos[], int tam,stipoProducto listaTipos[], int sizeTipo)
{
    int i;
    int l;
    int contador;
    float acumulador;
    float promedio;

    for(i=0;i<sizeTipo;i++)
    {
        contador=0;
        acumulador=0;
        for(l=0;l<tam;l++)
        {
            if(listaProductos[l].estado==1 && listaProductos[l].idTipo==listaTipos[i].idTipo)
            {
                contador++;
                acumulador=acumulador+listaProductos[l].precio;
            }
        }
        promedio=CalcularPromedio(acumulador,contador);
        if(promedio!=-1)
        {
           printf("Tipo:%sPromedio:%f\n",listaTipos[i].descripcionTipo,promedio);
        }
        else
        {
            printf("Tipo:%s no se pudo calcular el promedio\n",listaTipos[i].descripcionTipo);
        }
    }
}
float CalcularPromedio(float acumulador,int contador)
{
    float promedio;
    promedio=-1;
    if(contador>0)
    {
        promedio=acumulador/contador;
    }
    return promedio;
}
/*
Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.
*/
int BuscarPorPrecio(sProducto listaProductos[], int tam, float precio, stipoProducto listaTipos[], int sizeTipo)
{
    int resultado;
    int i;
    int indiceTipo;

    resultado = -1;
    for(i=0; i<tam;i++)
    {
        if(listaProductos[i].estado == 1 && listaProductos[i].precio == precio)
        {
            indiceTipo = BuscarIndiceTipo(listaProductos[i].idTipo, listaTipos, sizeTipo);
            MostrarUnProducto(listaProductos[i], listaTipos[indiceTipo]);
            resultado = 0;
        }

    }
    return resultado;
}
int BuscarIndiceTipo(int idTipo, stipoProducto listaTipos[], int tam)
{
    int indice;
    int i;

    indice = -1;

    for(i=0; i<tam;i++)
    {
        if(listaTipos[i].idTipo == idTipo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

float BuscarPrecioMinimoPorTipo (sProducto listaProductos[], int tam, int idTipo)
{
    int bandera;
	float precioMinimo;

	bandera = 0;
	for(int i=0; i<tam; i++)
	{
		if(listaProductos[i].estado==1 && listaProductos[i].idTipo == idTipo && (bandera == 0 || listaProductos[i].precio < precioMinimo))
		{
			precioMinimo = listaProductos[i].precio;
			bandera = 1;
		}
	}
	return precioMinimo;
}

int BuscarMenorPorTipo (sProducto listaProductos[], int tam, stipoProducto listaTipos[], int sizeTipo, int idTipo )
{
    int retorno = -1;
    int indice;
    int banderaMenor;
    float  precioMinimo;

    indice = BuscarIndiceTipo (idTipo, listaTipos, sizeTipo);
    precioMinimo = BuscarPrecioMinimoPorTipo (listaProductos, tam, idTipo );


    for(int i=0; i<tam; i++)
    {
        if(listaProductos[i].estado == 1 && listaProductos[i].idTipo == idTipo && listaProductos[i].precio == precioMinimo){

            MostrarUnProducto(listaProductos[i], listaTipos[indice]);
            retorno = 1;
        }

    }



    return retorno;
}






