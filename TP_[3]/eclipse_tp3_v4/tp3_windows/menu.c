/*
 * menu.c
 *
 *  Created on: 9 jun. 2022
 *      Author: Acost
 */
#include "menu.h"

int menuPrincipal() {
	int opcion;
	system("cls");
	printf("*******************************************************************************\n");
	printf("*                      M E N U         P R I N C I P A L                      *\n");
	printf("*******************************************************************************\n");
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
	printf("3. Alta de pasajero.\n");
	printf("4. Modificar datos de pasajero.\n");
	printf("5. Baja de pasajero.\n");
	printf("6. Listar pasajeros.\n");
	printf("7. Ordenar pasajeros.\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
	printf("10. Salir.\n");
	printf("Ingrese una opcion: ");
	fflush(stdin);
	scanf("%d",&opcion);
	system("cls");
	return opcion;

}
int menuModificacion()
{
	int opcion;
	printf("1. Modificar Nombre.\n");
	printf("2. Modificar Apellido.\n");
	printf("3. Modificar Precio.\n");
	printf("4. Modificar Tipo Pasajero.\n");
	printf("5. Modificar Codigo de vuelo.\n");
	printf("6. Modificar estado de vuelo.\n");
	printf("7. Confirmar Cambios.\n");
	printf("8. Salir.\n");
	printf("Ingrese una opcion: ");
	fflush(stdin);
	scanf("%d",&opcion);
	system("cls");
	return opcion;
}
int menuOrdenamiento()
{
	int opcion;
	system("cls");
	printf("*******************************************************************************\n");
	printf("*                       M E N U       O R D E N A M I E N T O                 *\n");
	printf("*******************************************************************************\n");
	printf("1. Ordenar por id.\n");
	printf("2. Ordenar por nombre.\n");
	printf("3. Ordenar por pellido.\n");
	printf("4. Ordenar por precio,\n");
	printf("5. Ordenar por tipo de pasajero.\n");
	printf("6. ordenar por codigo de vuelo.\n");;
	printf("7. ordenar por estado de vuelo.\n");
	printf("8. Salir.\n");
	printf("Ingrese una opcion: ");
	fflush(stdin);
	scanf("%d",&opcion);
	system("cls");
	return opcion;
}

