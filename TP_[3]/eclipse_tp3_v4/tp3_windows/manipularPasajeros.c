/*
 * manipularPasajeros.c
 *
 *  Created on: 11 jun. 2022
 *      Author: Acost
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "manipularPasajeros.h"
#include "LinkedList.h"
#include "utn.h"
#include "ingresos.h"
#include "menu.h"
#define INTENTOS_INF -1

int mostrarPassengers (LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int len = ll_len(pArrayListPassenger);
	if (pArrayListPassenger != NULL && len >0)
	{
		printf("ID        NOMBRE        APELLIDO     PRECIO     CODIGO DE VUELO     TIPO DE PASaAJERO      ESTATUS\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i < len ; i++)
		{
			mostrarPassenger(ll_get(pArrayListPassenger,i));
			retorno = 1;
		}

	}
	return retorno;
}
int mostrarPassenger(Passenger* passenger)
{
	int retorno = 0;
	char auxStringTipo[20];
	char auxStringStatus[20];
	if (passenger != NULL)
	{
		Passenger_getTipoStringPasajero(passenger,auxStringTipo);
		Passenger_getStatusStringPasajero(passenger, auxStringStatus);
		printf("%d   %10s    %10s   %10.2f   %15s   %15s   %20s\n",passenger->id,passenger->nombre,passenger->apellido,passenger->precio,passenger->codigoVuelo,auxStringTipo,auxStringStatus);
		retorno = 1;
	}
	return retorno;
}

int buscarPassengerId(LinkedList* pArrayListPassenger,int idBuscado)
{
	int index=-1;
	if (pArrayListPassenger !=NULL && idBuscado>0)
	{
		Passenger* aux = NULL;
		for (int i = 0; i <ll_len(pArrayListPassenger); i++)
		{
			aux = ll_get(pArrayListPassenger,i);
			if (aux->id == idBuscado)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
int AltaPasajero(LinkedList* pArrayListPassenger,int* pLastId)
{
	int retorno = 0;
	char confirmaAlta;
	if(pArrayListPassenger != NULL && pLastId != NULL)
	{
		Passenger* aux = Passenger_new();
		if (aux != NULL)
		{//
			if( Passenger_SolicitarDatos(aux->nombre, aux->apellido,&aux->precio,&aux->tipoPasajero,aux->codigoVuelo,&aux->statusFlight))
			{
				mostrarPassenger(aux);
				printf("Confirma Alta? s/n: ");
				fflush(stdin);
				scanf("%c",&confirmaAlta);
				confirmaAlta = tolower(confirmaAlta);
				while (confirmaAlta!='s' && confirmaAlta!='n')
				{
					printf("ERROR= Confirma Alta?, ingrese s/n: ");
					fflush(stdin);
					scanf("%c",&confirmaAlta);
				}
				if(confirmaAlta == 's')
				{
					(*pLastId)++;
					aux->id = *pLastId;
					ll_add(pArrayListPassenger, aux);
					aux = NULL;
					retorno = 1;
				}
			}
		}
	}
    return retorno;
}

int bajaPasajero (LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int idBuscado;
	int indexBuscado;
	char confirmaBaja;
	char MensajeId[]="Ingrese Id: ";
	char MensajeError[]="ERROR = ";
	Passenger* aux = NULL;
	if (pArrayListPassenger != NULL)
	{
		mostrarPassengers(pArrayListPassenger);
		utn_getNumeroInt(&idBuscado, MensajeId, MensajeError, 1, 10000,INTENTOS_INF);
		indexBuscado = buscarPassengerId(pArrayListPassenger, idBuscado);
		if(indexBuscado == -1)
		{
			printf("No se encontro el Id igresado");
		}
		else
		{
				aux = ll_get(pArrayListPassenger,indexBuscado);
				if (aux != NULL)
				{
					mostrarPassenger(aux);
					printf("Confirma Baja? s/n: ");
					fflush(stdin);
					scanf("%c",&confirmaBaja);
					confirmaBaja = tolower(confirmaBaja);
					while (confirmaBaja!='s' && confirmaBaja!='n')
					{
						printf("ERROR= Confirma Baja?, ingrese s/n: ");
						fflush(stdin);
						scanf("%c",&confirmaBaja);
					}
					if(confirmaBaja == 's')
					{
						retorno = 1;
						ll_remove(pArrayListPassenger, indexBuscado);
					}
				}
		}

	}
	return retorno;
}
int modificarPasajero(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	char mensajeId[]="Ingrese el id a buscar ,0 para salir: ";
	char mensajeNombre[]="Ingrese nueva nombre: ";
	char mensajeApellido[]="Ingrese nuevo apellido: ";
	char mensajePrecio[]="Ingrese  nuevo Precio entre 1000 y 100000:  ";
	char mensajeTipoPasajero[]="1_FirstClass\n2_ExecutiveClass\n3_EconomyClass\nIngrese tipo de pasajero : \n";
	char mensajeCodigoVuelo[]="Ingrese nuevo Codigo de vuelo: ";
	char mensajeStatus[]="1_Aterrizado.\n2_En horario.\n3_En vuelo.\n4_Demorado.\n Ingrese el estado de vuelo: ";
	char mensajeError[]="Error=";
	int idBuscado;
	int indexEncontrado;
	char continuar = 's';
	Passenger* auxCambios = Passenger_new(); //Creo pas dinamico donde voy a realizar los cambios
	Passenger* aux = NULL;// puntero para guardar la referencia del indice encontrado.
	if (auxCambios != NULL && pArrayListPassenger != NULL)
	{
		mostrarPassengers(pArrayListPassenger); // MUESTRO PASAJEROS
		utn_getNumeroInt(&idBuscado, mensajeId, mensajeError, 0, 10000,INTENTOS_INF); //SOLICITO ID
		if (idBuscado)
		{
			indexEncontrado = buscarPassengerId(pArrayListPassenger, idBuscado);//BUSCO ID
			if(indexEncontrado == -1)
			{
				printf("No se encontro el Id igresado\n");
			}
			else
			{
				aux = ll_get(pArrayListPassenger, indexEncontrado);//guardo la referencia del indice encontrado
				*auxCambios = * aux;//copio el contenido del puntero en el auxiliar donde realizo los cambios
				do
				{//SI ENCUENTRO ID ACCEDO A MENU DE MODIFICACION
					system("cls");
					printf("*******************************************************************************\n");
					printf("*                     M E N U        M O D I F I C A C I O N                  *\n");
					printf("*******************************************************************************\n\n");
					printf("ID        NOMBRE        APELLIDO     PRECIO     CODIGO DE VUELO     TIPO DE PASaAJERO      ESTATUS\n");
					printf("--------------------------------------------------------------------------------------------------\n");
					mostrarPassenger(auxCambios); //MUESTRO COPIA DEL PASAJERO ENCONTRADO
					switch(menuModificacion())
					{
					case 1://cambiar nombre
						utn_getNombreOApellido(auxCambios->nombre,mensajeNombre, mensajeError, 3, 49, INTENTOS_INF);
						break;
					case 2://cambiar apellido
						utn_getNombreOApellido(auxCambios->apellido, mensajeApellido, mensajeError, 2, 49,INTENTOS_INF);
						break;
					case 3://cambiar precio
						utn_getNumeroFloat(&auxCambios->precio, mensajePrecio, mensajeError, 1000, 100000, INTENTOS_INF);
						break;
					case 4://cambiar tipo pasajero
						utn_getNumeroInt(&auxCambios->tipoPasajero, mensajeTipoPasajero, mensajeError,1, 3, INTENTOS_INF);
						break;
					case 5://cambiar codigo de vuelo
						utn_getAlfanumerico(auxCambios->codigoVuelo, mensajeCodigoVuelo, mensajeError, 7, 7, INTENTOS_INF);
						break;
					case 6://cambiar estado de vuelo
						utn_getNumeroInt(&auxCambios->statusFlight,mensajeStatus, mensajeError,1, 4,INTENTOS_INF);
						break;
					case 7://confirmar cambios
						*aux = *auxCambios;//COPIO EL CONTENIDO DEL AUXILIAR MODIFIOCADO EN EL PUNTERO DEL INDICE ENCONTRADO
						Passenger_delete(auxCambios);
						auxCambios = NULL;
						retorno = 1;
						break;
					case 8:
						continuar= 'n';
						break;
					default:
						break;
					}

				}while (continuar == 's');
			}
		}


	}
	return retorno;
}




int ordenarPasajero(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int seguir = 1;
	if (pArrayListPassenger != NULL)
	{
		retorno = 1;
		do
		{
			system("cls");
			switch (menuOrdenamiento())
			{
			case 1:
				printf("Cargando...\n");
				ll_sort(pArrayListPassenger,Passenger_sortId,1);
				break;
			case 2:
				printf("Cargando...\n");
				ll_sort(pArrayListPassenger,Passenger_sortName,1);
				break;
			case 3:
				printf("Cargando...\n");
				ll_sort(pArrayListPassenger,Passenger_sortLastName,1);
				break;
			case 4:
				printf("Cargando...\n");
				ll_sort(pArrayListPassenger,Passenger_sortPrice,1);
				break;
			case 5:
				printf("Cargando...\n");
				ll_sort(pArrayListPassenger,Passenger_sortTypePassenger,1);
				break;
			case 6:
				printf("Cargando...\n");
				ll_sort(pArrayListPassenger,Passenger_sortFlycode,1);
				break;
			case 7:
				printf("Cargando...\n");
				ll_sort(pArrayListPassenger,Passenger_sortStatusFlight,1);
				break;
			case 8:
				seguir = 0;
				break;
			default:
				printf("Opcion invalida.\n");
				break;
		}
	system("pause");
	}while (seguir == 1);


	}
	return retorno;
}
