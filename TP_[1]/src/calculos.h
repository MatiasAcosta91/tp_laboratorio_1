/*
 * calculos.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Acost
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_


#endif /* CALCULOS_H_ */
/**
 * @brief Aplica un % de descuento a un precio ingresado
 *
 * @param precioInicial int es el precio inicial
 * @param porDesc int es el porcentaje de descuento que se aplicara
 * @return float retorna el preciofinal con el descuento aplicado
 */float aplicarDescuento (int precioInicial, int porDesc);

/**
 * @brief
 *
 * @param precioInicial int aplica un % de interes a un precio ingresado
 * @param porcInteres int es el porcentaje de interes que se aplicara
 * @return float retorna el precio final con el interes aplicado
 */float aplicarInteres (int precioInicial,int porcInteres);

/**
 * @brief calcula el equivalente en bitcoin segun el precio ingresado
 *
 * @param precioPesos int precio al cual se le calculara el equivalente en bitcoin
 * @param valorBitcoin float valor en pesos quivalente a 1 bitcoin
 * @return double retorna el valor en bitcoint equivalente
 */double pesosABitcoin (int precioPesos, float valorBitcoin);

/**
 * @brief calcula el costo de un kilometro segun un precio y kilometros totales del vuelo
 *
 * @param km int es la cantidad total de kilometros
 * @param precio int es el precio total
 * @return float retorna el precio de un kilometro
 */float precioPorKm (int km, int precio);

/**
 * @brief calcula la diferencia de precio entre dos precios ingresados
 *
 * @param precio1 int
 * @param precio2 int
 * @return int retorna la diferencia de precio.
 */int calcularDifPrecio(int precio1,int precio2);

/**
 * @brief invoca a otras cuatro funciones las cuales realizan calculos aplicando descuento, interes, equivalente en bitcoin y precio por kilometro
 *
 * @param precioVuelo int precio inicial del vuelo
 * @param descuento int porcentaje de descuento a aplicar
 * @param interes	int porcentaje de interes a aplicar
 * @param km	int cantidad total de kilometros del vuelo
 * @param valorBitcoin	float equivalente en pesos a 1 bitcoin
 * @param precDebit	*float puntero con la direccion de memoria donde se guardara el valor con descuento
 * @param precCredit *float puntero con la direccion de memoria donde se guardara el valor con interes
 * @param precKm *float puntero con la direccion de memoria donde se guardara el valor de un kilometro
 * @return int retorna 0 si no se pudieron realizar los calculos (ej: puntero a NULL, valores en 0 o negativos), 1 si se pudieron realizar correctamente.
 */int realizarCalculos (int precioVuelo,int descuento,int interes,int km,float valorBitcoin,float* precDebit, float* precCredit,double* precBit,float* precKm);
