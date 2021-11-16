


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include "funciones_matematicas.h"
#include "funciones_string.h"


int myGets(char* cadena,int tam){

	int retorno=0;

	fflush(stdin);
	fgets(cadena,tam,stdin);
	cadena[strlen(cadena)-1]='\0';

	return retorno;
}

int myGetsChar( char *cadena, int tamMax){

	int retorno=1;
	char buffer[4096];

	if(cadena!=NULL && tamMax>0){

		if(fgets(buffer, sizeof(buffer), stdin)!= NULL ){

			if(buffer[strnlen(buffer,sizeof(buffer))-1]=='\n'){

				buffer[strnlen(buffer,sizeof(buffer))-1]='\0';
			}

			if(strnlen(buffer,sizeof(buffer)) <= tamMax){

				strncpy(cadena,buffer,tamMax);
			}
		}
	}

	return retorno;
}

int getInt(int* pResultado){

	int retorno=-1;
	char buffer[50];

	if(pResultado != NULL &&
		myGets(buffer,sizeof(buffer))==0 &&
		esNumerica(buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);

	}

	return retorno;
}
int getFloat(float* pResultado){

	int retorno=-1;
	char buffer[50];

	if(pResultado != NULL &&
		myGets(buffer,sizeof(buffer))==0 &&
		esNumerica(buffer) &&
		validarFloat(buffer)==1)
	{
		retorno=0;
		*pResultado=atof(buffer);

	}

	return retorno;
}

int validarFloat (char *stringRecibido){

	int retorno=1;
	int i=0;
	int contadorPuntos=0;

	if(stringRecibido[0]=='+' || stringRecibido[0]== '-'){

		i=1;
	}

	for(; stringRecibido[i]!='\0'; i++){

		if(stringRecibido[i]=='.'){

			contadorPuntos++;
			if(contadorPuntos>1){

				retorno=0;
				break;
			}
		}
	}


	return retorno;
}

int getChar(char* pResultado, int tam){

	int retorno=0;
	char buffer[4096];

	if(pResultado!=NULL && tam>0 &&
	myGetsChar(buffer, tam)==0 &&
	esTextoBasico(buffer)==1)

	{
		retorno=1;
		strcpy(pResultado, buffer);

	}


	return retorno;
}
int esNumerica(char* cadena){

	int retorno= 1;
	int i=0;
	if(cadena[0]=='-'){

		i=1;
	}
	for(;cadena[i]!='\0';i++){

		if(cadena[i]<'0'|| cadena[i]>'9' || !(isdigit(cadena[i]))){
			retorno=0;
			break;
		}
	}
	return retorno;
}
int esTextoBasico(char* cadena){

	int retorno= 1;
		int i;

		for(i=0;cadena[i]!='\0';i++){

			//if(cadena[i]<'A'||(cadena[i]>'Z'&&cadena[i]<'a')||(cadena[i]>'z'&&cadena[i]<'ñ')||cadena[i]>'Ñ'){

			if( cadena[0]=='\n' || isspace(cadena[0]) || cadena[i]<32||(cadena[i]>32&&cadena[i]<65)||(cadena[i]>90&&cadena[i]<97)||(cadena[i]>122&&cadena[i]<164)||cadena[i]>165 || !(isalpha(cadena[i]))){

				retorno=0;
				break;
			}
		}
	return retorno;
}
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos){

	int retorno =-1;
	int buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

		do{
			printf("%s",mensaje);

			if(getInt(&buffer)==0 &&
					buffer>=minimo &&
					buffer<=maximo)
			{

				*pResultado=buffer;
				retorno=0;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getFloat(float* pResultado, char* mensaje,char* mensajeError, float minimo, float maximo, int reintentos){

	int retorno =-1;
	float buffer;
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

		do{
			printf("%s",mensaje);

			if(getFloat(&buffer)==0 && buffer>=minimo && buffer<=maximo){

				*pResultado=buffer;
				retorno=0;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getCharNombre(char* pResultado, char* mensaje,char* mensajeError, int reintentos, int tamMax){

	int retorno =-1;
	char buffer[tamMax];

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0  && tamMax>1){

		do{
			printf("%s",mensaje);

			if(getChar(buffer, sizeof(buffer))==1){

				strncpy(pResultado,buffer,tamMax);
				retorno=0;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos>=0);
	}

	return retorno;
}
int PrimerasLetrasMayuscula(char*mensaje){

	int i;
	mensaje[0]=toupper(mensaje[0]);

	for(i=1;mensaje[i]!='\0';i++){

		mensaje[i]=tolower(mensaje[i]);

		if(mensaje[i-1]==32){

			mensaje[i]=toupper(mensaje[i]);
		}
	}
	return 1;
}
int ConcatenarNombreYApellido(char*nombre,char*apellido,char*nombreCompleto,int tam){
	int retorno=0;
	snprintf(nombreCompleto,tam,"%s, %s",apellido,nombre);
	retorno=PrimerasLetrasMayuscula(nombreCompleto);
	return retorno;
}





