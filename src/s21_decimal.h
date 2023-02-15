#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
#include <limits.h>
#include <math.h>
#include "binary/core.h"
#include "comparison/comp.h"


/* Smart artithmetic API */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/* Other API */
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

/* Convertors and parsers */
int s21_from_int_to_decimal(int src, s21_decimal *dst);  // Из int debug ++
int s21_from_float_to_decimal(float src,
                              s21_decimal *dst);         // Из float debug ++
int s21_from_decimal_to_int(s21_decimal src, int *dst);  // В int debug ++
int s21_from_decimal_to_float(s21_decimal src, float *dst);  // В float debug ++

/* Helper func */
void lower_scale(s21_decimal *dec);
#endif
