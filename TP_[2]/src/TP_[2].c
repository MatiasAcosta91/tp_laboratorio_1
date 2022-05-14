/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Acosta Matias Jordan DIV 1A
 Version     :
 Copyright   : -
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ingresos_Validaciones.h"
#include "menu.h"
#include "typePassenger.h"
#include "arrayPassenger.h"
#include "calculos.h"
#include "statusFlight.h"
#define MAXPASSENGERS 2000
#define MAX_STATUS 5
#define MAX_TYPE 3

int main(void) {
	setbuf(stdout,NULL);

	 ePassenger vec[MAXPASSENGERS];
	    int nextId = 1000;
	    char repetirMenu ='s';
	    ePassenger aux;
	    int idBuscado;
	    //flags de control
	    int flagIngresos = 0;

	    eStatusFlight estatus[MAX_STATUS]=
	    {
	        {0,"EN ESPERA"},
	        {1,"ACTIVO"},
	        {2,"DEMORADO"},
	        {3,"REPROGRAMADO"},
	        {4,"CANCELADO"}
	    };

	    eTypePassenger tiposPasajero[MAX_TYPE]=
	    {
	        {1,"Economico"},
	        {2,"Turista"},
	        {3,"Primera Clase"}
	    };



	    initPassengers(vec,MAXPASSENGERS);
	    do
	    {
	        switch(menuPrincipal())
	        {
	        case 1:
	            pedirDatos(&aux,estatus,MAX_STATUS,tiposPasajero,MAX_TYPE);
	            if ( addPassenger(vec,MAXPASSENGERS,nextId,aux.name,aux.lastName,aux.price,aux.typePassenger,aux.flycode,aux.statusFlight,estatus,MAX_STATUS,tiposPasajero,MAX_TYPE) )
	            {
	                flagIngresos = 1;
	                nextId++;
	            }
	            break;
	        case 2:
	            if (flagIngresos)
	            {
	                modifyPassenger(vec,MAXPASSENGERS,estatus,MAX_STATUS,tiposPasajero,MAX_TYPE);
	            }
	            else
	            {
	                printf("No se puede modificar si no se ingresaron pasajeros.\n");
	            }

	            break;
	        case 3:
	            if(flagIngresos)
	            {
	                printPassengers(vec,MAXPASSENGERS,estatus,MAX_STATUS,tiposPasajero,MAX_TYPE);
	                pedirId(&idBuscado);
	                removePassenger(vec,MAXPASSENGERS,idBuscado,estatus,MAX_STATUS,tiposPasajero,MAX_TYPE);
	            }
	            else
	            {
	                printf("No se puede dar de baja si no se ingresaron pasajeros.\n");
	            }

	            break;
	        case 4:
	            if (flagIngresos)
	            {
	                informar(vec,MAXPASSENGERS,estatus,MAX_STATUS,tiposPasajero,MAX_TYPE);
	            }
	            else
	            {
	                printf("No se puede informar si no se ingresaron pasajeros.\n");
	            }
	            break;
	        case 5:
	            if (altaForzada(vec,MAXPASSENGERS,10,&nextId))
	            {
	                printf("DATOS CARGADOS EXITOSAMENTE.\n");
	            }
	            flagIngresos = 1;
	            break;
	        case 6:
	                repetirMenu='n';
	            break;
	        default:
	            printf("Opcion Invalida.");
	        }
	        system("Pause");
	        printf("programa terminado.");
	    }
	    while (repetirMenu == 's');








	return EXIT_SUCCESS;
}
