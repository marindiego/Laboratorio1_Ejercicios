/*
 ============================================================================
 Name        : D).c
 Author      : DIego
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int PushInt (int* list, int size, int value, int index);
int PushInt (int* list, int size, int value, int index)
{
	int* aux;
	int new_size = size+1;

	for (int i = 0; i < size; i++) {
		if (list[i] == index  ) {
			list[index] = value;
			aux = (int*)realloc(list,sizeof(int)*new_size);
			list = aux;
		}
	}


	return 0;
}

int RemoveInt (int* list, int size, int integer);
int RemoveInt (int* list, int size, int integer){

	for (int i = 0; i < size; i++) {


	}

	return 0;
}
int main(void) {

	setbuf(stdout,NULL);

	int* ages;
	int size = 5;
	ages = (int*) malloc(sizeof(int)*5);


	ages[0]=2;
	ages[1]=3;
	ages[2]=6;
	ages[3]=2;
	ages[4]=1;


	RemoveInt(ages, 5, 6);

	for(int i = 0; i<size; i++){

		if (*(ages+i)!=0) {
			printf("%d\n", *(ages+i));
		}
	}

	PushInt(ages, size, 8, 3);

	for(int i = 0; i<size; i++){

		if (*(ages+i)!=0) {
			printf("%d\n", *(ages+i));
		}
	}


	return EXIT_SUCCESS;
}
