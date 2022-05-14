/*
 * statusFlight.c
 *
 *  Created on: 14 may. 2022
 *      Author: Acost
 */

#include "statusFlight.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ListarStatus(eStatusFlight estados[],int cantEst)
{
    int retorno = -1;
    if (estados != NULL && cantEst > 0)
    {
        printf(" ***STATUS FLIGHT ***\n\n");
        printf("CODIGO      ESTADO\n");
        printf("-----------------------\n");
        for (int i = 0; i < cantEst; i++ )
        {
            printf("%d         %s\n",estados[i].idStatus,estados[i].desc);
        }
        retorno = 0;
    }
    return retorno;
}
int cargarDescripccionStatus(eStatusFlight estados[],int cantEst,int idEst,char descripccion[])
{
    int retorno = -1;
    if (estados!= NULL && cantEst > 0 && idEst >= 0 && idEst <=4 && descripccion != NULL)
    {
        for (int i = 0; i < cantEst; i++)
        {
            if (estados[i].idStatus == idEst)
            {
                strcpy(descripccion,estados[i].desc);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

