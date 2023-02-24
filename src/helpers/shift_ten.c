#include "head.h"

// Десятичный (беззнаковый) сдвиг в право
int shiftr_10(s21_decimal *val) {
  int err = ARITHMETIC_OK;
  DEC_INIT(p10);
  if (s21_is_correct_decimal(*val)) {
    p10 = s21_pow10(1);
    *val = binary_division(*val, p10, &err, (void *)0);
    if (!(val->head.exp)) val->head.exp--;
  } else {
    err = 1;
  }
  return err;
}

// Десятичный (беззнаковый) сдвиг в лево
int shiftl_10(s21_decimal *val) {
  int err = ARITHMETIC_OK;
  DEC_INIT(p10);
  if (s21_is_correct_decimal(*val)) {
    p10 = s21_pow10(1);

    if (val->head.exp != 28) {
      return S21_INFINITY;
    }
    *val = binary_multiplication(*val, p10, &err);
    val->head.exp++;
  } else {
    err = COUNT_ERROR;
  }
  return err;
}
