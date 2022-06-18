#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
/* TP3
 * Autor: Acosta Matias Jordan
 * Division 1A
 * Profesor Christian Baus
 *
 *
 */

/****************************************************
 Menu:
 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).						listo
 2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).						listo
 3. Alta de pasajero  																				listo
 4. Modificar datos de pasajero																		listo
 5. Baja de pasajero																				listo
 6. Listar pasajeros																				listo
 7. Ordenar pasajeros																				listo
 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).							listo
 9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).						listo
 10. Salir
 *****************************************************/

/* LOS CONTROLLERS SON LOS QUE VAN EN EL MAIN, SON LAS QUE VAN A LLAMAR A LAS DEMAS FUNCIONES.
 LOS PARSERS

 */
#define CANT_TIPOS 3
int main()
{
	setbuf(stdout,NULL);
	char seguir = 's';
	int lastId;
	LinkedList *listaPasajeros = ll_newLinkedList();
	int len;
	int flagLoad = 0;
	int flagBinSave=1;
	int flagDataSave=1;
	if(listaPasajeros == NULL)
	{
		printf("No se consiguio memoria.\n");
		EXIT_FAILURE;
	}

	if (!ObtenerUltimoId("ultimoId.bin", &lastId))
	{
		printf("No se pudo obtener el ultimo Id.\n");
		EXIT_FAILURE;
	}

	do {
		len = ll_len(listaPasajeros);
		system("cls");
		switch (menuPrincipal())
		{
		case 1:
			if (!flagLoad)
			{
				controller_loadFromText("data.csv", listaPasajeros);
				flagLoad = 1;
				flagBinSave = 0;
				flagDataSave = 0;
			}
			else
			{
				printf("No se permite una segunda carga de archivo dado que los datos se duplicaran.\n");
			}
			break;
		case 2:
			if (!flagLoad)
			{
				controller_loadFromBinary("data.bin" ,listaPasajeros);
				flagLoad= 1;
				flagBinSave = 0;
				flagDataSave = 0;
			}
			else
			{
				printf("No se permite una segunda carga de archivo dado que los datos se duplicaran.\n");
			}

			break;
		case 3:
			if( controller_addPassenger(listaPasajeros,&lastId))
			{
			printf("Alta Confirmada.\n");
			flagDataSave = 0;
			flagBinSave = 0;
			}
			else
			{
				printf("No se concreto el alta.\n");
			}
			break;
		case 4:
			if (len > 0)
			{
				if ( controller_editPassenger(listaPasajeros))
				{
					printf("Cambios guardados!.\n");
					flagDataSave = 0;
					flagBinSave = 0;
				}
				else
				{
					printf("No se guardaron los cambios.\n");
				}
			}
			else
			{
				printf("No hay pasajeros para mostrar.\n");
			}
			break;
		case 5:
			if(len >0)
			{
				if(controller_removePassenger(listaPasajeros))
				{
					printf("Baja realizada.\n");
					flagDataSave = 0;
					flagBinSave = 0;
				}
				else
				{
					printf("No se concreto la baja.\n");
				}
			}
			else
			{
				printf("No hay pasajeros cargados.\n");
			}
			break;
		case 6:
			if (!controller_ListPassenger(listaPasajeros))
			{
				printf("No hay pasajeros cargados o lista = NULL.\n");
			}
			break;
		case 7:
			if(len >0)
			{
				if (controller_sortPassenger(listaPasajeros))
				{
					printf("Ok.\n");
				}
				else
				{
					printf("No se pudo realizar ordenamiento. No hay pasajeros cargados o lista = NULL.\n");
				}
			}
			else
			{
				printf("No hay pasajeros cargados.\n");
			}
			break;
		case 8:
			if (len>0)
			{
				controller_saveAsText("data.csv",listaPasajeros);
				flagDataSave = 1;
			}
			else
			{
				printf("No hay datos cargados para guardar.\n");
			}

			break;
		case 9:
			if (len>0)
			{
				controller_saveAsBinary("data.bin",listaPasajeros);
				flagBinSave = 1;
			}
			else
			{
				printf("No hay datos cargados para guardar.\n");
			}
			break;
		case 10:
			if (flagBinSave && flagDataSave)
			{
				seguir = 'n';
				ll_deleteLinkedList(listaPasajeros);
				GuardarUltimoId("ultimoId.bin", &lastId);
			}
			else
			{
				printf("Para poder salir se debe guardar la informacion en el archivo \"data\" y en el archivo \"bin\".\n");
			}

			break;
			default:
			printf("Opcion ingresada Invalida.\n");
		}
		system("pause");
	} while (seguir == 's');
	return 0;
}

