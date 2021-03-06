/*
 * menuYMensajes.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Acost
 */

#ifndef MENUYMENSAJES_H_
#define MENUYMENSAJES_H_



#endif /* MENUYMENSAJES_H_ */
/**
 * @brief Muestra al usuario un menu con distintas opciones
 *
 * @param km int los kilometros que seran mostrados en el menu de opciones
 * @param precAero int precio de una de las aerolineas que sera mostrada en el menu de opciones
 * @param precLat int precio de otra de las aerolineas que sera mostrada en el menu de opciones
 * @return int retorna enteros del 1 al 6 segun la opcion elegida por el usuario
 */int menu (int km,int precAero,int precLat);
/**
 * @brief Le muestra un mensaje al usuario indicandole que calculos se realizaron
 *
 */void mensajeCalculos();
/**
 * @brief Le muestra al usuario una serie de mensajes con los resultados de los calculos realizados
 *
 * @param precDebito float es el precio calculado por pagar con debito
 * @param precCredito float precio calculado por pagar con credito
 * @param precBitcoin float precio calculado en bitcoin
 * @param precioPorKm float precio por calculado por kilometro
 */void mostrarResultados (float precDebito, float precCredito, double precBitcoin, float precioPorKm);
