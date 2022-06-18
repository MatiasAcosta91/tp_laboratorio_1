/**
* @brief realiza la apertura de un archivo para realizar la carga de su contenido en formato de texto en memoria dinamica.
*
* @param path char* nombre o ruta del del archivo
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 si no pudi realizar la apertura o path o lista =NULL; 1 si pudo realizar la carga correctamente.
*/int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
/**
* @brief realiza la apertura de un archivo para realizar la carga de su contenido en formato binario en memoria dinamica.
*
* @param path char* nombre o ruta del del archivo
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 si no pudi realizar la apertura o path o lista =NULL; 1 si pudo realizar la carga correctamente.
*/int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/**
* @brief  permite adherir a un nuevo pasajero al arrayList
*
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @param pLastId int* puntero al ultimo id utilizado
* @return 0 en caso de list o plastId = NULL; 1 si se adhirio correctamente.
*/int controller_addPassenger(LinkedList* pArrayListPassenger,int* pLastId);

/**
* @brief permite modificar los datos de un pasajero
*
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 en caso de no realizar modificacion, 1 si se realizo alguna modificacion
*/int controller_editPassenger(LinkedList* pArrayListPassenger);

/**
* @brief permite eliminar a un pasajero del arrayList
*
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 en caso de no confirmar la eliminacion, 1 si se elimino correctamente
*/int controller_removePassenger(LinkedList* pArrayListPassenger);

/**
* @brief permite mostrar el listado de pasajeros
*
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 si no hay pasajeros cargados o arrayList = NULL, 1 Si se pudo mostrar correctamente.
*/int controller_ListPassenger(LinkedList* pArrayListPassenger);

/**
* @brief permite realizar ordenamientos del listado de pasajeros.
*
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 si no se realizo ningun ordenamiento o arrayList = NULL, 1 si se realizo algun ordenamiento
*/int controller_sortPassenger(LinkedList* pArrayListPassenger);

/**
* @brief permite guardar el listado de pasajeros que se encuentra en memoria dinamica en un archivo de texto.
*
* @param path char* nombre o ruta del del archivo
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 en caso de ruta invalida o arrayList = NULL, 1 si se pudo gardar correctamente.
*/int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/**
* @brief  permite guardar el listado de pasajeros que se encuentra en memoria dinamica en un archivo binario.
*
* @param path char* nombre o ruta del del archivo
* @param pArrayListPassenger linkedList* puntero a la lista de pasajeros
* @return 0 en caso de ruta invalida o arrayList = NULL, 1 si se pudo gardar correctamente.
*/int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


