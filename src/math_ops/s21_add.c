#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = ARITHMETIC_OK;
  if (s21_is_correct_decimal(value_1) && s21_is_correct_decimal(value_2)) {
    if (value_1.head.sign ^ value_2.head.sign) {
      if (value_1.head.sign) {
        value_1.head.sign = 0;
        err = s21_sub(value_2, value_1, result);
      } else {
        value_2.head.sign = 0;
        err = s21_sub(value_1, value_2, result);
      }
    } else {
      clean_value(result);
      err = dec_normalize(&value_1, &value_2);
      //  Нет раницы тк оба числа имею равную экп после выравниванию

      if (err == ARITHMETIC_OK) {
        int sign = value_2.head.sign & value_2.head.sign;
        *result = binary_addition(value_1, value_2, &err);
        if (!err) {
          result->head.sign = sign;
          result->head.exp = value_1.head.exp;
        }
      }
      if (err && value_1.head.sign) err = S21_NEGATIVE_INFINITY;
    }
  }
  return err;
}
