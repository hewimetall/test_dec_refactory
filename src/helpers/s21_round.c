#include "head.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int status = ARITHMETIC_OK;
  if (s21_is_correct_decimal(value)) {
    DEC_INIT(mul);
    s21_truncate(value, result);
    int sign = value.head.sign;
    int exp = value.head.exp;
    if (exp) exp--;
    while (exp--) {
      value = binary_division(value, s21_pow10(1), &status, (void *)0);
    }
    value.head.exp = 0;
    s21_mod(value, s21_pow10(1), &mul);

    if (mul.data[0] >= 5) {
      if (sign)
        s21_sub(*result, DECIMAL_ONE, result);
      else
        s21_add(*result, DECIMAL_ONE, result);
    }
    if (sign) result->head.sign = 1;
  } else {
    status = COUNT_ERROR;
  }
  return status;
}
