#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../practica_tablas_hash.h"
#include "arboles/arbol-avl.h"
#include "cadenas.h"

int tamanoTablaHash = 1009;

int hash_modulo(int k) {
    return k % tamanoTablaHash;
}

int codigoAleatorio() {
    return rand() % 9000000 + 1000000; // NOLINT(cert-msc50-cpp)
}

void experimento(const char *nombreArchivo, bool usarTH, TablaHash tabla_hash, ArbolAVL arbol, int iteraciones) {
    clock_t start = clock();

    FILE *archivo = fopen(nombreArchivo, "rb");
    assert(archivo != NULL);
    while (iteraciones > 0) {
        int codigo = codigoAleatorio();
        TipoElemento te = usarTH ?
                          th_recuperar(tabla_hash, codigo) :
                          avl_buscar(arbol, codigo);
        if (te == NULL) {
            continue;
        }
        long *posicionEnArchivo = (long *) te->valor;
        fseek(archivo, (long) sizeof(struct Registro) * (*posicionEnArchivo), SEEK_SET);
        struct Registro bufferLectura;
        size_t bytesLeidos = fread(&bufferLectura, sizeof(struct Registro), 1, archivo);
        if (bytesLeidos == 0) {
            printf("Error al leer el registro %ld perteneciente al código %d\n", *posicionEnArchivo, codigo);
        }

//        printf("Leído registro en posición %ld: %d %s %d %d\n", registroLeido->posicionEnArchivo, bufferLectura.codigo,
//               bufferLectura.detalle, bufferLectura.precio, bufferLectura.stock);

        iteraciones--;
    }
    fclose(archivo);

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tiempo de búsqueda usando %s: %f\n", usarTH ? "Tabla Hash" : "Árbol AVL", cpu_time_used);
}

int main() {
    srand(time(NULL));

    imprimir_titulo("Tests para comparar tablas hash con árboles AVL");

//    char *nombreArchivo = "productos_10.dat";
//    char *nombreArchivo = "productos_100.dat";
    char *nombreArchivo = "productos_1000.dat";
//    char *nombreArchivo = "productos_10000.dat";

    TablaHash tabla_hash = th_crear(tamanoTablaHash, hash_modulo);
    ArbolAVL arbol = avl_crear();
    leerArchivoYCargarEstructuras(nombreArchivo, tabla_hash, arbol);

    th_mostrar(tabla_hash);
//    mostrar_arbol_binario_ascii(avl_raiz(arbol)); // Para archivos de 1000 y 10000 no anda (porque es muy grande para mostrar en la consola)

    int iteraciones = 5000;
    experimento(nombreArchivo, true, tabla_hash, arbol, iteraciones);  // true  --> usa la tabla hash
    experimento(nombreArchivo, false, tabla_hash, arbol, iteraciones); // false --> usa el árbol AVL

    return 0;
}
