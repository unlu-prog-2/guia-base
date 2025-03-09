#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "../practica_tablas_hash.h"
#include "cadenas.h"

int hash_modulo(int x) {
    return x % 10;
}

int main() {
    srand(time(NULL));

    imprimir_titulo("Tests para entender cómo funcionan las tablas hash");

//    TablaHash tabla = th_crear(10, hash_modulo);
//    th_mostrar(tabla);
//
//    int valores[] = { 531, 230, 711, 317, 434, 865, 294};
//    for (int i = 0; i < 7; i++) {
//        printf("Insertando %d\n", valores[i]);
//        th_insertar(tabla, te_crear(valores[i]));
//        th_mostrar(tabla);
//    }

    return 0;
}
