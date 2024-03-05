#ifndef PRACTICA_TABLA_HASH_H
#define PRACTICA_TABLA_HASH_H

#include "tabla-hash/tabla-hash.h"
#include "arboles/arbol-avl.h"

void generarRegistrosYGuardarEnArchivo(char *nombreArchivo, int cantidad);

void leerArchivoYCargarEstructuras(char *nombreArchivo, TablaHash tablaHash, ArbolAVL arbol);

struct Registro {
    int codigo;
    char detalle[50];
    int precio;
    int stock;
};

#endif // PRACTICA_TABLA_HASH_H
