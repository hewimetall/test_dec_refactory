#include "head.h"

int s21_is_not_equal(s21_decimal a, s21_decimal b) {
  int err = 0;
  if (!s21_is_correct_decimal(a) || !s21_is_correct_decimal(b)) err = 1;
  return ((s21_is(a, b, &err) != 0 && !err) ? 1 : 0);
}
