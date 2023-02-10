#include "core.h"

/*
  Data is good
  ALG
  1) get max exp
  2) update_exp
*/
int normalize(s21_decimal *v1, s21_decimal *v2) {
  int diff = v1->head.exp - v2->head.exp;
  int err = ARITHMETIC_OK;
  if (diff > 0) {
    *v2 = binary_multiplication(*v2, s21_pow10(diff), &err);
    v2->head.exp += diff;
  } else {
    *v1 = binary_multiplication(*v1, s21_pow10((-1) * diff), &err);
    v1->head.exp -= diff;
  }
  return err;
}
