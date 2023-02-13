#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = 0;
    if (value_1.head.sign == 1 && value_2.head.sign == 1) {
        value_2.head.sign &= 0b01111111111111111111111111111111;
        err = s21_add(value_1, value_2, result);
    } else if (value_1.head.sign == 0 && value_2.head.sign == 0) {
        value_2.head.sign |= 0x80000000;;
        err = s21_add(value_1, value_2, result);
    } else if (value_1.head.sign == 1 && value_2.head.sign == 0) {
        value_2.head.sign |= 0x80000000;;
        err = s21_add(value_1, value_2, result);
    } else if (value_1.head.sign == 0 && value_2.head.sign == 1) {
        value_2.head.sign &= 0b01111111111111111111111111111111;
        err = s21_add(value_1, value_2, result);
    }
  return err;
}