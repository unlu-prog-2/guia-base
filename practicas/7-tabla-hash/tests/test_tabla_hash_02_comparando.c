#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "../practica_tablas_hash.h"
#include "cadenas.h"

int hash_modulo(int k) {
    return (4 + 3 * k) % 10;
}

int main() {
    srand(time(NULL));

    imprimir_titulo("Tests para comparar tablas hash");

//    TablaHash tabla = th_crear(10, hash_modulo);
//    th_mostrar(tabla);
//
//    int valores[] = {12, 13, 15, 5, 42, 8, 22, 91, 51, 21};
//    for (int i = 0; i < 10; i++) {
//        printf("Insertando %d\n", valores[i]);
//        th_insertar(tabla, te_crear(valores[i]));
//        th_mostrar(tabla);
//    }

    return 0;
}
