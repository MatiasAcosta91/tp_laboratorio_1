/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "utn.h"
Passenger* Passenger_new()
{
	return (Passenger*) calloc(1,sizeof(Passenger));
}
Passenger* Passenger_newParametros(int id,char* nombreStr,char* apellido, float precio,char* flycode, int tipoPasajero,int statusFlight)
{
	Passenger* aux = Passenger_new();
	if (aux != NULL && nombreStr != NULL && apellido != NULL && flycode != NULL)
	{
		if (!(Passenger_setId(aux,id) && Passenger_setNombre(aux,nombreStr) && Passenger_setApellido(aux,apellido) && Passenger_setPrecio(aux,precio)
				&& Passenger_setTipoPasajero(aux,tipoPasajero) && Passenger_setCodigoVuelo(aux, flycode) && Passenger_setEstatus(aux, statusFlight))   )
		{
			free(aux);
			aux = NULL;

		}
	}
	return aux;
}
void Passenger_delete(Passenger* pasajero)
{
	free(pasajero);
}
int Passenger_setId(Passenger *this, int id)
{
	int retorno = 0;
	if (this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}
int Passenger_getId(Passenger *this, int *id)
{
	int retorno = 0;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setNombre(Passenger *this, char *nombre)
{
	int retorno = 0;
	char auxNombre[20];
	if (this != NULL && esString(nombre) && strlen(nombre) < 50 && strlen(nombre) >= 2)
	{
		strcpy(auxNombre, nombre);
		strlwr(auxNombre);
		auxNombre[0] = toupper(auxNombre[0]);
		strcpy(this->nombre, nombre);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getNombre(Passenger *this, char *nombre)
{
	int retorno = 0;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setApellido(Passenger *this, char *apellido) {
	int retorno = 0;
	char auxApellido[20];
	if (this != NULL && esString(apellido) && strlen(apellido) < 50 && strlen(apellido) > 1)
	{
		strcpy(auxApellido, apellido);
		strlwr(auxApellido);
		auxApellido[0] = toupper(auxApellido[0]);
		strcpy(this->apellido, auxApellido);
		retorno = 1;
	}

	return retorno;
}
int Passenger_getApellido(Passenger *this, char *apellido)
{
	int retorno = 0;
	if (this != NULL && apellido!= NULL) {
		strcpy(apellido, this->apellido);
		retorno = 1;
	}
	return retorno;
}


int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo)
{
	int retorno = 0;
	if (this != NULL && codigoVuelo != NULL && esAlfanumerica(codigoVuelo) && strlen(codigoVuelo)<8 && strlen(codigoVuelo)>6)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo)
{
	int retorno = 0;
	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero)
{
	int retorno = 0;
	if(this != NULL && tipoPasajero >=1 && tipoPasajero <= 3)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 1;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero)
{
	int retorno = 0;
	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 1;
	}
	return retorno;
}
int Passenger_setEstatus(Passenger *this, int statusFlight)
{
	int retorno = 0;
	if(this != NULL && statusFlight >=1 && statusFlight <= 4)
	{
		this->statusFlight = statusFlight;
		retorno = 1;
	}
	return retorno;
}

int Passenger_getEstatus(Passenger *this, int* statusFlight)
{
	int retorno = 0;
	if(this != NULL && statusFlight != NULL)
	{
		*statusFlight = this->statusFlight;
		retorno = 1;
	}
	return retorno;
}

int Passenger_getTipoStringPasajero(Passenger *this, char *tipoPasajero)
{
	int retorno = 0;
	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 1;
		switch(this->tipoPasajero)
		{
		case 1:
			strcpy(tipoPasajero,"FirstClass");
			break;
		case 2:
			strcpy(tipoPasajero,"ExecutiveClass");
			break;
		case 3:
			strcpy(tipoPasajero,"EconomyClass");
			break;
		default:
			retorno = 0;
			break;
		}
		retorno = 1;
	}
	return retorno;
}
int Passenger_getStatusStringPasajero(Passenger *this, char *StatusString)
{
	int retorno = 0;
	if(this != NULL && StatusString != NULL)
	{
		retorno = 1;
		switch(this->statusFlight)
		{
		case 1:
			strcpy(StatusString,"Aterrizado");
			break;
		case 2:
			strcpy(StatusString,"En horario");
			break;
		case 3:
			strcpy(StatusString,"En Vuelo");
			break;
		case 4:
			strcpy(StatusString,"Demorado");
			break;
		default:
			retorno = 0;
			break;
		}
		retorno = 1;
	}
	return retorno;
}
int Passenger_getTypeStringPasajero(Passenger *this, char *typePassenger)
{
	int retorno = 0;
		if(this != NULL && typePassenger != NULL)
		{
			retorno = 1;
			switch(this->tipoPasajero)
			{
			case 1:
				strcpy(typePassenger,"FirstClass");
				break;
			case 2:
				strcpy(typePassenger,"ExecutiveClass");
				break;
			case 3:
				strcpy(typePassenger,"EconomyClass");
				break;
			default:
				retorno = 0;
				break;
			}
			retorno = 1;
		}
		return retorno;
}
int Passenger_getIntStatusFromString(char* stringStatus,int* statusInt)
{
	int retorno = 0;		//0          1           2         3
	char status[4][50]={"Aterrizado","En horario","En Vuelo","Demorado"};
	if (stringStatus != NULL && statusInt != NULL)
	{
		for (int i = 0; i < 4; i++)
		{
			if(stricmp(status[i],stringStatus) == 0)
			{
				*statusInt = i+1;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
int Passenger_getIntTypePassengerFromString(char* typeString,int* typeInt)
{
	int retorno = 0;		//0            1                2
	char typePassenger[3][50]={"FirstClass","ExecutiveClass","EconomyClass"};
	if (typeString!= NULL && typeInt!= NULL)
	{
		for (int i = 0; i < 3; i++)
		{
			if(stricmp(typePassenger[i],typeString) == 0)
			{
				*typeInt = i+1;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = 0;
	if (this != NULL && precio>= 1000 && precio <= 100000)
	{
		this->precio = precio;
		retorno = 1;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger *this, float *precio)
{
	int retorno = 0;
	if (this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}
//gestion Id
int ObtenerUltimoId(char* path, int* id)
{
	int retorno = 0;
	if(path != NULL && id != NULL)
	{
		FILE* f = fopen (path,"rb");
		if (f != NULL)
		{
			fread(id,sizeof(int),1,f);
			fclose(f);
			retorno = 1;
		}

	}
	return retorno;
}
int GuardarUltimoId(char* path, int* id)
{
	int retorno = 0;
	if(path != NULL && id != NULL)
	{
		FILE* f = fopen (path,"wb");
		if (f != NULL)
		{
			fwrite(id,sizeof(int),1,f);
			fclose(f);
			retorno = 1;
		}

	}
	return retorno;
}
// Comparadoras
int Passenger_sortId(void* x, void* y)
{
	int retorno = 0;
	Passenger* empleadoA = NULL;
	Passenger* empleadoB = NULL;
	if (x != NULL && y != NULL)
	{
		empleadoA = (Passenger*) x;
		empleadoB = (Passenger*) y;

	}
	if (empleadoA->id< empleadoB->id)
	{
		retorno = -1;
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}
int Passenger_sortName(void* x, void* y)
{
	int retorno = 0;
	Passenger* empleadoA = NULL;
	Passenger* empleadoB = NULL;
	if (x != NULL && y != NULL)
	{
		empleadoA = (Passenger*) x;
		empleadoB = (Passenger*) y;
		retorno = stricmp (empleadoA->nombre,empleadoB->nombre);
	}
	return retorno;
}
int Passenger_sortLastName(void* x, void* y)
{
	int retorno = 0;
	Passenger* empleadoA = NULL;
	Passenger* empleadoB = NULL;
	if (x != NULL && y != NULL)
	{
		empleadoA = (Passenger*) x;
		empleadoB = (Passenger*) y;
		retorno = stricmp (empleadoA->apellido,empleadoB->apellido);
	}
	return retorno;
}
int Passenger_sortTypePassenger(void* x, void* y)
{
	int retorno = 0;
	Passenger* empleadoA = NULL;
	Passenger* empleadoB = NULL;
	if (x != NULL && y != NULL)
	{
		empleadoA = (Passenger*) x;
		empleadoB = (Passenger*) y;
		if (empleadoA->tipoPasajero < empleadoB->tipoPasajero)
		{
			retorno = -1;
		}
		else
		{
			if (empleadoA->tipoPasajero > empleadoB->tipoPasajero)
			{
				retorno = 1;
			}

		}

	}
	return retorno;
}
int Passenger_sortStatusFlight(void* x, void* y)
{
	int retorno = 0;
	Passenger* empleadoA = NULL;
	Passenger* empleadoB = NULL;
	if (x != NULL && y != NULL)
	{
		empleadoA = (Passenger*) x;
		empleadoB = (Passenger*) y;
		if (empleadoA->statusFlight < empleadoB->statusFlight)
		{
			retorno = -1;
		}
		else
		{
			if (empleadoA->statusFlight > empleadoB->statusFlight)
			{
				retorno = 1;
			}

		}

	}
	return retorno;
}
int Passenger_sortPrice(void* x, void* y)
{
	int retorno = 0;
	Passenger* empleadoA = NULL;
	Passenger* empleadoB = NULL;
	if (x != NULL && y != NULL)
	{
		empleadoA = (Passenger*) x;
		empleadoB = (Passenger*) y;
		if (empleadoA->precio < empleadoB->precio)
		{
			retorno = -1;
		}
		else
		{
			if (empleadoA->precio > empleadoB->precio)
			{
				retorno = 1;
			}

		}

	}


	return retorno;
}
int Passenger_sortFlycode(void* x, void* y)
{
	int retorno = 0;
	Passenger* empleadoA = NULL;
	Passenger* empleadoB = NULL;
	if (x != NULL && y != NULL)
	{
		empleadoA = (Passenger*) x;
		empleadoB = (Passenger*) y;
		retorno = stricmp (empleadoA->codigoVuelo,empleadoB->codigoVuelo);
	}
	return retorno;
}

