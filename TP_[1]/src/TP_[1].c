/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Acosta Matias Jordan 1A
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "menuYMensajes.h"
#include "calculos.h"
#include "ingresosYValidaciones.h"
#define BITCOIN 4606954.55
#define DESCUENTO 10
#define INTERES 25

int main(void) {
		setbuf(stdout,NULL);
		int seguir = 1; //
	    int kmIngresados = 0;
	    int precAero = 0;
	    int precLat = 0;
	    //Precios Aerolineas
	    float precAeroDebito;
	    float precAeroCredito;
	    double precAeroBitcoin;
	    float precAeroPorKm;
	    //Precios Latam
	    float precLatDebito;
	    float precLatCredito;
	    double precLatBitcoin;
	    float precLatPorKm;
	    int diferenciaPrecio;
	    //Flags de ingresos a opciones del menu
	    int flagKm = 0;
	    int flagPrecios = 0;
	    int flagCalculos = 0;

	    do
	    {
	        switch(menu(kmIngresados,precAero,precLat))
	        {
	        case 1:
	            kmIngresados = solicitarKm(); //solicito que se ingresen los kilometros
	            flagKm=1;
	            break;
	        case 2:
	            printf("Aerolineas ");
	            precAero = solicitarPrecios(); //se solicita precios para aerolineas

	            printf("Latam ");
	            precLat = solicitarPrecios(); //Se solicita precio para latam
	            flagPrecios=1;
	            break;
	        case 3:
	            if (flagKm && flagPrecios) //si se ingreso precios y km se realizan los calculos
	            {
	                realizarCalculos (precAero,kmIngresados,DESCUENTO,INTERES,BITCOIN,&precAeroDebito,&precAeroCredito,&precAeroBitcoin,&precAeroPorKm);
	                realizarCalculos (precLat,kmIngresados,DESCUENTO,INTERES,BITCOIN,&precLatDebito,&precLatCredito,&precLatBitcoin,&precLatPorKm);
	                diferenciaPrecio = calcularDifPrecio (precAero,precLat);
	                mensajeCalculos();
	                flagCalculos = 1;
	            }
	            else
	            {
	                printf("Para realizar los calculos se debe ingresar los kilometros y precios.\n\n");

	            }
	            break;
	        case 4:
	            if (flagCalculos) //si se realizaron los calculos se puede realizar la muestra de resultados
	            {
	                printf("KMs Ingresados: %d\n\n", kmIngresados);
	                printf("Precio Aerolineas: $ %d\n",precAero);
	                mostrarResultados(precAeroDebito,precAeroCredito,precAeroBitcoin,precAeroPorKm);
	                printf("\n Precio Latam: $ %d\n",precLat);
	                mostrarResultados(precLatDebito,precLatCredito,precLatBitcoin,precLatPorKm);
	                printf("\nLa diferencia de precio es: $ %d",diferenciaPrecio);
	                printf("\n\n* * *   SE REESTABLECIO KM Y PRECIOS A CERO   * * *\n.");
	                flagPrecios = 0;
	                flagKm = 0;
	                flagCalculos = 0;
	                kmIngresados = 0;
	                precAero = 0;
	                precLat = 0;
	            }
	            else
	            {
	                printf("Para mostrar los resultados primero se deben hacer los calculos.\n\n");
	            }

	            break;
	        case 5: //carga forazada
	            cargaForzada (&kmIngresados,&precAero,&precLat);
	            realizarCalculos (precAero,kmIngresados,DESCUENTO,INTERES,BITCOIN,&precAeroDebito,&precAeroCredito,&precAeroBitcoin,&precAeroPorKm);
	            realizarCalculos (precLat,kmIngresados,DESCUENTO,INTERES,BITCOIN,&precLatDebito,&precLatCredito,&precLatBitcoin,&precLatPorKm);
	            diferenciaPrecio = calcularDifPrecio (precAero,precLat);
	            printf("KMs Ingresados: %d\n\n", kmIngresados);
	            printf("Precio Aerolineas: $ %d\n",precAero);
	            mostrarResultados(precAeroDebito,precAeroCredito,precAeroBitcoin,precAeroPorKm);
	            printf("\n Precio Latam: $ %d\n",precLat);
	            mostrarResultados(precLatDebito,precLatCredito,precLatBitcoin,precLatPorKm);
	            printf("\nLa diferencia de precio es: $ %d",diferenciaPrecio);
	            printf("\n\n* * *   SE REESTABLECIO KM Y PRECIOS A CERO   * * *\n.");
	            flagPrecios = 0;
	            flagKm = 0;
	            flagCalculos = 0;
	            kmIngresados = 0;
	            precAero = 0;
	            precLat = 0;
	            break;
	        case 6:
	            seguir = 0; //salir
	            break;
	        default:
	            printf("Opcion ingresada incorrecta.");
	            break;
	        }
	        system("pause");
	    }
	    while (seguir == 1);
	return EXIT_SUCCESS;
}

