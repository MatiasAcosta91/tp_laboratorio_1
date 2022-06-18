/*
* utn.h
*
*  Created on: 10 jun. 2022
*      Author: Acost
*/

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */


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

/**
* @brief emite un mensaje solicitando el ingreso de dia, mes y año
*
* @param dia puntero donde se escribira el valor del dia validado
* @param mes puntero donde se escribira el valor del mes validado
* @param anio puntero donde se escribira el valor del año validado
* @return 0 en caso de error(punteros = NULL), 1 en caso de validar correctamente,
*/int utn_getFecha(int* dia, int* mes, int* anio);

/** \brief lee desde la entrada hasta que se encuentra un \n o  hasta que haya copiado la cadena con un maximo de longitud.
*
* \param  cadena char* puntero donde se copiara la cadena obtenida,
* \param len int longitud de la cadena buffer
* \param maxCaracteres int, cantidad maxima de caracteres que escribira, tener el cuenta el \0, por lo cual escribira maxcaracteres-1
* \return retoirno int -1 en caso de error 0 si salio todo Ok.
*
*/int myGets (char* cadena, int len);

/** \brief Obtiene un numero una cadena que solo contenga letras desde la terminal.
*
* \param pResultado int* donde se devolvera un resultado.
* \return int 0 en caso de error 1 si salio todo Ok.
*
*/int getString(char* pResultado);

/** \brief Obtiene un numero entero desde la terminal.
*
* \param pResultado int* donde se devolvera un resultado.
* \return int 0 en caso de error 1 si salio todo Ok.
*
*/int getInt(int* pResultado);

/** \brief Obtiene un numero flotante desde la terminal
*
* \param pResultado float* donde se devolvera un resultado.
* \return int 0 en caso de error 1 si salio todo Ok.
*
*/ int getFloat(float* pResultado);

/** \brief Obtiene una cadena alfanumerica desde la terminal
*
* \param pResultado char* donde se devolvera un resultado.
* \return int 0 en caso de error 1 si salio todo Ok.
*
*/  int getAlfanumerico (char* pResultado);

/** \brief
*
* \param dia int
* \param mes int
* \param anio int
* \return int
*
*/int esFecha(int dia, int mes, int anio);

/** \brief verifica si la cadena ingresada solo contiene letras y le otorga formato poniendo en mayuscula el caracter del indice 0 y en minusculas los siguientes ej: Juan.
*
* \param cadena char* cadena de caracteres que sera analizada
* \return int 1 (EXITO) la cadena solo tiene letras, 0 (ERROR).
*
*/
int esString(char* cadena);

/** \brief verifica si la cadena ingresada solo contiene letras y numeros sin caracteres especiales.
*
* \param cadena char* cadena de caracteres que sera analizada
* \return int 1 (EXITO) la cadena solo tiene letras o numeros, 0 (ERROR) la cadena contiene caracteres especiales.
*
*/int esAlfanumerica (char* cadena);

/** \brief verifica si la cadena ingresada es numerica
*
* \param cadena char* cadena de caracteres que sera analizada
* \return int 1 (EXITO) la cadena es numerica, 0 (ERROR) la cadena no es numerica
*
*/int esNumerica(char* cadena);

/** \brief verifica si la cadena ingresada es es numerica con decimales y un unico punto
*
* \param cadena char* cadena de caracteres que sera analizada
* \return int 1 (EXITO) la cadena tiene decimales y un unico punto, 0 (ERROR) la cadena no no tiene decimales o tiene mas de un punto
*
*/int esDecimal(char* cadena);
