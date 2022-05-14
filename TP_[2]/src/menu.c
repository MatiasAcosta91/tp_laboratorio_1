/*
 * menu.c
 *
 *  Created on: 14 may. 2022
 *      Author: Acost
 */

#include "arrayPassenger.h"
#include "menu.h"
#include "calculos.h"
#include <stdio.h>
#include <stdlib.h>
int menuPrincipal ()
{
    int rta;
    system("cls");
    printf("****************************************************************\n");
    printf("*                        A      B      M                       *\n");
    printf("****************************************************************\n");
    printf("1.ALTAS.\n");
    printf("2.MODIFICAR.\n");
    printf("3.BAJA.\n");
    printf("4.INFORMAR.\n");
    printf("5.CARGA FORZADA\n");
    printf("6.SALIR\n");
    printf("Ingrese opcion: ");
    scanf("%d",&rta);
    system("cls");
    return rta;
}
int menuModificacion ()
{
		int rta;
        printf("1.Nombre.\n");
        printf("2.Apellido.\n");
        printf("3.Precio.\n");
        printf("4.Tipo de pasajero.\n");
        printf("5.Codigo de vuelo.\n");
        printf("6.Confirmar Cambios.\n");
        printf("7.Salir.\n");
        printf("Que desea modificar?: ");
        fflush(stdin);
        scanf("%d",&rta);
        return rta;
}
int menuInformar ()
{
    int rta;
    system("cls");
    printf("1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n");
    printf("2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio. \n");
    printf("3. Listado de los pasajeros por Codigo de vuelo y estados de vuelos ACTIVO (1)\n");
    printf("4.Salir.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&rta);
    system("cls");

    return rta;
}

