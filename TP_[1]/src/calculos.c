/*
 * calculos.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Acost
 */
#include "calculos.h"
#include <stdlib.h>

float aplicarDescuento (int precioInicial,int porcDesc)
{
    float precioFinal = 0;
    if (precioInicial > 0 && porcDesc > 0)
    {
        precioFinal =  precioInicial - (float) porcDesc * precioInicial / 100 ;

    }
    return precioFinal;
}
float aplicarInteres (int precioInicial,int porcInteres)
{
    float precioFinal = 0;
    if (precioInicial > 0 && porcInteres > 0)
    {
        precioFinal =  precioInicial + (float) porcInteres * precioInicial / 100 ;

    }
    return precioFinal;
}
double pesosABitcoin (int precioPesos, float valorBitcoin)
{
    double bitcoin = 0;
    if (precioPesos > 0 && valorBitcoin > 0)
    {
        bitcoin = (float) precioPesos / valorBitcoin;
    }
    return bitcoin;
}
float precioPorKm (int km, int precio)
{
    float precioKm = 0;
    if (km > 0 && precio > 0)
    {
        precioKm = (float) precio / km;
    }
    return precioKm;
}
int calcularDifPrecio(int precio1,int precio2)
{
    float diferencia = -1;
    if (precio1 > 0 && precio2 > 0)
    {
        if (precio1 > precio2)
        {
            diferencia = precio1 - precio2;
        }
        else
        {
            diferencia = precio2 - precio1;
        }
    }
    return diferencia;
}


int realizarCalculos (int precioVuelo,int km,int descuento,int interes,float valorBitcoin,float* precDebit, float* precCredit,double* precBit,float* precKm)
{
    int todoOk = 0;
    if (precioVuelo > 0 && descuento > 0 && interes > 0 && valorBitcoin > 0 && precBit!=NULL && precCredit!=NULL && precBit!=NULL && precKm!=NULL)
    {
        *precDebit = aplicarDescuento (precioVuelo,descuento);
        *precCredit = aplicarInteres (precioVuelo,interes);
        *precBit = pesosABitcoin (precioVuelo,valorBitcoin);
        *precKm = precioPorKm (km,precioVuelo);
        todoOk = 1;
    }
    return todoOk;
}
