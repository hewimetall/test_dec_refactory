#include "s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal a, s21_decimal b) {
  int err = 0;
  return ((s21_is(a, b, &err) <= 0 && !err) ? 1 : 0);
}
