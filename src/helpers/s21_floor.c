#include "head.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int err = ARITHMETIC_OK;
  if (s21_is_correct_decimal(value)) {
    if (eq_zero(value))
      clean_value(result);
    else if (value.head.sign) {
      // negate
      if (value.head.exp) {
        s21_truncate(value, &value);
        s21_sub(value, DECIMAL_ONE, &value);
        *result = value;
        result->head.sign = 1;
      }
    } else {
      *result =
          binary_division(value, s21_pow10(value.head.exp), &err, (void *)0);
      err = 0;
    }
  } else {
    err = COUNT_ERROR;
  }
  return err;
}
