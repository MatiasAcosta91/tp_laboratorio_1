/**
* @brief obtiene los pasajeros guardados en un archivo de texto, crea un pasajero en la memoria dinamica, le asigna los datos del archivo y los agrega a la lista de pasajeros
*
* @param pFile FILE* Puntero a la estructura FILE
* @param pArrayListPassenger *linkedList puntero a la lista de pasajeros.
* @return int retorna la cantidad de pasajeros cargados correctamente.
*/int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
/**
* @brief obtiene los pasajeros guardados en un archivo bin, crea un pasajero en la memoria dinamica, le asigna los datos del archivo y los agrega a la lista de pasajeros
*
* @param pFile FILE* Puntero a la estructura FILE
* @param pArrayListPassenger *linkedList puntero a la lista de pasajeros.
* @return int retorna la cantidad de pasajeros cargados correctamente.
*/int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
/**
* @brief guarda en un el puntero file la lista de pasajeros en modo texto.
*
* @param pFile FILE* Puntero a la estructura FILE
* @param pArrayListPassenger *linkedList puntero a la lista de pasajeros.
* @return int retorna la cantidad de pasajeros guardados correctamente.
*/int parser_TextFromPassenger(FILE* pFile , LinkedList* pArrayListPaassenger);
/**
* @brief guarda en un el puntero file la lista de pasajeros en modo binario
*
* @param pFile FILE* Puntero a la estructura FILE
* @param pArrayListPassenger *linkedList puntero a la lista de pasajeros.
* @return int retorna la cantidad de pasajeros guardados correctamente.
*/int parser_binaryFromPassenger(FILE* pFile , LinkedList* pArrayListPaassenger);

