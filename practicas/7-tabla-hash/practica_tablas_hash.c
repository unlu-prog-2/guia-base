#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "practica_tablas_hash.h"

/**
 * Genera un archivo con registros aleatorios según la
 * cantidad solicitada (sin repetir el código).
 */
void generarRegistrosYGuardarEnArchivo(const char *nombreArchivo, int cantidad) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    assert(archivo != NULL);

    ArbolAVL arbol = avl_crear();

    struct Registro registro;
    int i = 0;
    while (i < cantidad) {
        int codigo = rand() % 9000000 + 1000000;
        if (avl_buscar(arbol, codigo) != NULL) {
            continue;  // Número repetido, seguir probando
        }
        avl_insertar(arbol, te_crear(codigo));

        registro.codigo = codigo;
        sprintf(registro.detalle, "Producto %i", codigo);
        registro.precio = rand() % 1000 * 100;
        registro.stock = rand() % 100;
        fwrite(&registro, sizeof(struct Registro), 1, archivo);

        i++;
    }

    fclose(archivo);
}

/**
 * Lee el archivo indicado y carga cada registro leído en una tabla hash y un árbol AVL.
 */
void leerArchivoYCargarEstructuras(const char *nombreArchivo, TablaHash tablaHash, ArbolAVL arbol) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    assert(archivo != NULL);

    struct Registro bufferLectura;
    long i = 0;
    while (fread(&bufferLectura, sizeof(struct Registro), 1, archivo)) {
        printf("%d %s %d %d\n", bufferLectura.codigo, bufferLectura.detalle, bufferLectura.precio, bufferLectura.stock);

        // Reservamos memoria en el heap para guardar la posición y guardamos la posición
        long *posicionEnArchivo = malloc(sizeof(long));
        *posicionEnArchivo = i++;

        TipoElemento te = te_crear_con_valor(bufferLectura.codigo, posicionEnArchivo);

        th_insertar(tablaHash, te);
        avl_insertar(arbol, te);
    }

    fclose(archivo);
}

