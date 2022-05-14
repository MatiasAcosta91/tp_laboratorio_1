/*
 * calculos.h
 *
 *  Created on: 14 may. 2022
 *      Author: Acost
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_



#endif /* CALCULOS_H_ */
/**
 * @brief recorre el array de pasajeros y calcula  el precio total de todos los vuelos de los pasajeros que posean el campo isEmpty == 0
 *
 * @param list ePassengers* array de pasajeros
 * @param len largo del array de pasajeros
 * @param precioTotal float *direccion donde se devolvera el precio total calculado, en caso de no haber pasajeros isEmpty == 0 se devolvera 0
 * @return 0 en caso de error, 1 si pudo realizar el calculo correctamente
 */int calcularPrecioTot(ePassenger* list, int len, float* precioTotal);
/**
 * @brief  recorre el array de pasajeros y calcula  el precio promedio segun el precio de todos los vuelos de los pasajeros que posean el campo isEmpty == 0
 *
 * @param list ePassenger* array de pasajeeros
 * @param len largo de array de pasajeros
 * @param precioPromedio direccion donde se escribira el valor del precio promedio de los vuelos
 * @return 0 en caso de error o no haber pasajeros disponibles para hacer el calculo, 1 en caso de calcularlo correctamente.
 */int calcularPrecioProm(ePassenger* list, int len, float* precioPromedio);
