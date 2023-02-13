#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int sign_op = 0;

  s21_decimal *res = result;

  sign_op = value.head.sign;

  if (sign_op) {
    s21_truncate(value, res);

    s21_decimal *copy = res;

    copy->head.sign = 0;
    s21_decimal one = {0};
    one.data[0] = 0b00000000000000000000000000000001;
    one.data[1] = 0b00000000000000000000000000000000;
    one.data[2] = 0b00000000000000000000000000000000;
    one.data[3] = 0b00000000000000000000000000000000;

    s21_add(*copy, one, copy);
    copy->head.sign = 1;

    copy = result;

  } else {
    s21_truncate(value, res);
    *res = *result;
  }
  return error;
}
