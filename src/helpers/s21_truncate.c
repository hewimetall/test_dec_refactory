#include "head.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  clean_value(result);
  int err = ARITHMETIC_OK;
  if (s21_is_correct_decimal(value)) {
    *result =
        binary_division(value, s21_pow10(value.head.exp), &err, (void *)0);
    err = 0;
    result->head.sign = value.head.sign;
  } else {
    err = COUNT_ERROR;
  }
  return err;
}
