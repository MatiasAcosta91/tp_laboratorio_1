/*
 * ingresos_Validaciones.h
 *
 *  Created on: 14 may. 2022
 *      Author: Acost
 */
#include "arrayPassenger.h"
#include "statusFlight.h"
#include "typePassenger.h"

#ifndef INGRESOS_VALIDACIONES_H_
#define INGRESOS_VALIDACIONES_H_



#endif /* INGRESOS_VALIDACIONES_H_ */
#include "arrayPassenger.h"
#include "statusFlight.h"
#include "typePassenger.h"

/**
 * @brief Solicita todos los datos correspondientes que seran solicitados para dar el alta de un nuevo pasajero
 *
 * @param aux ePassenger*, pasajero auxiliar donde seran cargados todos los datos necesarios para el alta
 * @param estados  eStatusFlight array de statusflight, permite cargar la descipccion correspondiente al codigo de statusflight
 * @param cantEst int tamaño del array de statusFlight
 * @param tiposPasajero typePassenger, permite cargar la descipccion correspondiente al codigo de typePassenger
 * @param cantTipo int tamaño del array de tipos
 * @return 0 en caso de error, 1 en caso de haber solicitado los datos correctamente.
 */int pedirDatos (ePassenger* aux,eStatusFlight estados[],int cantEst,eTypePassenger tiposPasajero[],int cantTipo);
/**
 * @brief emite un mensaje solicitando nombre,
 *
 * @param nombre char* direccion donde se guardara el nombre ingresado
 * @return 0 en caso de error, 1 en caso de exito
 */int pedirNombre (char* nombre);

/**
 * @brief emite un mensaje solicitando Apellido
 *
 * @param apellido char* direccion donde se guardara el apellido ingresado
 * @return  0 en caso de error, 1 en caso de exito
 */int pedirApellido (char* apellido);
/**
 * @brief emite un mensaje solicitando que se ingrese un precio dentro de un rango
 *
 * @param precio float* direccion donde se guardara el precio ingresado
 * @return  0 en caso de error, 1 en caso de exito
 */int pedirPrecio (float* precio);

 /**
   * @brief emite un mensaje solicitando que se ingrese un codigo de vuelo alfanumerico de determinada cantidad de caracteres
  *
  * @param flycode char* direccion donde se guardara el codigo ingresado
  * @return  0 en caso de error, 1 en caso de exito
  */int pedirFlycode (char* flycode);

/**
 * @brief emite un mensaje solicitando que se seleccione un tipo de pasajeros de un listado determinado que sera mostrado
 *
 * @param typePassenger eTypePassenger* direccion donde se copiara el id del tipo de pasajero seleccionado
 * @param tipos eTypePassenger []  array de tipos de pasajeros, permite mostrar el listado de tipos de pasajeros sobre el cual se realizara la seleccion
 * @param cantTipos largo del array de typo de pasajeros
 * @return 0 en caso de error, 1 en caso de exito
 */int pedirTypePassenger(int* typePassenger,eTypePassenger tipos[],int cantTipos);

/**
 * @brief emite un mensaje solicitando que se seleccione un estado de vuelo de un listado determinado que sera mostrado
 *
 * @param statusFlight eStatusFlight*  direccion donde se copiara el id del estado de vuelo
 * @param estados eStatusFligth[] array de estados de vuelo, permite mostrar el listado de estados de vuelos sobre el cual se realziara la seleccion
 * @param cantEst largo del array de estados,
 * @return0 en caso de error, 1 en caso de exito
 */int pedirStatusFlight(int* statusFlight,eStatusFlight estados[],int cantEst);


/**
 * @brief emite un mensaje solicitando que se ingrese un id
 *
 * @param id int* donde se copiara el id en caso de ser un id valido
 * @return en caso de error, 1 en caso de exito
 */int pedirId (int* id);

/** \brief Solicita un numero int entre dos rangos establecidos
 *
 * \param pResultado int* puuntero donde se guardara el resultado en caso de ser valido
 * \param mensaje *char mensaje que se muestra al usuario solicitando los numeros
 * \param mensajeError *char mensaje que se muestra en caso de ingresar un numero invalido o fuera de rango.
 * \param minimo int valor minimo que se solicitara
 * \param maximo int valor maximo que se solicitara
 * \param reintentos int cantidada de intentos que se le otorgara para ingresar la informacion, -1 para ingresos infinitos.
 * \return retorno int, 1 si salio todo Ok, 0 en caso de error
 *
 */int utn_getNumeroInt (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/** \brief Solicita un numero float entre dos rangos establecidos
 *
 * \param pResultado float* puuntero donde se guardara el resultado en caso de ser valido
 * \param mensaje *char mensaje que se muestra al usuario solicitando los numeros
 * \param mensajeError *char mensaje que se muestra en caso de ingresar un numero invalido o fuera de rango.
 * \param minimo float valor minimo que se solicitara
 * \param maximo float valor maximo que se solicitara
 * \param reintentos int cantidada de intentos que se le otorgara para ingresar la informacion, -1 para ingresos infinitos.
 * \return retorno int, 1 si salio todo Ok, 0 en caso de error
 *
 */int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/** \brief Solicita el ingreso de una de un array de char validando que solo se ingresen letras hasta un maxino de caracteres indicado
 *
 * \param pResultado char* puuntero donde se guardara el la cadena en caso de ser validada.
 * \param mensaje *char mensaje que se muestra al usuario solicitando que ingrese la cadena
 * \param mensajeError *char mensaje que se muestra en caso de ingresar un caracter invalido o fuera de rango.
 * \param minCaracteres int cantidad minima de caracteres que debera contener la cadena
  * \param maxCaracteres intcantidad maximad de caracteres de debera contener la cadena
 * \param reintentos int cantidada de intentos que se le otorgara para ingresar la informacion, -1 para ingresos infinitos.
 * \return retorno int, 1 si salio todo Ok, 0 en caso de error
 *
 */int utn_getNombreOApellido(char* pResultado, char* mensaje, char* mensajeError,int minCaractres,int maxCaracteres, int reintentos);

/** \brief Solicita el ingreso de una de un array de char validando que solo se ingresen letras  y numeros hasta un maxino de caracteres indicado
 *
 * \param pResultado char* puuntero donde se guardara el la cadena en caso de ser validada.
 * \param mensaje *char mensaje que se muestra al usuario solicitando que ingrese la cadena
 * \param mensajeError *char mensaje que se muestra en caso de ingresar un caracter invalido o fuera de rango.
 * \param minCaracteres int cantidad minima de caracteres que debera contener la cadena
  * \param maxCaracteres intcantidad maximad de caracteres de debera contener la cadena
 * \param reintentos int cantidada de intentos que se le otorgara para ingresar la informacion, -1 para ingresos infinitos.
 * \return retorno int, 1 si salio todo Ok, 0 en caso de error
 *
 */int utn_getAlfanumerico(char* pResultado, char* mensaje, char* mensajeError,int minCaracteres,int maxCaracteres, int reintentos);



