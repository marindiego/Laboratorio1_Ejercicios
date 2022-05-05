/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);// Crear una lista en memoria


Node* test_getNode(LinkedList* this, int nodeIndex);

int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

int ll_add(LinkedList* this, void* pElement);// Agrega un nodo con un elemento en la lista

int ll_len(LinkedList* this); // Devuelve la cantidad de nodos enganchados

void* ll_get(LinkedList* this, int index); // Devuelve la dir que estas gestionando

int ll_set(LinkedList* this, int index,void* pElement); // Reemplaza un elemento por otro

int ll_remove(LinkedList* this,int index); // Borra un nodo pero no el elemento

int ll_clear(LinkedList* this); // Vacia los nodods

int ll_deleteLinkedList(LinkedList* this); // Borra la lista completa

int ll_indexOf(LinkedList* this, void* pElement); // Devuelve el indice del elemento

int ll_isEmpty(LinkedList* this); // Si esta vacia

int ll_push(LinkedList* this, int index, void* pElement); // Mete un nodo en el medio

void* ll_pop(LinkedList* this,int index); //Saca el elemento del indice especificado y lo devuelve

int ll_contains(LinkedList* this, void* pElement); // Le paso el elemento y me dice si esta o no esta

int ll_containsAll(LinkedList* this,LinkedList* this2); // Si una lista esta contenida a la otra

LinkedList* ll_subList(LinkedList* this,int from,int to); // Devuelve una sublista desde las posiciones de los elementos que recibe con parametros

LinkedList* ll_clone(LinkedList* this); //Te copia una lista indentica a la que recibe

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); // Ordenar la lista dependiendo de los parametros qeu recibe
