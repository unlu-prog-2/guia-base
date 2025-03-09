#include <assert.h>
#include <stdio.h>

#include "aserciones.h"
#include "cadenas.h"
#include "../numero-racional.h"

void probar_simplificar(struct NumeroRacional f1, struct NumeroRacional esperado) {
    printf("Antes de simplificar: %s\n", nr_to_string(f1));
    nr_simplificar(&f1);
    printf("Simplificado: %s\n", nr_to_string(f1));
    assert(int_eq(f1.numerador,esperado.numerador));
    assert(int_eq(f1.denominador,esperado.denominador));

    enum NRComparacion resultado = nr_comparar(f1, esperado);
    assert(int_eq(resultado, IGUAL));
}

void probar_comparar(struct NumeroRacional f1, struct NumeroRacional f2, enum NRComparacion esperado) {
    enum NRComparacion resultado = nr_comparar(f1, f2);
    printf("Comparando %s con %s: %s\n", nr_to_string(f1), nr_to_string(f2), comparacion_to_string(resultado));
    assert(int_eq(resultado, esperado));
}

void probar_sumar(struct NumeroRacional f1, struct NumeroRacional f2, struct NumeroRacional esperado) {
    struct NumeroRacional resultado = nr_sumar(f1, f2);
    printf("%s + %s = %s\n", nr_to_string(f1), nr_to_string(f2), nr_to_string(resultado));
    assert(int_eq(resultado.numerador, esperado.numerador));
    assert(int_eq(resultado.denominador, esperado.denominador));
}

void probar_restar(struct NumeroRacional f1, struct NumeroRacional f2, struct NumeroRacional esperado) {
    struct NumeroRacional resultado = nr_restar(f1, f2);
    printf("%s - %s = %s\n", nr_to_string(f1), nr_to_string(f2), nr_to_string(resultado));
    assert(int_eq(resultado.numerador, esperado.numerador));
    assert(int_eq(resultado.denominador, esperado.denominador));
}

void probar_multiplicar(struct NumeroRacional f1, struct NumeroRacional f2, struct NumeroRacional esperado) {
    struct NumeroRacional resultado = nr_multiplicar(f1, f2);
    printf("%s * %s = %s\n", nr_to_string(f1), nr_to_string(f2), nr_to_string(resultado));
    assert(int_eq(resultado.numerador, esperado.numerador));
    assert(int_eq(resultado.denominador, esperado.denominador));
}

void probar_dividir(struct NumeroRacional f1, struct NumeroRacional f2, struct NumeroRacional esperado) {
    struct NumeroRacional resultado = nr_dividir(f1, f2);
    printf("%s / %s = %s\n", nr_to_string(f1), nr_to_string(f2), nr_to_string(resultado));
    assert(int_eq(resultado.numerador, esperado.numerador));
    assert(int_eq(resultado.denominador, esperado.denominador));
}

int main() {
    imprimir_titulo("Tests para Número Racional");

    // struct NumeroRacional nr;
    // assert(bool_true(nr_inicializar(3, 5, &nr)));
    // assert(int_eq(nr.numerador, 3));
    // assert(int_eq(nr.denominador, 5));
    //
    // assert(bool_false(nr_inicializar(3, 0, &nr)));
    // assert(int_eq(nr.numerador, 3));
    // assert(int_eq(nr.denominador, 5));
    //
    // probar_simplificar((struct NumeroRacional) {3, 5}, (struct NumeroRacional) {3, 5});
    // probar_simplificar((struct NumeroRacional) {6, 10}, (struct NumeroRacional) {3, 5});
    // probar_simplificar((struct NumeroRacional) {6, 2}, (struct NumeroRacional) {3, 1});
    // probar_simplificar((struct NumeroRacional) {-6, 2}, (struct NumeroRacional) {-3, 1});
    // probar_simplificar((struct NumeroRacional) {6, -2}, (struct NumeroRacional) {-3, 1});
    //
    // probar_comparar((struct NumeroRacional) {3, 5}, (struct NumeroRacional) {3, 5}, IGUAL);
    // probar_comparar((struct NumeroRacional) {6, 2}, (struct NumeroRacional) {3, 5}, MAYOR);
    // probar_comparar((struct NumeroRacional) {1, 7}, (struct NumeroRacional) {3, 5}, MENOR);
    // probar_comparar((struct NumeroRacional) {6, 2}, (struct NumeroRacional) {3, 1}, IGUAL);
    //
    // probar_sumar((struct NumeroRacional) {2, 5}, (struct NumeroRacional) {1, 2}, (struct NumeroRacional) {9, 10});
    // probar_sumar((struct NumeroRacional) {1, 2}, (struct NumeroRacional) {1, 2}, (struct NumeroRacional) {1, 1});
    // probar_sumar((struct NumeroRacional) {1, 2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {5, 4});
    // probar_sumar((struct NumeroRacional) {-1, 2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {1, 4});
    // probar_sumar((struct NumeroRacional) {1, -2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {1, 4});
    //
    // probar_restar((struct NumeroRacional) {2, 5}, (struct NumeroRacional) {1, 2}, (struct NumeroRacional) {-1, 10});
    // probar_restar((struct NumeroRacional) {1, 2}, (struct NumeroRacional) {1, 2}, (struct NumeroRacional) {0, 1});
    // probar_restar((struct NumeroRacional) {1, 2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {-1, 4});
    // probar_restar((struct NumeroRacional) {-1, 2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {-5, 4});
    // probar_restar((struct NumeroRacional) {1, -2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {-5, 4});
    //
    // probar_multiplicar((struct NumeroRacional) {2, 5}, (struct NumeroRacional) {1, 2}, (struct NumeroRacional) {1, 5});
    // probar_multiplicar((struct NumeroRacional) {1, 2}, (struct NumeroRacional) {1, 2}, (struct NumeroRacional) {1, 4});
    // probar_multiplicar((struct NumeroRacional) {1, 2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {3, 8});
    // probar_multiplicar((struct NumeroRacional) {-1, 2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {-3, 8});
    // probar_multiplicar((struct NumeroRacional) {1, -2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {-3, 8});
    //
    // probar_dividir((struct NumeroRacional) {2, 5}, (struct NumeroRacional) {1, 2}, (struct NumeroRacional) {4, 5});
    // probar_dividir((struct NumeroRacional) {1, 2}, (struct NumeroRacional) {1, 2}, (struct NumeroRacional) {1, 1});
    // probar_dividir((struct NumeroRacional) {1, 2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {2, 3});
    // probar_dividir((struct NumeroRacional) {-1, 2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {-2, 3});
    // probar_dividir((struct NumeroRacional) {1, -2}, (struct NumeroRacional) {3, 4}, (struct NumeroRacional) {-2, 3});

    return 0;
}
