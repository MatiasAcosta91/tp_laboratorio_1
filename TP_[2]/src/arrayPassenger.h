/*
 * arrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: Acost
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger; //1 economico 2 ejecutiva 3 primera clase
    int statusFlight; //0 ESPPERA , 1 ACTIVO, 2 DEMORADO, 3 REPROGRAMADO, 4 CANCELADO
    int isEmpty;
} ePassenger;


#endif /* ARRAYPASSENGER_H_ */
#include "statusFlight.h"
#include "typePassenger.h"
int buscarLibre (ePassenger* list,int len);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/int initPassengers(ePassenger* list, int len);


/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger* posicion libre del array de pasajeros donde se realizara la carga de un nuevo pasajero.
* \param len int tamaño del array de pasajeros
* \param id int id que se le asignara al nuevo pasajero
* \param name[] char nombre que se le asignara al nuevo pasajero
* \param lastName[] char apellido que se le asignara al nuevo pasajero
* \param price float precio del vuelo del nuevo pasajero
* \param typePassenger int tipo de pasajero
* \param flycode[] char codigo de vuelo del nuevo pasajero
* \return int Return (-1) if Error [Invalid length or NULL pointer or withoutfree space] - (0) if Ok
*/int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int status,eStatusFlight estados[], int cantEst,eTypePassenger tipos[], int cantTipos);



/**
 * @brief muestra el contenido del array de pasajeros cuyo campo isEmpty==0;
 *
 * @param list ePassenger* array de pasajeros que se mostrara
 * @param length largo del array de pasajeros
 * @param estatus eStatusFligth[] array de statusfligth, permite que se cargue la descripccion correspondiente al codigo de statusFligth
 * @param tamStatus tamaño del array de statusFlight
 * @param tiposPasajero typePassenger[] array de TypePassenger, permite que se cargue la descripccion correspondiente al codigo de typePassenger
 * @param cantTipo largo del array de typePassenger
 * @return 0 en caso de error o que no existan pasajeros para mostrar, 1 en caso de haber podido mostrar pasajeros.
 */int printPassengers(ePassenger* list, int length, eStatusFlight estatus[],int tamStatus,eTypePassenger tiposPasajero[],int cantTipo);


/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list ePassenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*
*/int findPassengerById(ePassenger* list, int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/int removePassenger(ePassenger* list, int len, int id,eStatusFlight estados[],int cantEst,eTypePassenger tiposPasajero[],int cantTipo);


/**
 * @brief permite harcodear un listado de pasajeros en el array de vuelos.
 *
 * @param list ePassener*, array donde se cargara el listado de pasajeros,
 * @param len int largo del array de pasajeros
 * @param cant int cantidad de nuevos pasajeros que seran cargados
 * @param pId int* id sobre el cual se comenzara la carga secuencial autoingrementando el id++ por cada pasajero
 * @return
 */int altaForzada(ePassenger* list,int len, int cant, int* pId);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/int sortPassengers(ePassenger* list, int len, int order);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/int sortPassengersByCode(ePassenger* list, int len, int order);

/** \brief  Permite modificar un pasajero dentro del array
 *
 * \param list ePassenger* array de pasajeros
 * \param len int tamaño del array
 * \return int 0 en caso de error o no haber realizado ningun cambio. 1 en de ingresar correctamente o haber realizado un cambio en algun pasajero
 *
 */int modifyPassenger(ePassenger* list,int len,eStatusFlight estatus[],int tamStatus,eTypePassenger tiposPasajero[],int cantTipo);


/**
 * @brief permite acceder a un submenu donde se podra elegir que datos desean que se informen.
 *
 * @param list ePassenger* array de pasajeros sobre los cuales se mostraran los informes
 * @param len int tamaño del array
 * @param estatus eStatusFlight array de statusflight, permite cargar la descipccion correspondiente al codigo de statusflight
 * @param tamStatus int tamaño del array de statusFlight
 * @param tipos eTipos* array de typePassenger, permite cargar la descipccion correspondiente al codigo de typePassenger
 * @param tamTipos int tamaño del array de tipos
 * @return int -1 en caso de error arrays apuntando a NULL, 0 en caso de poder acceder correctamente.
 */int informar(ePassenger* list, int len,eStatusFlight estatus[],int tamStatus,eTypePassenger tipos[],int tamTipos);
