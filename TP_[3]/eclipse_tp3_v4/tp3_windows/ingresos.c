/*
 * ingresos.c
 *
 *  Created on: 11 jun. 2022
 *      Author: Acost
 */
#include "ingresos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#define INTENTOS_INF -1
int Passenger_SolicitarDatos(char* nombreStr,char* apellido, float* precio, int* tipoPasajero,char* flycode,int* statusFlight)
{
	int retorno = 0;
	char mensajeNombre[]="Ingrese nombre: \n";
	char mensajeApellido[]="Ingrese apellido: \n";
	char mensajePrecio[]="Ingrese Precio entre 1.000 y 100.000: \n";
	char mensajeTipoPasajero[]="1_FirstClass\n2_ExecutiveClass\n3_EconomyClass\nIngrese tipo de pasajero : ";
	char mensajeFlyCode[]="Ingrese codigo de vuelo alfanumerico de 7 digitos: \n";
	char mensajeStatus[]="1_Aterrizado.\n2_En horario.\n3_En vuelo.\n4_Demorado.\n Ingrese el estado de vuelo: ";
	char mensajeError[]="ERROR = ";
	if (nombreStr != NULL && apellido != NULL && precio != NULL && tipoPasajero != NULL && flycode != NULL)
	{
		printf("*******************************************************************************\n");
		printf("*                           M E N U           A L T A                         *\n");
		printf("*******************************************************************************\n");
		if( utn_getNombreOApellido(nombreStr, mensajeNombre, mensajeError, 3, 49, INTENTOS_INF) &&
		utn_getNombreOApellido(apellido, mensajeApellido, mensajeError,2, 49, INTENTOS_INF) &&
		utn_getNumeroFloat(precio, mensajePrecio, mensajeError, 1000, 100000,INTENTOS_INF) &&
		utn_getNumeroInt(tipoPasajero, mensajeTipoPasajero, mensajeError, 1, 3, INTENTOS_INF) &&
		utn_getAlfanumerico(flycode, mensajeFlyCode, mensajeError, 7, 7, INTENTOS_INF)&&
		utn_getNumeroInt(statusFlight, mensajeStatus, mensajeError,1, 4,INTENTOS_INF))
		{
			retorno = 1;
		}
	}
	return retorno;
}
