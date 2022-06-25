/*
 ============================================================================
 Name        : Clase.c
 Author      : DIego
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	FILE* pArchivo;
	char cadena[100];
	pArchivo = fopen("mis_datos.txt", "w");//Abriendo el archivo para escritura de texto
	   if(pArchivo!=NULL)
	   {
	       fprintf(pArchivo,"German Scarafilo, 34años");
	       fclose(pArchivo);

	   }

	//Leer en texto
	pArchivo = fopen("mis_datos.txt","r");
	if(pArchivo!=NULL)
	{
		while(!feof(pArchivo))
		{
			//find end of file
			fgets(cadena,100,pArchivo);
			printf("%s",cadena);
		}
		fclose(pArchivo);
	}

	//Escribir en binario
	FILE* pArchivo;
		int x[5] = {6,7,5,9,3};
	   pArchivo = fopen("numerito.bin", "wb");
	   fwrite(x,sizeof(int),5,pArchivo);


	   int entero[5];
	   pArchivo = fopen("numerito.bin", "rb");
	   fread(entero, sizeof(int), 5, pArchivo);

	   for(int i=0; i<5; i++)
	   {
	       printf("%d\n", entero[i]);
	   }

	   fclose(pArchivo);




	return EXIT_SUCCESS;
}
