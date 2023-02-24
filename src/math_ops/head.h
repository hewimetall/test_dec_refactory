#ifndef S21_MATH_H_
#define S21_MATH_H_
#include "binary/head.h"
#include "comparison/head.h"
#include "helpers/head.h"
#include "s21_struct.h"
#define MINUS_SIGN 2147483648

/* Smart artithmetic API */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif
