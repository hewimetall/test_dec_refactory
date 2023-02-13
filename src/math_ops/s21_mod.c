#include "s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = ARITHMETIC_OK;
  if (result) {
    s21_decimal whole_part = DECIMAL_ZERO;
    *result = DECIMAL_ZERO;
    int sign = 0;

    if (value_2.head.sign) sign = 1;
    value_1.head.sign = 0;
    value_2.head.sign = 0;

    if (s21_is_greater_or_equal(value_1, value_2) &&
        s21_is_not_equal(value_2, DECIMAL_ZERO)) {
      while (s21_is_less(whole_part, value_1)) {
        s21_add(value_2, whole_part, &whole_part);
      }
      s21_sub(whole_part, value_2, &whole_part);

      s21_sub(value_1, whole_part, result);

    } else if (s21_is_equal(value_2, DECIMAL_ZERO)) {
      status = S21_ZERO_DIV;
    }

    if (sign) result->head.sign = 1;
  }
  return status;
}