/*
 * statusFlight.h
 *
 *  Created on: 14 may. 2022
 *      Author: Acost
 */

#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_
typedef struct
{
    int idStatus;
    char desc[20];
}eStatusFlight;

#endif /* STATUSFLIGHT_H_ */

/**
 * @brief muestra un listado de los tipos de vuelo
 *
 * @param estados eStatusFlight[] array de los estados de vuelo
 * @param cantEst largo del array de estados de vuelo
 * @return -1 en caso de error, 0 si lo pudo listar correctamente
 */int ListarStatus(eStatusFlight estados[],int cantEst);
/**
 * @brief busca dentro del array de vuelos estados de vuelo la descripccion correspondiente a un determinado id de estado de vuelo y devuelve la descripccion correspondiente
 *
 * @param estados eStatusFlight array del estado de vuelos
 * @param cantEst largo del array de estados de vuelo
 * @param idEst id del estado de vuelo que se buscara
 * @param descripccion direccion donde se copiara la descripccion del vuelo en caso de haberse ingresado un id de vuelo existente
 * @return 0 en caso de error o que no se encuentre el id, 1 si se logro copiar la descripccion correctamente
 */int cargarDescripccionStatus(eStatusFlight estados[],int cantEst,int idEst,char descripccion[]);


