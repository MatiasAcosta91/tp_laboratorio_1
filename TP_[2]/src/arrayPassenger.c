/*
 * arrayPassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: Acost
 */
#include "arrayPassenger.h"
#include "ingresos_Validaciones.h"
#include "menu.h"
#include "statusFlight.h"
#include "calculos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define INTENTOSINF -1

/**
 * @brief permite mostrar la informacion de un unico pasajero
 *
 * @param pasajero ePassejger pasajero que sera mostrado
 * @param estatus
 * @param tamStatus
 * @param tiposPasajero
 * @param cantTipo
 * @return
 */static int printOnePassenger (ePassenger pasajero,eStatusFlight estatus[],int tamStatus,eTypePassenger tiposPasajero[],int cantTipo)
{
    int retorno = -1;
    char estadoAux[20];
    char TypePassengerAux[20];
    if (estatus != NULL && tamStatus > 0)
    {
        cargarDescripccionStatus(estatus,tamStatus,pasajero.statusFlight,estadoAux);
        cargarDescTypePassenger(tiposPasajero,cantTipo,pasajero.typePassenger,TypePassengerAux);
        printf("%d    %10s      %10s   %15s     %10.2f     %10s     %15s\n",pasajero.id,pasajero.lastName,pasajero.name,TypePassengerAux,pasajero.price,pasajero.flycode,estadoAux);
        retorno = 0;
    }
    return retorno;
}
static int swapPassengers (ePassenger* list, int pos1, int pos2, int len)
{
    int retorno = -1;
    ePassenger aux;
    if (list != NULL && pos1 >= 0 && pos1<len && pos2 >= 0 && pos2 <len)
    {
        aux = list[pos1];
        list[pos1] = list[pos2];
        list[pos2] = aux;
        retorno = 0;
    }
    return retorno;
}

int buscarLibre (ePassenger* list,int len)
{
    int retorno = -1;
    if (list != NULL && len >0)
    {
        for (int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}
int initPassengers(ePassenger* list, int len)
{
    int retorno = -1;
    if(list != NULL && len >0)
    {
        for (int i = 0; i < len; i++)
        {
            list[i].isEmpty =  1;
        }
        retorno = 0;
    }
    return retorno;
}
int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int status,eStatusFlight estados[], int cantEst,eTypePassenger tipos[], int cantTipos)
{
    int retorno = 0;
    int posLibre;
    char confirmaAlta;
    char auxTipo[20];
    char auxStatus[20];
    if (list != NULL && len > 0 && id >=0 && name != NULL && lastName != NULL && price > 0 && typePassenger >0 && typePassenger <= 3 && flycode != NULL && status >= 0 && status <= 4)
    {
        posLibre=buscarLibre(list,len);
        if ( posLibre >= 0 && posLibre < len)
        {
            cargarDescripccionStatus(estados,cantEst,status,auxStatus);
            cargarDescTypePassenger(tipos,cantTipos,typePassenger,auxTipo);
            printf("ID        APELLIDO          NOMBRE    TIPO DE PASAJERO     PRECIO        FLYCODE      ESTADO DE VUELO\n");
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("%d   %10s      %10s   %15s     %10.2f   %10s   %15s\n",id,lastName,name,auxTipo,price,flycode,auxStatus);
            printf("\n\nConfirma el alta del pasajero? (s/n): ");
            fflush(stdin);
            scanf("%c",&confirmaAlta);
            while (confirmaAlta != 's' && confirmaAlta != 'n')
            {
                printf("ERROR: Ingrese s/n: ");
                fflush(stdin);
                scanf("%c",&confirmaAlta);
                confirmaAlta = tolower(confirmaAlta);
            }
            if (confirmaAlta == 's')
            {
                list[posLibre].id = id;
                strcpy (list[posLibre].name,name);
                strcpy (list[posLibre].lastName,lastName);
                list[posLibre].price = price;
                strcpy (list[posLibre].flycode,flycode);
                list[posLibre].typePassenger = typePassenger;
                list[posLibre].isEmpty = 0;
                list[posLibre].statusFlight=status;
                printf(" ALTA CONFIRMADA. \n");
                retorno = 1;
            }
        }
    }
    return retorno;
}
int printPassengers(ePassenger* list, int length, eStatusFlight estatus[],int tamStatus,eTypePassenger tiposPasajero[],int cantTipo)
{
    int retorno = 0;
    if (list != NULL && length > 0)
    {
        printf("******************************************************************************************************\n");
        printf("*                              LISTADO          DE          PASAJEROS                                *\n");
        printf("******************************************************************************************************\n");
        printf("ID        APELLIDO          NOMBRE    TIPO DE PASAJERO     PRECIO        FLYCODE      ESTADO DE VUELO\n");
        printf("------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < length; i++)
        {
            if (list[i].isEmpty == 0)
            {
                printOnePassenger(list[i],estatus,tamStatus,tiposPasajero,cantTipo);
                retorno = 1;
            }
        }
        if(!retorno)
        {
            printf("No hay pasajeros para mostrar.\n");
        }
    }
    return retorno;
}

int findPassengerById(ePassenger* list, int len,int id)
{
    int retorno = -1;
    if (list != NULL && len >0 && id >= 1000)
    {
        for (int i = 0; i < len; i++)
        {
            if (list[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int removePassenger(ePassenger* list, int len, int id,eStatusFlight estados[],int cantEst,eTypePassenger tiposPasajero[],int cantTipo)
{
    int retorno = 0;
    int indexBuscado;
    char confirmaBaja;
    if (list != NULL && len > 0 && id >= 0)
    {
        indexBuscado = findPassengerById(list,len,id);
        if (indexBuscado == -1)
        {
            printf("No se encontro el ID.");
        }
        else
        {
            printf("\n");
            printOnePassenger(list[indexBuscado],estados,cantEst,tiposPasajero,cantTipo);
            printf("\n");
            printf("confirma la baja?(s/n): ");
            fflush(stdin);
            scanf("%c",&confirmaBaja);
            fflush(stdin);
            confirmaBaja = tolower(confirmaBaja);
            while (confirmaBaja != 's' && confirmaBaja != 'n')
            {
            printf("ERROR=confirma la baja?(s/n): ");
            fflush(stdin);
            scanf("%c",&confirmaBaja);
            fflush(stdin);
            confirmaBaja = tolower(confirmaBaja);
            }
            if (confirmaBaja == 's')
            {
                list[indexBuscado].isEmpty = 1;
                printf("BAJA CONFIRMADA.\n");
                retorno = 1;
            }
            else
            {
                printf("BAJA CANCELADA\n");
            }
        }
    }
    return retorno;
}
int altaForzada(ePassenger* list,int len, int cant, int* pId)
{
    int retorno = 0;
    int posLibre;
    ePassenger Auxiliares[10] =
    {

        {0000,"Javier","Zapatero",199551.2,"bbbsmd219",1,0,0},
        {0000,"Maria","Acosta",512551.13,"aamckld21",3,3,0},
        {0000,"Angel","Brown",906151.77,"bbcsmeljj",2,2,0},
        {0000,"Mauricio","Cano",32551.2,"aamckld21",3,1,0},
        {0000,"Juan","Alonso",21551,"cczmfje1r",2,0,0},
        {0000,"Esteban","Blanc",41245.98,"bbbsmd219",3,4,0},
        {0000,"Julian","Capello",62551.61,"ddzmfke1",2,1,0},
        {0000,"Pedro","Brown",72551,"zzbjgm11s",1,4,0},
        {0000,"Anibal","Cano",89551.2,"aamckld21",1,2,0},
        {0000,"Carlos","Acosta",142551.2,"cmdk2l10f",1,1,0}

    };
    if (list != NULL && len > 0 && cant >0 && pId != NULL)
    {

        for (int i = 0 ; i < cant; i++)
        {
            posLibre = buscarLibre(list,len);
            if(list[posLibre].isEmpty == 1)
            {
                list[posLibre] = Auxiliares[i];
                list[posLibre].id = *pId;
                (*pId)++;
            }
        }
        retorno  = 1;
    }
    return retorno;
}
int sortPassengers(ePassenger* list, int len, int order) //1 asc 0 desc
{
    int retorno = -1;
    int ordenados;
    int limite = len-1;
    if (list != NULL && len > 0 && (order == 1 || order == 0) )
    {
        do
        {
            ordenados = 1;
            for (int i = 0; i < limite; i ++)
            {
                if ( (order == 1 && ( (stricmp(list[i].lastName,list[i+1].lastName) > 0)  || (stricmp(list[i].lastName,list[i+1].lastName) == 0 && list[i].typePassenger > list[i+1].typePassenger)))

                        ||

                        (order == 0 && ( (stricmp(list[i].lastName,list[i+1].lastName) < 0)  || (stricmp(list[i].lastName,list[i+1].lastName) == 0 && list[i].typePassenger < list[i+1].typePassenger)))
                   )
                {
                    swapPassengers(list,i,i+1,len);
                    ordenados = 0;
                }
            }
            limite --;
        }while(ordenados == 0);
        retorno = 0;
    }
    return retorno;
}
int sortPassengersByCode(ePassenger* list, int len, int order)
{
    int retorno = -1;
    int ordenados;
    int limite = len-1;
    if (list != NULL && len > 0 && (order == 1 || order == 0) )
    {
        do
        {
            ordenados = 1;
            for (int i = 0; i < limite; i++)
            {
                if( (order == 1 && ((stricmp(list[i].flycode,list[i+1].flycode) > 0 ) || (stricmp(list[i].flycode,list[i+1].flycode)== 0 && list[i].statusFlight>list[i+1].statusFlight  )))
                        ||
                        (order == 0 && ((stricmp(list[i].flycode,list[i+1].flycode) < 0 ) || (stricmp(list[i].flycode,list[i+1].flycode)== 0 && list[i].statusFlight<list[i+1].statusFlight  )))
                  )
                {
                    swapPassengers(list,i,i+1,len);
                    ordenados = 0;
                }
            }
            limite --;
        }
        while  (ordenados == 0);
        retorno = 0;
    }
    return retorno;
}
int modifyPassenger(ePassenger* list,int len,eStatusFlight estatus[],int tamStatus,eTypePassenger tiposPasajero[],int cantTipo)
{
    int retorno = 0;
    int idBuscado;
    int indexBuscado;
    char repetir = 's';
    char continuar;
    int flagCambio = 0;
    ePassenger aux;

    if (list!= NULL && estatus != NULL && tiposPasajero != NULL && len >0 && tamStatus >0 && cantTipo >0)
    {

        system("cls");
        printPassengers(list,len,estatus,tamStatus,tiposPasajero,cantTipo);
        pedirId(&idBuscado);
        indexBuscado = findPassengerById(list,len,idBuscado);
        if (indexBuscado >= 0 && indexBuscado < len)
        {
            aux = list[indexBuscado];
            do
            {
                system("cls");
                printf("****************************************************************\n");
                printf("*             M  O  D  I  F  I  C  A  C  I  O  N               *\n");
                printf("****************************************************************\n");
                printf("\n\n");
                printf("ID        APELLIDO          NOMBRE    TIPO DE PASAJERO     PRECIO        FLYCODE      ESTADO DE VUELO\n");
                printf("------------------------------------------------------------------------------------------------------\n");
                printOnePassenger(aux,estatus,tamStatus,tiposPasajero,cantTipo);
                printf("\n\n");

                switch(menuModificacion())
                {
                case 1:
                    pedirNombre(aux.name);
                    flagCambio = 1;
                    break;
                case 2:
                    flagCambio = 1;
                    pedirApellido(aux.lastName);
                    break;
                case 3:
                    flagCambio = 1;
                    pedirPrecio(&aux.price);
                    break;
                case 4:
                    flagCambio = 1;
                    pedirTypePassenger(&aux.typePassenger,tiposPasajero,cantTipo);
                    break;
                case 5:
                    flagCambio = 1;
                    pedirFlycode(aux.flycode);
                    break;
                case 6:
                    if(flagCambio)
                    {
                        list[indexBuscado] = aux;
                        printf("Cambio Confirmado.\n");
                        flagCambio = 0;

                    }
                    else
                    {
                        printf("No se realizo ningun cambio.");
                    }

                    break;
                case 7:
                    if (flagCambio)
                    {

                        printf("Si no guarda los cambios se perderan. esta seguro que desea continuar?(s/n): ");
                        fflush(stdin);
                        scanf("%c",&continuar);
                        while (continuar !='s' && continuar != 'n')
                        {
                            printf("Opcion incorrecta ingrese s/n: ");
                            fflush(stdin);
                            scanf("%c",&continuar);
                        }
                        if (continuar =='s')
                        {
                            repetir = 'n';
                        }
                    }
                    else
                    {
                        repetir = 'n';
                    }

                    break;
                default:
                    printf("Opcion incorrecta");
                    break;
                }
                system("pause");
            }
            while (repetir == 's');
        }
        else
        {
            printf("No se encontro el pasajero.");
        }
    }
    return retorno;
}
int informar(ePassenger* list, int len,eStatusFlight estatus[],int tamStatus,eTypePassenger tipos[],int tamTipos)
{
    int retorno = -1;
    char continuar = 's';
    float precioTotal;
    float precioProm;
    int flagVueloActivo = 0;
    int flagMayorProm = 0;
    if (list != NULL && len > 0)
    {
        do
        {
            switch(menuInformar())
            {
            case 1:
                sortPassengers(list,len,1);
                printPassengers(list,len,estatus,tamStatus,tipos,tamTipos);
                break;
            case 2:
                printPassengers(list,len,estatus,tamStatus,tipos,tamTipos);
                calcularPrecioTot(list,len,&precioTotal);
                calcularPrecioProm(list,len,&precioProm);

                printf("\n\nPrecio total de todos los pasajeros: %.2f\n",precioTotal);
                printf("\nPrecio promedio de los vuelos: %.2f\n",precioProm);
                printf("\nListado de pasajeros que superan el precio promedio.\n\n\n");
                printf("ID        APELLIDO          NOMBRE    TIPO DE PASAJERO     PRECIO        FLYCODE      ESTADO DE VUELO\n");
                printf("------------------------------------------------------------------------------------------------------\n");
                for (int i = 0; i < len; i++)
                {
                    if (list[i].isEmpty == 0 && list[i].price>precioProm )
                    {
                        printOnePassenger(list[i],estatus,tamStatus,tipos,tamTipos);
                        flagMayorProm = 1;
                    }

                }
                if (!flagMayorProm)
                {
                    printf("\n\nNingun pasajero supera el precio promedio.\n\n");
                }
                break;
            case 3:
                sortPassengersByCode(list,len,1);
                printf("ID        APELLIDO          NOMBRE    TIPO DE PASAJERO     PRECIO        FLYCODE      ESTADO DE VUELO\n");
                printf("------------------------------------------------------------------------------------------------------\n");
                for (int i = 0; i < len; i++)
                {
                    if (list[i].isEmpty == 0 && list[i].statusFlight == 1 )
                    {
                        printOnePassenger(list[i],estatus,tamStatus,tipos,tamTipos);
                        flagVueloActivo = 1;
                    }

                }
                if(!flagVueloActivo)
                {
                    printf("No hay pasajeros en vuelo activo.\n*");
                }
                break;
            case 4:
                continuar = 'n';
                break;
            default:
                printf("Opcion incorrecta.\n");
                break;
            }
            system("pause");
        }
        while (continuar =='s');

        retorno = 0;
    }
    return retorno;
}



