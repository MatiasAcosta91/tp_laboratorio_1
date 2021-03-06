/*
 * ingresosYValidaciones.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Acost
 */

#ifndef INGRESOSYVALIDACIONES_H_
#define INGRESOSYVALIDACIONES_H_



#endif /* INGRESOSYVALIDACIONES_H_ */
/**
 * @brief emite un mensaje al usuario solicitando que se ingrese la cantidad de kilometros de un vuelo
 *
 * @return int retorna la cantidad de kilometros ingresada
 */int solicitarKm ();
/**
 * @brief emite un mensaje al usuario solicitando que se ingrese el precio de un vuelo
 *
 * @return int retorna el precio ingresado por el usuario
 */int solicitarPrecios();

/**
 * @brief valida que el ingreso sea positivo mayor a cero, en caso contraro emite un mensaje solicitando que se ingrese nuevamente
 *
 * @param ingreso int es el valor sobre el cual se realizara la validacion
 * @return int retorna un valor positivo mayor a cero
 */int validarIngesoPositivo (int ingreso);

/**
 * @brief Realiza una carga forzada de datos
 *
 * @param kmIngresados int kilometros a cargar
 * @param precioAero int precio del vuelo de aerolineas a cargar
 * @param precioLat int precio del vuelo de latam a cargar
 * @return
 */int cargaForzada (int* kmIngresados, int* precioAero, int* precioLat);
