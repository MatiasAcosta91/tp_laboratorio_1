/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero;
	int statusFlight;

}Passenger;
//constructores
/**
 * @brief Crea en memoria dinamica una estructura del tipo Passenger
 *
 * @return NULL en caso de no poder crearla. devuelve referencia de la estructura en caso de crearla correctamente.
 */Passenger* Passenger_new();

/**
 * @brief Crea en memoria dinamica una estructura del tipo Passenger
 *
 * @param id
 * @param nombreStr
 * @param apellido
 * @param precio
 * @param flycode
 * @param tipoPasajero
 * @param statusFlight
 * @return NULL en caso de no poder crearla o parametros ingresados invalido. devuelve la referencia de la estructura en caso de crearla correctamente.
 */Passenger* Passenger_newParametros(int id,char* nombreStr,char* apellido, float precio,char* flycode, int tipoPasajero,int statusFlight);
//destructor
/**
 * @brief elimina un elemento del tipo Passenger.
 *
 * @param pasajero *Passenger, puntero al pasajero
 */void Passenger_delete(Passenger* pasajero);
//getters
/**
 * @brief obtiene el id de un pasajero pasajero.
 *
 * @param this Passenger* puntero al pasajero
 * @param id int* puntero al id donde se escribira el id del pasajero
 * @return 0 en caso de error( this o id = NULL), 1 si pudo cargar correctamente el id
 */int Passenger_getId(Passenger* this,int* id);

/**
 * @brief obtiene el nombre de un pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param nombre char* puntero a donde se copiara el nombre
 * @return 0 en caso de this o nombre = NULL, 1 en caso de copiarlo correctamente
 */int Passenger_getNombre(Passenger* this,char* nombre);

/**
 * @brief obtiene el apellidop de un pasajero pasajero.
 *
 * @param this Passenger* puntero al pasajero
 * @param apellido char* puntero donde se copiara el apellido
 * @return 0 en caso de this o apellido = NULL, 1 en caso de copiarlo correctamente
 */int Passenger_getApellido(Passenger* this,char* apellido);

/**
 * @brief  obtiene el codigo de vuelo de un pasajero pasajero.
 *
 * @param this Passenger* puntero al pasajero
 * @param codigoVuelo char* puntero donde se copiara el codigo de vuelo
 * @return 0 en caso de this o codigoVuelo= NULL, 1 en caso de copiarlo correctamente
 */int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * @brief obtiene el tipo de pasajero de un pasajero pasajero.
 *
 * @param this Passenger* puntero al pasajero
 * @param tipoPasajero int* puntero donde se copiara el tipo de pasajero
 * @return 0 en caso de this o tipoPasajero= NULL, 1 en caso de copiarlo correctamente
 */int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/**
 * @brief  a partir del valor int de tipo de pasajero de un pasajero se obtiene una cadena de caracteres que representa el tipo de pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param tipoPasajero char* puntero donde se copiara la cadena de tipo de pasajero.
 * @return  0 en caso de this o tipoPasajero= NULL, 1 en caso de copiarlo correctamente
 */int Passenger_getTipoStringPasajero(Passenger *this, char *tipoPasajero);

/**
 * @brief  obtiene el precio del vuelo de un pasajero pasajero.
 *
 * @param  this Passenger* puntero al pasajero
 * @param precio float* puntero dodne se copiara el precio del vuelo
 * @return  0 en caso de this o precio= NULL, 1 en caso de copiarlo correctamente
 */int Passenger_getPrecio(Passenger* this,float* precio);

/**
 * @brief obtiene el estado de vuelo de un pasajero pasajero.
 *
 * @param  this Passenger* puntero al pasajero
 * @param statusFlight int * puntero donde se copiara el estado de vuelo
 * @return  0 en caso de this o statusFlight= NULL, 1 en caso de copiarlo correctamente
 */int Passenger_getEstatus(Passenger *this, int* statusFlight);

/**
 * @brief  a partir del valor int del estado de vuelo de un pasajero se obtiene una cadena de caracteres que representa el estado de vuelo
 *
 * @param this Passenger* puntero al pasajero
 * @param StatusString char* puntero donde se copiara la cadena que describe el estado del vuelo
 * @return 0 en caso de this o statusString= NULL, 1 en caso de copiarlo correctamente
 */int Passenger_getStatusStringPasajero(Passenger *this, char *StatusString);

/**
 * @brief  a partir del valor int del tipo de pasajero de un pasajero se obtiene una cadena de caracteres que representa el tipo de pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param typePassenger char*  puntero donde se copiara la cadena que describe el tipo de pasajero
 * @return 0 en caso de this o typePassenger= NULL, 1 en caso de copiarlo correctamente
 */int Passenger_getTypeStringPasajero(Passenger *this, char *typePassenger);

/**
 * @brief a partir de la cadena que describe el tipo de pasaero se obtiene un entero que representa el tipo de pasajero
 *
 * @param stringStatus char* candea que representa el tipo de pasajero
 * @param statusInt int* puntero donde se escribira el entero que representa el tipo de pasajero
 * @return  0 en caso de this o statusInt= NULL , 1 en caso de copiarlo correctamente
 */int Passenger_getIntStatusFromString(char* stringStatus,int* statusInt);

/**
 * @brief
 *
 * @param typeString
 * @param typeInt
 * @return
 */int Passenger_getIntTypePassengerFromString(char* typeString,int* typeInt);

//setters

/**
* @brief le asigna un id a un pasajero .
*
* @param this Passenger* puntero al pasajero
* @param id int id que se le asignara al pasajero
* @return 0 en caso de this = NULL o id <=0
*/int Passenger_setId(Passenger* this,int id);
/**
* @brief le asigna un nombre a un pasajero .
*
* @param  this Passenger* puntero al pasajero
* @param nombre char* puntero de la cadena nombre que se le asignara al pasajero
* @return 0 en caso de this o nombre == NULL o en caso de nombre invalido. 1 si asigno correctamente
*/int Passenger_setNombre(Passenger* this,char* nombre);
/**
* @brief le asigna un apellido a un pasajero .
*
* @param this Passenger* puntero al pasajero
* @param apellido char* puntero de la cadena apellido que se le asignara al pasajero
* @return 0 en caso de this o apellido == NULL o en caso de apellido invalido. 1 si asigno correctamente
*/int Passenger_setApellido(Passenger* this,char* apellido);
/**
* @brief le asigna un codigo de vuelo a un pasajero .
*
* @param this Passenger* puntero al pasajero
* @param codigoVuelo char* puntero a la cadena que se le asignara como codigo de vuelo al pasajero
* @return 0 en caso de this o codigoVuelo == NULL o cadena invalida( solo caracteres alfanumericos). 1 si lo cargo correctamente.
*/int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
* @brief le asigna un tipo de pasajero a un pasajero .
*
* @param this Passenger* puntero al pasajero
* @param tipoPasajero int entero que representa el tipo de pasajero.
* @return 0 en caso de this == NULL o tipo pasajero <1 o >3, 1 si lo cargo correctamente
*/int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
/**
* @brief le asigna un precio a un pasajero .
*
* @param this Passenger* puntero al pasajero
* @param precio float precio que se le asiganara al vuelo del pasajero
* @return 0 en caso de this == NULL o precio invalido (<1000 o >100.000) 1 si lo cargo correctamente
*/int Passenger_setPrecio(Passenger* this,float precio);
/**
* @brief le asigna un estado de vuelo a un pasajero .
*
* @param this Passenger* puntero al pasajero
* @param statusFlight int  representa el  estado de vuelo del pasajero.
* @return 0 en caso de this == NULL o statusFligth<1 o >4
*/int Passenger_setEstatus(Passenger *this, int statusFlight);
//comparadores-

/**
* @brief  castea los punteros recibidos a *Passenger y compara sus id.
*
* @param x void* puntero a un pasajero
* @param y void puntero a otro pasajero
* @return 0 en caso de x o y == NULL o que los id sean iguales.  1 si el id de x es mayor, -1 si el id de y es mayor
*/int Passenger_sortId(void* x, void* y);
/**
* @brief  castea los punteros recibidos a *Passenger y compara sus nombres
*
* @param x void* puntero a un pasajero
* @param y void puntero a otro pasajero
* @return 0 en caso de x o y == NULL o que los nombres sean iguales.  1 si el nombre de x es mayor, -1 si el nombre de y es mayor
*/int Passenger_sortName(void* x, void* y);
/**
* @brief  castea los punteros recibidos a *Passenger y compara sus apellidos.
*
* @param x void* puntero a un pasajero
* @param y void puntero a otro pasajero
* @return 0 en caso de x o y == NULL o que los apellidos sean iguales.  1 si el apellido de x es mayor, -1 si el apellido de y es mayor
*/int Passenger_sortLastName(void* x, void* y);
/**
* @brief  castea los punteros recibidos a *Passenger y compara tipo de pasajero.
*
* @param x void* puntero a un pasajero
* @param y void puntero a otro pasajero
* @return 0 en caso de x o y == NULL o que los tipod e pasajero sean iguales.  1 si el tipo de pasajero de x es mayor, -1 si el tipo de pasajero de y es mayor
*/int Passenger_sortTypePassenger(void* x, void* y);
/**
* @brief  castea los punteros recibidos a *Passenger y compara sus statusFlight.
*
* @param x void* puntero a un pasajero
* @param y void puntero a otro pasajero
* @return 0 en caso de x o y == NULL o que los statusFlight sean iguales.  1 si el statusFlight de x es mayor, -1 si el statusFlight de y es mayor
*/int Passenger_sortStatusFlight(void* x, void* y);
/**
* @brief  castea los punteros recibidos a *Passenger y compara sus precios
*
* @param x void* puntero a un pasajero
* @param y void puntero a otro pasajero
* @return 0 en caso de x o y == NULL o que los precios sean iguales.  1 si el precio de x es mayor, -1 si el precio de y es mayor
*/int Passenger_sortPrice(void* x, void* y);
/**
* @brief  castea los punteros recibidos a *Passenger y compara sus codigo de vuelo
*
* @param x void* puntero a un pasajero
* @param y void puntero a otro pasajero
* @return 0 en caso de x o y == NULL o que los codigo de vuelo sean iguales.  1 si el codigo de buelo de x es mayor, -1 si el codigo de vuelo de y es mayor
*/int Passenger_sortFlycode(void* x, void* y);

//gestionId

/**
 * @brief obtiene el ultimo id guardado en la ruta path
 *
 * @param path ruta del archivo que guardara solamente el ultimo Id.
 * @param id puntero donde se copiara el valor id guardado en el archivo.
 * @return 0 en caso de path == NULL o id == NULL, 1 si pudo copiar el valor.
 */int ObtenerUltimoId(char* path, int* id);
/**
 * @brief  guarda el ultimo id usado en la ruta path
 *
 * @param path ruta del archivo que guardara solo el ultimo id
 * @param id puntero donde se copiara el valor id guardado en el archivo.
 * @return  0 en caso de path == NULL o id == NULL, 1 si pudo copiar el valor.
 */int GuardarUltimoId(char* path, int* id);

#endif /* PASSENGER_H_ */
