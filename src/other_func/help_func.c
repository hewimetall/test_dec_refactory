#include "../s21_decimal.h"

int get_bit(s21_decimal src, int pos) {
  return (src.data[pos / 32] >> (pos % 32));
}

int leftShift(s21_decimal *number) {
  int is_overflow = get_bit(*number, 95);
  for (int i = 95; i >= 0; i--) {
    if (i != 0) {
      setter(number, i, get_bit(*number, i - 1));
    } else {
      setter(number, i, 0);
    }
  }
  return is_overflow;
}

void setter(s21_decimal *number, int bit, int sign) {
  if (sign == 0) {
    number->data[bit / 32] >> (bit % 32) & 0;
  } else {
    number->data[bit / 32] >> (bit % 32) | 1;
  }
}

s21_decimal int64_to_decimal(s21_uint64 a) {
    s21_decimal b = DECIMAL_ZERO;
    union _to64 to = {.data64 = a};
    b.data[0] = to.data32[0];
    b.data[1] = to.data32[1];
    return b;
}

/**
 *
 * Уравнивает степени для числа
 *  1 e0 -> 10 e1
 *  1 e1 -> 1  e1
 */
int dec_normalize(s21_decimal *value_1, s21_decimal *value_2) {
  int err = ARITHMETIC_OK;
  int exp1 = value_1->head.exp;
  int exp2 = value_2->head.exp;

  int max_scl = (exp1 > exp2) ? exp1 : exp2;

  err = shift_exp(max_scl- value_1->head.exp, value_1);
  err = shift_exp(max_scl- value_2->head.exp, value_2);

  value_1->head.exp = max_scl;
  value_2->head.exp = max_scl;

  return err;
}
