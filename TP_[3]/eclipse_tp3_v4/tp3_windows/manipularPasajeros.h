/*
 * manipularPasajeros.h
 *
 *  Created on: 11 jun. 2022
 *      Author: Acost
 */
#include "LinkedList.h"
#include "Passenger.h"
#ifndef MANIPULARPASAJEROS_H_
#define MANIPULARPASAJEROS_H_



#endif /* MANIPULARPASAJEROS_H_ */

/**
 * @brief muestra el listado completos de pasajeros que se encuentra dentro pArrayListPassenger
 *
 * @param pArrayListPassenger LinkedList* lista de pasajeros
 * @return 0 en caso de pArrayListPassenger = NULL o no hay pasajeros cargados. 1 en caso de mostrar correctamente.
 */int mostrarPassengers (LinkedList* pArrayListPassenger);
/**
 * @brief muestra un unico pasajero.
 *
 * @param passenger Passenger* puntero a un pasajero.
 * @return 0 en caso de passenger = NULL, 1 si se pudo mostrar
 */int mostrarPassenger(Passenger* passenger);
/**
 * @brief buscar un pasajero segun el id ingresado.
 *
 * @param pArrayListPassenger LinkedList* lista de pasajeros
 * @param idBuscado int id del pasajero buscado
 * @return retorna el indice del pasajero dentro del arrayList, -1 si no lo encontro
 */int buscarPassengerId(LinkedList* pArrayListPassenger,int idBuscado);
/**
 * @brief permite realizar la baja de un pasajero
 *
 * @param pArrayListPassenger LinkedList* lista de pasajeros
 * @return 1 si se dio la baja, 0 si no se encontro el pasajero o no se confirmo la baja
 */int bajaPasajero (LinkedList* pArrayListPassenger);
/**
 * @brief permite realizar el alta de un pasajero.
 *
 * @param pArrayListPassenger LinkedList* lista de pasajeros
 * @param pLastId int* puntero al ultimo id utilizado.
 * @return 1 en caso de confirmar el alta. 0  si arrayList o plastId = 0 o si no se confirma el alta
 */int AltaPasajero(LinkedList* pArrayListPassenger,int* pLastId);
/**
 * @brief permite modificar un pasajero
 *
 * @param pArrayListPassenger LinkedList* lista de pasajeros
 * @return 0 en caso de no encontrar al pasajero o no realizar ninguna modificacion, 1 si se confirma alguna modificacion
 */int modificarPasajero(LinkedList* pArrayListPassenger);
/**
 * @brief permite realizar el ordenamiento de el listado de pasajeros.
 *
 * @param pArrayListPassenger LinkedList* lista de pasajeros
 * @return 0 si arrayList == NULL o no se realiza ningun ordenamiento, 1 si se realizo algun ordenamiento.
 */int ordenarPasajero(LinkedList* pArrayListPassenger);
