#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int sign = 0, is_owerfull = 0;
  if (s21_is_correct_decimal(value_1) && s21_is_correct_decimal(value_2)) {
    DEC_INIT(tmp);
    clean_value(result);
    if (value_1.head.sign != value_2.head.sign) sign = 1;
    value_1.head.sign = 0;
    value_2.head.sign = 0;

    int tmp_exp = value_1.head.exp + value_2.head.exp;
    value_1.head.exp = 0;
    value_2.head.exp = 0;

    for (int i = 0; i < 96 && !is_owerfull; i++) {
      if (get_bit(value_2, i) == 1) {
        s21_decimal temp = value_1;
        int k = 0;
        while (k < i) {
          if (shiftl(&temp)) {
            is_owerfull = 1;
            break;
          }
          k++;
        }
        if (is_owerfull || (is_owerfull = s21_add(temp, tmp, &tmp))) {
          break;
        }
      }
    }

    if (!is_owerfull) *result = tmp;
    if (sign) result->head.sign = 1;
    if (result->head.sign && is_owerfull) is_owerfull = S21_NEGATIVE_INFINITY;
    result->head.exp = tmp_exp;
  }
  return is_owerfull;
}
