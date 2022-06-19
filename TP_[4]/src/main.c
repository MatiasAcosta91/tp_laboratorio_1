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


/*
TRABAJO PRACTICO 4
PROFESOR CHRISTIAN BAUS
ALUMNO ACOSTA MATIAS JORDAN
DIVISION 1A

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
} eEmpleado;

int mostrarEmpleado(eEmpleado* empleado);
int mostrarEmpleados (LinkedList* lista);
int main(void)
{
    /*
    startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
    startTesting(6);  // ll_get
    startTesting(7);  // ll_set
    startTesting(8);  // ll_remove
    startTesting(9);  // ll_clear
    startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf++
    startTesting(12); // ll_isEmpty
    startTesting(13); // ll_push
    startTesting(14); // ll_pop
    startTesting(15); // ll_contains}
    startTesting(16); // ll_containsAll
    startTesting(17); // ll_subList
    startTesting(18); // ll_clone
    startTesting(19); // ll_sort
    */


    //      1 - PRUEBA  ll_newLinkedList
    LinkedList* listaEmpleados = ll_newLinkedList();
    if (listaEmpleados == NULL)
    {
        printf("No se pudo crear la lista.\n");
        exit(1);
    }

    //      2 - PRUEBA ll_len
    printf("Largo de la lista: %d\n",ll_len(listaEmpleados));


    //      5 - PRUEBA ll_add y segunda prueba ll_len
    eEmpleado* emp1 = (eEmpleado*) calloc(1,sizeof(eEmpleado));
    if (emp1 == NULL)
    {
        exit(1);
    }
    emp1->id =1000;
    strcpy(emp1->nombre, "juan");
    emp1->sueldo = 10000;
    printf("\n\n\n");

     eEmpleado* emp2 = (eEmpleado*) calloc(1,sizeof(eEmpleado));
    if (emp2 == NULL)
    {
        exit(1);
    }
    emp2->id =1001;
    strcpy(emp2->nombre, "kevin");
    emp2->sueldo = 30000;

     eEmpleado* emp3 = (eEmpleado*) calloc(1,sizeof(eEmpleado));
    if (emp3 == NULL)
    {
        exit(1);
    }
    emp3->id =1002;
    strcpy(emp3->nombre, "Jose");
    emp3->sueldo = 5000;
    ll_add(listaEmpleados,emp1);
    ll_add(listaEmpleados,emp2);
    ll_add(listaEmpleados,emp3);
    printf("Largo de la lista: %d\n\n\n",ll_len(listaEmpleados));

    //      3- PRUEBA test_getNode
    Node* nodoAux;
    nodoAux = test_getNode(listaEmpleados,0);
    printf("Muestro el pElement del nodo obtenido con  test_getNode\n");
    mostrarEmpleado (nodoAux->pElement);
    printf("\n\n\n");



    //      4- PRUEBA test_addNode
    eEmpleado* emp4 = (eEmpleado*) calloc(1,sizeof(eEmpleado));
    emp4->id =1003;
    strcpy(emp4->nombre, "pedro");
    emp4->sueldo = 8000;
    if (!test_addNode(listaEmpleados,1,emp4))
    {
        printf("Muestro empleado agregado con la funcion test_addNode\n");
        mostrarEmpleado(emp4);
        printf("Largo de la lista: %d\n\n\n",ll_len(listaEmpleados));
    }

    //      6- PRUEBA ll_get
    printf("Muestro empleado obtenido del index 1 con la funcion ll_get\n");
    eEmpleado* aux = NULL;
    aux =(eEmpleado*) ll_get(listaEmpleados,1);
    mostrarEmpleado(aux);
    printf("\n\n\n");

    //      7- PRUEBA ll_set
    mostrarEmpleados(listaEmpleados);
    printf("\n\nRemplazo el empleado del indice 1  con un nuevo empleado5 con ll_set\n\n");
    eEmpleado* emp5 = (eEmpleado*) calloc(1,sizeof(eEmpleado));
    emp5->id =1004;
    strcpy(emp5->nombre, "maria");
    emp5->sueldo = 12000;
    ll_set(listaEmpleados,1,emp5);
    mostrarEmpleados(listaEmpleados);
    printf("\n\n\n");

    //      11- PRUEBA ll_indexOf
    int indexBuscado = ll_indexOf(listaEmpleados,emp5);
    if (indexBuscado == -1)
    {
        printf("No se encontro el empleado");
    }
    else
    {
        printf("Index del empleado 5 es: %d\n",indexBuscado);
    }
    printf("\n\n\n");


    //      13- PRUEBA ll_push
    printf("ingreso un nuevo empleado (emp6) en el index 0 con ll_push.\n");
    eEmpleado* emp6 = (eEmpleado*) calloc(1,sizeof(eEmpleado));
    emp6->id =1005;
    strcpy(emp6->nombre, "Roberto");
    emp6->sueldo = 20000;
    ll_push(listaEmpleados,0,emp6);
    mostrarEmpleados(listaEmpleados);
    printf("\n\n\n");

    //      14- PRUEBA ll_pop
    mostrarEmpleados(listaEmpleados);
    printf("\n\nElimino el empleado del index 0 y retorno su puntero con ll_pop.\n");
    eEmpleado* empAux;
    empAux = ll_pop(listaEmpleados,0);
    mostrarEmpleados(listaEmpleados);
    printf("Empleado desvinculado de la lista con ll_pop\n");
    mostrarEmpleado(empAux);
    printf("\n\n\n");

    //      15- PRUEBA ll_contains
    printf("Prueba ll_contains\n");
    if (listaEmpleados == NULL)
    {
        exit(1);
    }
    if(ll_contains(listaEmpleados,emp2)==1)
    {
        printf("El elemento se encuentra contenido.\n");
    }
    else
    {
        printf("El elemento no se encuentra contenido\n");
    }
    printf("\n\n\n");
    //      16- PRUEBA ll_containsAll

    LinkedList* listaEmpleados2 = ll_newLinkedList();
    if (listaEmpleados2 == NULL)
    {

        exit(1);
    }
        ll_add(listaEmpleados2,emp1);
        ll_add(listaEmpleados2,emp2);
        ll_add(listaEmpleados2,emp3);
        ll_add(listaEmpleados2,emp3);
        if( ll_containsAll(listaEmpleados,listaEmpleados2))
        {
            printf("Todos los elementos de la lista 2 se encuentra en la lista 1\n");
        }
        else
        {
            printf("los elementos de la lista 2 no estan contenidos en la lista 1.\n");
        }
      printf("\n\n\n");
    //      17- PRUEBA ll_subList
    printf("Prueba ll_sublist, copio lista original desde 1 a 3 (1 y 2)\n");
    LinkedList* lista3 = ll_newLinkedList();
    if (lista3 == NULL)
    {
        exit(1);
    }
    lista3 = ll_subList(listaEmpleados,1,3);
    mostrarEmpleados(lista3);
      printf("\n\n\n");

    //      18 - PRUEBA ll_clone
    printf("Prueba ll_clone, copio lista original entera\n");
    LinkedList* lista4 = ll_newLinkedList();
    if (lista4 == NULL)
    {
        exit(1);
    }
    lista4 = ll_clone(listaEmpleados);
    mostrarEmpleados(lista4);
      printf("\n\n\n");
    //      19- PRUEBA ll_sort



    //      8- PRUEBA ll_remove
    printf("Elimino al empleado del indice 1 con ll_remove\n");
    ll_remove(listaEmpleados,1);
    mostrarEmpleados(listaEmpleados);
    printf("\n\n\n");


    //      9- PRUEBA ll_clear
    printf("Elimino todos los elementos de la lista con ll_clear \n");
    ll_clear(listaEmpleados);
    mostrarEmpleados(listaEmpleados);
    printf("\n\n\n");

    //      12- PRUEBA de ll_isempty
    printf("prueba isEmpty \n");
    if (ll_isEmpty(listaEmpleados))
    {
        printf("La lista esta vacia.\n");
    }
    else
    {
        printf("La lista no esta vacia.\n");
    }
    printf("\n\n\n");
//      10- PRUEBA ll_deleteLinkedList
    printf("Elimino linkedlist con ll_deleteLinkedList \n");
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

int mostrarEmpleado(eEmpleado* empleado)
{
    int retorno = 0;
    if (empleado != NULL)
    {
        printf("id:%d nombre:%s sueldo:%.2f\n",empleado->id,empleado->nombre,empleado->sueldo);
        retorno = 1;
    }
    return retorno;
}
int mostrarEmpleados (LinkedList* lista)
{
    int retorno = 0;
    int len;
    if (lista != NULL)
    {
        len = ll_len(lista);
        if (len == 0)
        {
            printf("No hay empleados para mostrar.");
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                mostrarEmpleado(ll_get(lista,i));
            }
            retorno = 1;
        }

    }

    return retorno;
}






























