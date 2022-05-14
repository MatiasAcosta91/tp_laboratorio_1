/*
 * typePassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: Acost
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

typedef struct
{
    int idTypePassenger;
    char desc[20];
}eTypePassenger;

#endif /* TYPEPASSENGER_H_ */


/**
 * @brief permite mostrar el listado de tipos de pasajero existente
 *
 * @param tipos eTypePassenger, array de tipo de pasajeros
 * @param cantTipos largo del array
 * @return -1 en caso de error. 0 si logro listar correctamente
 */int listarTipoPasajero(eTypePassenger tipos[],int cantTipos);
/**
 * @brief permite cargar la descripccion del tipo de pasajero segun el id del tipo de pasajero
 *
 * @param tipos eTypePassenger array de tipo de pasajeros
 * @param tamTipos int largo el array de tipo de pasajeros
 * @param idTipo int  id del tipo de pasajero.
 * @param vec char[] destino donde sera copiada la descripcciond el tipo de pasajero
 * @return
 */int cargarDescTypePassenger(eTypePassenger tipos[],int tamTipos, int idTipo, char vec[]);
