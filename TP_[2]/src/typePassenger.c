/*
 * typePassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: Acost
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typePassenger.h"
int listarTipoPasajero(eTypePassenger tipos[],int cantTipos)
{

    int retorno = -1;
    if (tipos != NULL && cantTipos > 0)
    {
        printf(" ***Tipo de pasajero ***\n\n");
        printf("CODIGO      ESTADO\n");
        printf("-----------------------\n");
        for (int i = 0; i < cantTipos; i++ )
        {
            printf("%d         %s\n",tipos[i].idTypePassenger,tipos[i].desc);
        }
        retorno = 0;
    }
    return retorno;

}
int cargarDescTypePassenger(eTypePassenger tipos[],int tamTipos, int idTipo, char vec[])
{
    int retorno = -1;
    if (tipos != NULL && tamTipos > 0 && idTipo >0 && vec != NULL)
    {
        for (int i = 0; i < tamTipos; i++)
        {
            if (tipos[i].idTypePassenger == idTipo)
            {
                strcpy(vec,tipos[i].desc);
                retorno = 0;
                break;
            }
        }

    }
    return retorno;
}

