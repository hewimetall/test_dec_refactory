#ifndef S21_HELPER_H_
#define S21_HELPER_H_
#include "binary/head.h"
#include "comparison/head.h"
#include "conversion/head.h"
#include "math_ops/head.h"

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_is_correct_decimal(s21_decimal value);
int shiftr_10(s21_decimal *val);
int shiftl_10(s21_decimal *val);
#endif
