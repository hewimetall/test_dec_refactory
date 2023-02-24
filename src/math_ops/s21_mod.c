#include <stdio.h>

#include "s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = ARITHMETIC_OK;

  clean_value(result);
  if (result && s21_is_correct_decimal(value_1) &&
      s21_is_correct_decimal(value_2)) {
    int sign = 0;

    if (value_1.head.sign) sign = 1;
    value_1.head.sign = 0;
    value_2.head.sign = 0;

    if (!eq_zero(value_2)) {
      dec_normalize(&value_1, &value_2);

      int err = 0;

      if (!s21_is_equal(value_2, DECIMAL_ONE))
        binary_division(value_1, value_2, &err, result);

      if (sign) result->head.sign = 1;
      if (!eq_zero(*result)) result->head.exp = value_1.head.exp;

    } else if (eq_zero(value_2)) {
      status = S21_ZERO_DIV;
    }
  }
  return status;
}