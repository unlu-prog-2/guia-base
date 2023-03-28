#ifndef ASSERT_H
#define ASSERT_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "aserciones.h"

bool bool_eq(bool real, bool esperado);

bool bool_true(bool real);

bool bool_false(bool real);

bool str_eq(char *real, char *esperado);

bool int_eq(int real, int esperado);

bool int_gt(int real, int esperado);

bool int_gte(int real, int esperado);

bool int_lt(int real, int esperado);

bool int_lte(int real, int esperado);

bool float_eq(float real, float esperado);

bool float_gt(float real, float esperado);

bool float_gte(float real, float esperado);

bool float_lt(float real, float esperado);

bool float_lte(float real, float esperado);

bool double_eq(double real, double esperado);

bool double_gt(double real, double esperado);

bool double_gte(double real, double esperado);

bool double_lt(double real, double esperado);

bool double_lte(double real, double esperado);

bool int_array_eq(int *real, int *esperado, int longReal, int longEsperado);

#endif // ASSERT_H
