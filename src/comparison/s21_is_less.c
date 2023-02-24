#include "head.h"

int s21_is_less(s21_decimal a, s21_decimal b) {
  int err = 0;
  int status = 0;
  if (!s21_is_correct_decimal(a) || !s21_is_correct_decimal(b)) err = 1;
  if (s21_is(a, b, &err) < 0 && !err)
    status = TRUE;
  else if (s21_is(a, b, &err) >= 0 && !err)
    status = FALSE;
  return status;
}