#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void imprimir_titulo(char *titulo) {
    printf("\n\n\x1b[36m %s \x1b[0m\n", titulo);
    const size_t longitud = strlen(titulo);
    char *subrayado = malloc(longitud + 1);
    for (int i = 0; i < longitud; i++) {
        subrayado[i] = titulo[i] != ' ' ? '-' : ' ';
    }
    subrayado[longitud] = '\0';
    printf("\x1b[34m %s \x1b[0m\n\n", subrayado);

    free(subrayado);
}

char *cadena_enteros_como_string(int list[], int size) {
    char *result = (char *) malloc(sizeof(char) * (size * 10 + 3));
    strcpy(result, "[");
    for (int i = 0; i < size; i++) {
        char num_str[10];
        sprintf(num_str, "%d, ", list[i]);
        strcat(result, num_str);
    }
    result[strlen(result) - 2] = ']';
    result[strlen(result) - 1] = '\0';
    return result;
}
