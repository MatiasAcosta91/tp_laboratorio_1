#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "ingresos.h"
#include "manipularPasajeros.h"
#include "utn.h"
#include "parser.h"
#include "menu.h"

#define INTENTOS_INF -1


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int cantidadCargados= 0;
	FILE* f = NULL;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		f = fopen(path,"r");
		if (f != NULL)
		{
			cantidadCargados = parser_PassengerFromText(f, pArrayListPassenger);
			if(cantidadCargados )
			{
				printf("Cantidad de pasajeros cargados correctamente = %d.\n",cantidadCargados);
				retorno = 1;
			}
		}
		fclose(f);
	}
	//RECIBE EL PATH DEL ARCHIVO Y EL LINKED LIST
	//SI LOGRA ABRRIR EL PATH
	//TIENE QUE LLAMAR A PARSER LOAD FROM TEXT
	//SI EL PARSER PUDO HACER TODO OK CIERRA EL ARCHIVO
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int cantidadCargados = 0;
	FILE* f = NULL;
	if (path != NULL && pArrayListPassenger != NULL)
	{
		f = fopen(path,"rb");
		if (f != NULL)
		{
			cantidadCargados = parser_PassengerFromBinary(f, pArrayListPassenger);
			if (cantidadCargados)
			{
				printf("Cantidad de pasajeros cargados correctamente = %d.\n",cantidadCargados);
				retorno = 1;
			}
		}
		fclose(f);
	}
	//RECIBE EL PATH DEL ARCHIVO Y EL LINKED LIST
	//SI LOGRA ABRRIR EL PATH
	//TIENE QUE LLAMAR A PARSER LOAD FROM BINARY
	//SI EL PARSER PUDO HACER TODO OK CIERRA EL ARCHIVO
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,int* pLastId)
{
	int retorno = 0;
	if (pArrayListPassenger != NULL && pLastId != NULL)
	{
		if( AltaPasajero(pArrayListPassenger, pLastId) )
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = 0;
    if(modificarPasajero(pArrayListPassenger))
    {
    	retorno = 1;
    }
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	if (pArrayListPassenger != NULL)
	{
		if (bajaPasajero(pArrayListPassenger))
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	if (pArrayListPassenger != NULL && ll_len(pArrayListPassenger)>0)
	{
		if (mostrarPassengers(pArrayListPassenger))
		{
			retorno = 1;
		}
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	if (pArrayListPassenger != NULL && ll_len(pArrayListPassenger) >0)
	{
		if (ordenarPasajero(pArrayListPassenger))
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int cantidadGuardados = 0;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* f = fopen(path,"w");
		if (f != NULL)
		{
			cantidadGuardados = parser_TextFromPassenger(f, pArrayListPassenger);
			if (cantidadGuardados)
			{
				printf("Cantidad de pasajeros guardados correctamente = %d.\n",cantidadGuardados);
				retorno = 1;
			}

		}
		fclose(f);
	}
	//RECIBE EL PATH DEL ARCHIVO Y EL LINKED LIST
	//SI LOGRA ABRRIR EL PATH
	//TIENE QUE LLAMAR A PARSER LOAD FROM TEXTa
	//SI EL PARSER PUDO HACER TODO OK CIERRA EL ARCHIVO
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int cantidadGuardados = 0;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* f = fopen(path,"wb");
		if (f != NULL)
		{
			cantidadGuardados = parser_binaryFromPassenger(f, pArrayListPassenger);
			if (cantidadGuardados)
			{
				printf("Cantidad de pasajeros guardados correctamente = %d.\n",cantidadGuardados);
				retorno = 1;
			}

		}
		fclose(f);
	}
	//RECIBE EL PATH DEL ARCHIVO Y EL LINKED LIST
	//SI LOGRA ABRRIR EL PATH
	//TIENE QUE LLAMAR A PARSER LOAD FROM TEXT
	//SI EL PARSER PUDO HACER TODO OK CIERRA EL ARCHIVO
	return retorno;
}

