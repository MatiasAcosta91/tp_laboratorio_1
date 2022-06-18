#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "manipularPasajeros.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPaassenger)
{
	int retorno = 0;
	char encabezado[150];
	fscanf(pFile,"%s\n",encabezado);
	int lecturas;
	char matrizAux[7][50];
	Passenger* auxNuevo;
	int typePassengerInt;
	int statusFligthInt;
	while (!feof(pFile))
	{													   					// id            nombre      apellido      precio       flycode   typePasenger   statusFlight
		lecturas = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",matrizAux[0],matrizAux[1],matrizAux[2],matrizAux[3],matrizAux[4],matrizAux[5],matrizAux[6]);
		if (lecturas == 7)
		{
			Passenger_getIntStatusFromString(matrizAux[6], &statusFligthInt);
			Passenger_getIntTypePassengerFromString(matrizAux[5], &typePassengerInt);
						                               //id        nombre       apellido          precio            flycode       typePaseenger    statusFligth
			auxNuevo = Passenger_newParametros(atoi(matrizAux[0]),matrizAux[1],matrizAux[2],atof( matrizAux[3]),(matrizAux[4]),typePassengerInt,statusFligthInt);
			if(auxNuevo != NULL)
			{
				ll_add(pArrayListPaassenger, auxNuevo);
				auxNuevo = NULL;
				retorno +=1;

			}

		}

	}
	//ACA SE HARIA EL FSCANF para leer el archivo y despues hago lladd para guardarlo en el linkedlist
    return retorno;
}
int parser_TextFromPassenger(FILE* pFile , LinkedList* pArrayListPaassenger)
{
	int retorno = 0;
	Passenger *aux = NULL;
	int len = ll_len(pArrayListPaassenger);
	char auxType[20];
	char auxStatus[20];
	if (pFile != NULL && pArrayListPaassenger!= NULL)
	{
		fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for (int i = 0; i <len ;i++)
		{
			aux=ll_get(pArrayListPaassenger,i);
			if (aux != NULL)
			{
			Passenger_getTypeStringPasajero(aux, auxType);
			Passenger_getStatusStringPasajero(aux, auxStatus);
			fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",aux->id,aux->nombre,aux->apellido,aux->precio,aux->codigoVuelo,auxType,auxStatus);
			retorno ++;
			}

		}
	}
	return retorno;
}


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	Passenger* aux = NULL;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			aux = Passenger_new();
			if (aux != NULL)
			{
				if (fread(aux,sizeof(Passenger),1,pFile) == 1 )
				{
					ll_add(pArrayListPassenger, aux);
					aux = NULL;
					retorno ++;
				}
			}
		}

	}
//ACA SE HARIA EL FREAD, despues lladd para guartdarlo en linkedlist
    return retorno;
}
int parser_binaryFromPassenger(FILE* pFile , LinkedList* pArrayListPaassenger)
{
	int retorno = 0;
	Passenger* aux = NULL;
	int len;
	if (pFile!= NULL && pArrayListPaassenger != NULL)
	{
		len = ll_len(pArrayListPaassenger);
		for (int i = 0; i < len; i++)
		{
			aux = ll_get(pArrayListPaassenger, i);
			if (aux != NULL)
			{
				fwrite(aux,sizeof(Passenger),1,pFile);
				retorno ++;
			}
		}
	}


	return retorno;
}


























