/*
 * ingresosYValidaciones.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Acost
 */

#include "ingresosYValidaciones.h"
#include <stdlib.h>
#include <stdio.h>

int solicitarKm ()
{
    int km;
    printf("Ingrese los Kilometros: ");
    scanf("%d",&km);
    km = validarIngesoPositivo(km);

    return km;
}
int validarIngesoPositivo (int ingreso)
{
    while (ingreso < 1)
    {
        printf("ERROR: Ingrese un valor positivo mayor a cero: ");
        fflush(stdin);
        scanf("%d",&ingreso);
    }
    return ingreso;
}
int solicitarPrecios()
{
    int precio;
    printf("ingrese precio: ");
    scanf("%d",&precio);
    precio = validarIngesoPositivo(precio);
    return precio;
}

int cargaForzada (int* kmIngresados, int* precioAero, int* precioLat)
{
    int todoOk=0;
    if (kmIngresados != NULL && precioAero != NULL && precioLat != NULL)
    {
        *kmIngresados = 7090;
        *precioAero =  162965;
        *precioLat = 159339;
        todoOk = 1;
    }
    return todoOk;
}

