#ifndef PRACTICA_TABLAS_HASH_H
#define PRACTICA_TABLAS_HASH_H

#include "tabla-hash/tabla-hash.h"
#include "arboles/arbol-avl.h"

void generarRegistrosYGuardarEnArchivo(const char *nombreArchivo, int cantidad);

void leerArchivoYCargarEstructuras(const char *nombreArchivo, TablaHash tablaHash, ArbolAVL arbol);

struct Registro {
    int codigo;
    char detalle[50];
    int precio;
    int stock;
};

#endif // PRACTICA_TABLAS_HASH_H
