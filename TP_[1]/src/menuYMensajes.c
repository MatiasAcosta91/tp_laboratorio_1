/*
 * menuYMensajes.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Acost
 */
#include "menuYMensajes.h"
#include <stdio.h>
#include <stdlib.h>

int menu (int km,int precAero,int precLat)
{
    int opcion;
    system("cls");
    printf("1. Ingresar Kilometros: (Km = %d)\n",km);
    printf("2. Ingresar Precio de vuelos (Aerolineas = %d , Latam = %d ).\n",precAero,precLat);
    printf("3. Calcular todos los costos.\n");
    printf("4. Informar Resultados.\n");
    printf("5. Carga forzada de datos.\n");
    printf("6. Salir.\n\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    system("cls");
    return opcion;

}
void mensajeCalculos()
{
    printf("Se realizaron los siguientes calculos:\n");
    printf("a) Tarjeta de debito (descuento 10%%)\n");
    printf("b) Tarjeta de credito (interes 25%%)\n");
    printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
    printf("d) Mostrar precio por km (precio unitario)\n");
    printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
}
void mostrarResultados (float precDebito, float precCredito, double precBitcoin, float precioPorKm)
{
    printf("a) Precio con tarjeta de debito: $ %.2f\n",precDebito);
    printf("b) Precio con tarjeta de credito: $ %.2f\n",precCredito);
    printf("c) Precio pagando con bitcoin: %.10f BTC\n",precBitcoin);
    printf("d) Mostrar precio unitario: $ %.2f\n\n",precioPorKm);
}
