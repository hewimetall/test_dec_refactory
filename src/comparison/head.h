#ifndef S21_COMPAR_H_
#define S21_COMPAR_H_
#include "binary/head.h"
#include "helpers/head.h"
#include "s21_struct.h"

/* Comparison Operators */
int s21_is(s21_decimal a, s21_decimal b, int *err);
int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);
#endif
