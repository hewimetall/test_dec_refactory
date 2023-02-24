#include "head.h"

int binary_round(s21_decimal *val) {
  int err = 0;
  DEC_INIT(diff);
  s21_decimal res = binary_division(*val, s21_pow10(1), &err, &diff);
  if (!eq_zero(diff)) *val = binary_addition(*val, DECIMAL_ONE, &err);
  *val = res;
  return diff.data[0];
}
