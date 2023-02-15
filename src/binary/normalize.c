#include "core.h"

/**
 * @brief: Уравнивает степени для числа
 *  1 e0 -> 10 e1
 *  1 e1 -> 1  e1
 */
int dec_normolize(s21_decimal *v1, s21_decimal *v2) {
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
