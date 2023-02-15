#include "comp.h"

int s21_is_less(s21_decimal a, s21_decimal b) {
  int err = 0;
  if (s21_is(a, b, &err) < 0 && !err)
    return TRUE;
  else
    return FALSE;
}