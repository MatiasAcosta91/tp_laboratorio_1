/*
 * ingresos.h
 *
 *  Created on: 11 jun. 2022
 *      Author: Acost
 */
#define INGRESOS_INF -1;
#ifndef INGRESOS_H_
#define INGRESOS_H_



#endif /* INGRESOS_H_ */

/**
 * @brief solicita que se ingresen todos los datos necesarios para dar de alta manualmente a un nuevo pasajero
 *
 * @param nombreStr char* nombre del pasajero
 * @param apellido char* apellido del pasajero
 * @param precio float* precio del vuelo
 * @param tipoPasajero int* tipo de pasajero.
 * @param flycode char* codigo del vuelo
 * @param statusFlight int* estado del vuelo
 * @return 0 si alguno de los parametros = NULL, 1 si se ingresaron todos los datos correctamente.
 */int Passenger_SolicitarDatos(char* nombreStr,char* apellido, float* precio, int* tipoPasajero,char* flycode,int* statusFlight);
