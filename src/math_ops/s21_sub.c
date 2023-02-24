#include "s21_decimal.h"
// + +  sub
// - - sub = -a - -b = b - a = (-) (a - b)
// a < b  ? b - a , a - b
// a - b = (-1)(b - a)
// -a -b = (-1)()
// a < b
//
int swap_sib(s21_decimal *value_1, s21_decimal *value_2) {
  short sign = 0;
  DEC_INIT(tmp);
  if (compare(*value_1, *value_2) < 0) {
    tmp = *value_1;
    *value_1 = *value_2;
    *value_2 = tmp;
    sign = 1;
  }
  return sign;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = dec_normalize(&value_1, &value_2);
  short sign = swap_sib(&value_1, &value_2);
  if (err) {
  } else if (value_1.head.sign ^ value_2.head.sign) {
    // - + add
    // -a - b = (-) )(a +b)
    if (value_1.head.sign) sign = !sign, value_1.head.sign = 0;
    // + - add
    if (value_2.head.sign) value_2.head.sign = 0;
    err = s21_add(value_1, value_2, result);
  } else {
    clean_value(result);
    // - - add
    // -a - b = (-) )(a +b)
    if (value_1.head.sign) sign = !sign;

    *result = binary_subtraction(value_1, value_2, &err);
    err = 0;
  }
  if (!eq_zero(*result)) {
    result->head.sign = sign;
    result->head.exp = value_1.head.exp;
  }
  if (eq_zero(*result)) result->head.sign = 0;
  return err;
}
