#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
#include <limits.h>
#include <math.h>
#include "binary_api/core.h"

#define set_bit(a, b) (a & 1 << b)
#define change_bit(a, b) (a | 1 << b)
#define SIGN_DECIMAL_MASK 0x80000000  // 10000000 00000000 00000000 00000000

/* Comparison Operators */
int s21_is(s21_decimal a, s21_decimal b, int *err);
int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);

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
s21_uint64 s21_pow10(int exp);
int get_bit(s21_decimal src, int pos);
int leftShift(s21_decimal *number);
void setter(s21_decimal *number, int bit, int sign);
void lower_scale(s21_decimal *dec);
#endif
