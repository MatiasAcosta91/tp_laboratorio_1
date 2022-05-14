/*
 * calculos.c
 *
 *  Created on: 14 may. 2022
 *      Author: Acost
 */

#include "arrayPassenger.h"
#include "calculos.h"
#include <stdlib.h>
int calcularPrecioTot(ePassenger* list, int len, float* precioTotal)
{
    int retorno = 0;
    float acumPrecio = 0;
    if (list != NULL && len >0)
    {
        for (int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0)
            {
                acumPrecio += list[i].price;
            }
        }
        *precioTotal = acumPrecio;
        retorno = 1;
    }
    return retorno;
}
int calcularPrecioProm(ePassenger* list, int len, float* precioPromedio)
{
    int retorno = 0;
    float acumPrecio = 0;
    int contador = 0;
    if (list != NULL && len >0)
    {
        for (int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0)
            {
                acumPrecio += list[i].price;
                contador ++;
            }
        }
        if (contador >0)
        {
            *precioPromedio = (float) acumPrecio/contador;
            retorno = 1;
        }

    }
    return retorno;
}

