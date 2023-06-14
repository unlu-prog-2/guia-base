#ifndef PRACTICA_TABLAS_HASH_H
#define PRACTICA_TABLAS_HASH_H

#include "tablas-hash/tablas-hash.h"
#include "arboles/arbol-avl.h"

void generarRegistrosYGuardarEnArchivo(char *nombreArchivo, int cantidad);

void leerArchivoYCargarEstructuras(char *nombreArchivo, TablaHash tablaHash, ArbolAVL arbol);

struct Registro {
    int codigo;
    char detalle[50];
    int precio;
    int stock;
};

#endif // PRACTICA_TABLAS_HASH_H
