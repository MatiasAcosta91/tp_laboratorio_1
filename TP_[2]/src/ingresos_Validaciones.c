/*
 * ingresos_Validaciones.c
 *
 *  Created on: 14 may. 2022
 *      Author: Acost
 */
#include "ingresos_Validaciones.h"
#include "arrayPassenger.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define INTENTOSINF -1


int pedirDatos (ePassenger* aux,eStatusFlight estados[],int cantEst,eTypePassenger tiposPasajero[],int cantTipo)
{
	int retorno = 0;
	if (aux !=  NULL && estados != NULL && tiposPasajero != NULL && cantEst >0 && cantTipo >0)
	{
		  printf("******************************************************************************************************\n");
		    printf("*                                A L T A   D E   P A S A J E R O                                     *\n");
		    printf("******************************************************************************************************\n");
		    pedirNombre(aux->name);
		    pedirApellido(aux->lastName);
		    pedirPrecio(&aux->price);
		    pedirFlycode(aux->flycode);
		    pedirTypePassenger(&aux->typePassenger,tiposPasajero,cantTipo);
		    pedirStatusFlight(&aux->statusFlight,estados,cantEst);
		    retorno = 1;
	}

    return retorno;
}
int pedirNombre (char* nombre)
{
	int retorno = 0;
	if(nombre != NULL)
	{
		 char mensajeNombre[]={"Ingrese nombre (4 A 20 letras):"};
		    char mensajeError[]={"ERROR: El nombre ingresado es invalido.\n"};
		    utn_getNombreOApellido(nombre,mensajeNombre,mensajeError,4,20,INTENTOSINF );
		    retorno = 1;
	}

    return retorno;
}
int pedirApellido (char* apellido)
{
	int retorno = 0;
		if(apellido != NULL)
		{
    char mensajeNombre[]={"Ingrese Apellido :"};
    char mensajeError[]={"ERROR: El Apellido ingresado es invalido.\n"};
    utn_getNombreOApellido(apellido,mensajeNombre,mensajeError,4,20,INTENTOSINF );
		retorno = 1;
		}
    return retorno;

}
int pedirPrecio (float* precio)
{
	int retorno = 0;
		if(precio!= NULL)
		{
    char mensajePrecio[]={"Ingrese Precio mayor a cero (maximo 500.000): "};
    char mensajeError[]={"ERROR: "};
    utn_getNumeroFloat(precio,mensajePrecio,mensajeError,1,500000,INTENTOSINF );
    retorno = 1;
		}
    return retorno;

}

int pedirFlycode (char* flycode)
{
	int retorno = 0;
		if(flycode != NULL)
		{
    char mensajeFlycode[]={"Ingrese codigo de  vuelo alfanumerico de 5 a 9 digitos: "};
    char mensajeError[]={"ERROR: "};
    utn_getAlfanumerico(flycode,mensajeFlycode,mensajeError,5,9,INTENTOSINF );
    retorno = 1;
		}
    return retorno;

}
int pedirTypePassenger(int* typePassenger,eTypePassenger tiposPasajero[],int cantTipo)
{
	int retorno = 0;
	if(typePassenger != NULL && tiposPasajero != NULL && cantTipo>0)
	{
		listarTipoPasajero(tiposPasajero,cantTipo);
		char mensajeTypePassenger[]= {"Ingrese tipo de pasajero: "};
		char mensajeError[]={"ERROR: "};
		utn_getNumeroInt(typePassenger,mensajeTypePassenger,mensajeError,1,3,INTENTOSINF );
		retorno = 1;
	}
    return retorno;
}
int pedirStatusFlight(int* statusFlight,eStatusFlight estados[],int cantEst)
{
	int retorno = 0;
		if(statusFlight != NULL && estados != NULL && cantEst >0)
		{
    ListarStatus(estados,cantEst);
    char mensajeStatusFligth[]={"Ingrese estado de vuelo: "};
    char mensajeError[]={"ERROR: "};
    utn_getNumeroInt(statusFlight,mensajeStatusFligth,mensajeError,0,4,INTENTOSINF );
    retorno = 1;
		}
    return retorno;

}
int pedirId (int* id)
{
	int retorno = 0;
		if(id != NULL)
		{
    char mensajeId[]={"Ingrese el ID a partir de 1000:"};
    char mensajeError[]={"ERROR: "};
    utn_getNumeroInt(id,mensajeId,mensajeError,1000,9999999,INTENTOSINF );
    retorno = 1;
		}
    return retorno;
}


/** \brief lee desde la entrada hasta que se encuentra un \n o  hasta que haya copiado la cadena con un maximo de longitud.
 *
 * \param  cadena char* puntero donde se copiara la cadena obtenida,
 * \param len int longitud de la cadena buffer
 * \param maxCaracteres int, cantidad maxima de caracteres que escribira, tener el cuenta el \0, por lo cual escribira maxcaracteres-1
 * \return retoirno int -1 en caso de error 0 si salio todo Ok.
 *
 */

static int myGets (char* cadena, int len)
{
    int retorno = 0;
    if (cadena != NULL && len >0)
    {
        fflush(stdin);
        fgets(cadena,len,stdin); //f gets tambien toma el ENTER del buffer de entrada stdin,
        if(cadena[strlen(cadena)-1] == '\n')//elimino el enter que toma fgets
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        retorno = 1;

    }
    return retorno;
}
/** \brief verifica si la cadena ingresada solo contiene letras y numeros sin caracteres especiales.
 *
 * \param cadena char* cadena de caracteres que sera analizada
 * \return int 1 (EXITO) la cadena solo tiene letras o numeros, 0 (ERROR) la cadena contiene caracteres especiales.
 *
 */
static int esAlfanumerica (char* cadena)
{
    int retorno = 1;
    if(cadena != NULL && strlen(cadena)>0)
    {
        for (int i = 0; cadena[i] != '\0'; i++)
        {

            if ( cadena[i] < '0' || (cadena [i] > '9' && cadena[i] < 'A')  || (cadena [i] > 'Z' && cadena[i] < 'a') || cadena[i] >'z')
            {
                retorno = 0;
                break;
            }
            if (i == 0)
            {
                cadena[i] = toupper(cadena[i]);
            }
            else
            {
                cadena[i] = tolower(cadena[i]);
            }
        }
    }

    return retorno;
}

/** \brief verifica si la cadena ingresada solo contiene letras y le otorga formato poniendo en mayuscula el caracter del indice 0 y en minusculas los siguientes ej: Juan.
 *
 * \param cadena char* cadena de caracteres que sera analizada
 * \return int 1 (EXITO) la cadena solo tiene letras, 0 (ERROR).
 *
 */
static int esString(char* cadena)
{
    int retorno = 1;
    if(cadena != NULL && strlen(cadena)>0)
    {
        for (int i = 0; cadena[i] != '\0'; i++)
        {

            if ( cadena[i] < 'A' || (cadena [i] > 'Z' && cadena[i] < 'a') || cadena[i] >'z')
            {
                retorno = 0;
                break;
            }
            if (i == 0)
            {
                cadena[i] = toupper(cadena[i]);
            }
            else
            {
                cadena[i] = tolower(cadena[i]);
            }
        }
    }

    return retorno;
}

/** \brief verifica si la cadena ingresada es numerica
 *
 * \param cadena char* cadena de caracteres que sera analizada
 * \return int 1 (EXITO) la cadena es numerica, 0 (ERROR) la cadena no es numerica
 *
 */
static int esNumerica(char* cadena)
{
    int retorno = 1;
    int i=0;
    if(cadena != NULL && strlen(cadena)>0)
    {
        if (cadena[0] == '-' || cadena [0] == '+')
        {
            i = 1;
        }
        for (; cadena[i] != '\0'; i++)
        {

            if (cadena[i] > '9' || cadena [i] < '0' )
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}
/** \brief verifica si la cadena ingresada es es numerica con decimales y un unico punto
 *
 * \param cadena char* cadena de caracteres que sera analizada
 * \return int 1 (EXITO) la cadena tiene decimales y un unico punto, 0 (ERROR) la cadena no no tiene decimales o tiene mas de un punto
 *
 */
static int esDecimal(char* cadena)
{
    int retorno = 1;
    int i=0;
    int contPuntoComa = 0;
    if(cadena != NULL && strlen(cadena)>0)
    {
        if (cadena[0] == '-' || cadena [0] == '+')
        {
            i = 1;
        }
        for (; cadena[i] != '\0'; i++)
        {
            if(cadena[i] == '.' || cadena[i] == ',')
            {
                contPuntoComa++;
            }
            if ( ((cadena[i] > '9'  || cadena [i] < '0') && cadena[i] != '.' )  ||  contPuntoComa > 1 )

            {

                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}
/** \brief Obtiene un numero una cadena que solo contenga letras desde la terminal.
 *
 * \param pResultado int* donde se devolvera un resultado.
 * \return int 0 en caso de error 1 si salio todo Ok.
 *
 */
static int getString(char* pResultado)
{
    int retorno = 0;
    char buffer[4096];
    if (pResultado != NULL)
    {
        if ( myGets(buffer,sizeof(buffer)) && esString(buffer))
        {
            strcpy(pResultado,buffer);
            retorno = 1;
        }
    }
    return retorno;
}
/** \brief Obtiene un numero entero desde la terminal.
 *
 * \param pResultado int* donde se devolvera un resultado.
 * \return int 0 en caso de error 1 si salio todo Ok.
 *
 */
int getInt(int* pResultado)
{
    int retorno = 0;
    char buffer[4096];
    if (pResultado != NULL)
    {
        if ( myGets(buffer,sizeof(buffer)) && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 1;
        }
    }
    return retorno;
}
/** \brief Obtiene un numero flotante desde la terminal
 *
 * \param pResultado float* donde se devolvera un resultado.
 * \return int 0 en caso de error 1 si salio todo Ok.
 *
 */
 static int getFloat(float* pResultado)
{
    int retorno = 0;
    char buffer[4096];
    if (pResultado != NULL)
    {
        if ( myGets(buffer,sizeof(buffer)) && esDecimal(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief Obtiene una cadena alfanumerica desde la terminal
 *
 * \param pResultado char* donde se devolvera un resultado.
 * \return int 0 en caso de error 1 si salio todo Ok.
 *
 */
static int getAlfanumerico (char* pResultado)
{
    int retorno = -1;
    char buffer[4096];
    if (pResultado != NULL)
    {
        if ( myGets(buffer,sizeof(buffer)) && esAlfanumerica(buffer))
        {
            strcpy(pResultado,buffer);
            retorno = 0;
        }
    }
    return retorno;
}


int utn_getNumeroInt (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = 0;
    int buffer;
    int flagInfinito = 0;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= -1)
    {
        if(reintentos == -1)
        {
            flagInfinito = 1;
        }
        do
        {
            printf("%s",mensaje);
            if (getInt(&buffer) && buffer <= maximo && buffer >= minimo)
            {
                *pResultado = buffer;
                retorno = 1;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos --;
            }

        }
        while (reintentos >= 0 || flagInfinito);
    }
    return retorno;
}
int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
    int retorno = 0;
    float buffer;
    int flagInfinito = 0;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= -1)
    {
        if(reintentos == -1)
        {
            flagInfinito = 1;
        }
        do
        {
            printf("%s",mensaje);
            if (getFloat(&buffer) && buffer <= maximo && buffer >= minimo)
            {
                *pResultado = buffer;
                retorno = 1;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos --;
            }

        }
        while (reintentos >= 0 || flagInfinito);
    }
    return retorno;
}

int utn_getNombreOApellido(char* pResultado, char* mensaje, char* mensajeError,int minCaracteres,int maxCaracteres, int reintentos)
{
    int retorno = 0;
    char buffer[4096];
    int flagInfinito = 0;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= -1)
    {
        if(reintentos == -1)
        {
            flagInfinito = 1;
        }
        do
        {
            printf("%s",mensaje);
            if (getString(buffer) && strlen(buffer) <= maxCaracteres && strlen(buffer) >= minCaracteres )
            {
                strcpy(pResultado,buffer);
                retorno = 1;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos --;
            }

        }
        while (reintentos >= 0 || flagInfinito);
    }
    return retorno;
}

int utn_getAlfanumerico(char* pResultado, char* mensaje, char* mensajeError,int minCaracteres,int maxCaracteres, int reintentos)
{
    int retorno = 0;
    char buffer[4096];
    int flagInfinito = 0;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minCaracteres > 0 && minCaracteres<=maxCaracteres && reintentos >= -1)
    {
        if(reintentos == -1)
        {
            flagInfinito = 1;
        }
        do
        {
            printf("%s",mensaje);
            if (getAlfanumerico(buffer) == 0 && strlen(buffer)>= minCaracteres && strlen(buffer)<=maxCaracteres)
            {
                strcpy(pResultado,buffer);
                retorno = 1;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos --;
            }

        }
        while (reintentos >= 0 || flagInfinito);

    }
    return retorno;
}



