#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "cadenas.h"
#include "../repaso.h"

static bool lineasEquivalentesIgnorandoEspacios(const char *esperada, const char *real) {
    size_t i = 0;
    size_t j = 0;

    while (true) {
        while (esperada[i] != '\0' && isspace((unsigned char) esperada[i])) {
            i++;
        }
        while (real[j] != '\0' && isspace((unsigned char) real[j])) {
            j++;
        }

        bool finEsperada = (esperada[i] == '\0');
        bool finReal = (real[j] == '\0');

        if (finEsperada && finReal) {
            return true;
        }

        if (finEsperada != finReal) {
            return false;
        }

        size_t inicioTokenEsperada = i;
        size_t inicioTokenReal = j;

        while (esperada[i] != '\0' && !isspace((unsigned char) esperada[i])) {
            i++;
        }
        while (real[j] != '\0' && !isspace((unsigned char) real[j])) {
            j++;
        }

        size_t largoTokenEsperada = i - inicioTokenEsperada;
        size_t largoTokenReal = j - inicioTokenReal;

        if (largoTokenEsperada != largoTokenReal) {
            return false;
        }

        if (strncmp(esperada + inicioTokenEsperada, real + inicioTokenReal, largoTokenEsperada) != 0) {
            return false;
        }
    }
}

static bool archivosIguales(const char *rutaEsperado, const char *rutaReal) {
    FILE *esperado = fopen(rutaEsperado, "r");
    FILE *real = fopen(rutaReal, "r");

    if (esperado == NULL || real == NULL) {
        if (esperado != NULL) {
            fclose(esperado);
        }
        if (real != NULL) {
            fclose(real);
        }
        return false;
    }

    char lineaEsperada[2048];
    char lineaReal[2048];
    int nroLinea = 1;

    while (true) {
        char *le = fgets(lineaEsperada, sizeof(lineaEsperada), esperado);
        char *lr = fgets(lineaReal, sizeof(lineaReal), real);

        if (le == NULL && lr == NULL) {
            fclose(esperado);
            fclose(real);
            return true;
        }

        if (le == NULL || lr == NULL || !lineasEquivalentesIgnorandoEspacios(lineaEsperada, lineaReal)) {
            printf("Diferencia en linea %d\n", nroLinea);
            printf("Esperado: %s", le == NULL ? "<EOF>\n" : lineaEsperada);
            printf("Real:     %s", lr == NULL ? "<EOF>\n" : lineaReal);
            fclose(esperado);
            fclose(real);
            return false;
        }

        nroLinea++;
    }
}

int main() {
    imprimir_titulo("Tests de Ejercicio de Procesar Archivo");

    const char *archivoEntrada = "TP0_EJ5.txt";
    const char *archivoEsperado = "TP0_EJ5_esperado.txt";
    const char *archivoGenerado = "TP0_EJ5.txt.salida";

    procesarArchivo(archivoEntrada);

    bool sonIguales = archivosIguales(archivoEsperado, archivoGenerado);
    // assert(sonIguales);

    return 0;
}
