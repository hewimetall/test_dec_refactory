#include "head.h"

/**
 * @brief: Уравнивает степени для числа
 *  1 e0 -> 10 e1
 *  1 e1 -> 1  e1
 */
int dec_normalize(s21_decimal *v1, s21_decimal *v2) {
  int diff = v1->head.exp - v2->head.exp;
  int err = ARITHMETIC_OK;
  DEC_INIT(tmp);
  if (diff == 0) {
  } else if (diff > 0) {
    tmp = binary_multiplication(*v2, s21_pow10(diff), &err);
    err *= 2;
    if (err && v1->head.exp != 0) {
      binary_round(v1);
      dec_normalize(v1, v2);
    } else {
      *v2 = tmp;
      v2->head.exp += v1->head.exp;
    }
  } else {
    tmp = binary_multiplication(*v1, s21_pow10((-1) * diff), &err);

    if (err && v2->head.exp != 0) {
      binary_round(v2);
      dec_normalize(v1, v2);
    } else {
      *v1 = tmp;
      v1->head.exp += v2->head.exp;
    }
  }
  if (err) {
  }
  return err;
}
