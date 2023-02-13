#include "../s21_decimal.h"

s21_decimal s21_whole_part(s21_decimal value_1, s21_decimal value_2,
                           s21_decimal *result, int *err) {
  s21_decimal mod = DECIMAL_ZERO;
  s21_decimal whole_part = DECIMAL_ZERO;

  s21_mod(value_1, value_2, &mod);
  s21_sub(value_1, mod, &whole_part);

  while (s21_is_not_equal(whole_part, DECIMAL_ZERO) == TRUE) {
    *err = s21_add(*result, DECIMAL_ONE, result);
    s21_sub(whole_part, value_2, &whole_part);
  }
  return mod;
}

int s21_shift_ten(s21_decimal *mod, s21_decimal *result) {
  s21_decimal shift = {{10, 0, 0}, {0, 0, 0, 0}};
  int err = 0;

  s21_mul(*mod, shift, mod);
  err = s21_mul(*result, shift, result);
  result->head.exp += 1;
  return err;
}

int s21_div_simple(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  int status = ARITHMETIC_OK;
  if (result) {
    *result = DECIMAL_ZERO;
    s21_decimal mod = DECIMAL_ZERO;
    int err = 0;
    int sign = 0;
    s21_decimal tmp_res = DECIMAL_ZERO;

    if (value_1.head.sign != value_2.head.sign) sign = 1;
    value_1.head.sign = 0;
    value_2.head.sign = 0;

    result->head.exp = value_1.head.exp - value_2.head.exp;
    value_1.head.exp = 0;
    value_2.head.exp = 0;

    if (s21_is_greater_or_equal(value_1, value_2)) {
      mod = s21_whole_part(value_1, value_2, result, &err);
    } else {
      mod = value_1;
    }

    while (!err && s21_is_not_equal(mod, DECIMAL_ZERO) == TRUE &&
           result->head.exp < 28 &&
           (result->data[0] & result->data[1] & result->data[2]) <
               __INT_MAX__) {
      err = s21_shift_ten(&mod, result);
      if (!err) mod = s21_whole_part(mod, value_2, result, &err);
    }

    if (s21_is_not_equal(mod, DECIMAL_ZERO) == TRUE && result->head.exp == 28 &&
        !err && result->data[0] < __INT_MAX__) {
      s21_whole_part(mod, value_2, &tmp_res, &err);
      s21_decimal five = {{5, 0, 0}, {0, 0, 0, 0}};
      if (s21_is_greater_or_equal(tmp_res, five)) {
        s21_add(*result, DECIMAL_ONE, result);
      }
    }

    if ((err == S21_INFINITY) || (err == S21_NEGATIVE_INFINITY)) status = err;
    if (sign) result->head.sign = 1;
  }
  return status;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = ARITHMETIC_OK;
  if (s21_is_equal(value_2, DECIMAL_ZERO)) {
    status = S21_ZERO_DIV;
    *result = DECIMAL_ZERO;
  } else {
    status = s21_div_simple(value_1, value_2, result);
  }

  return status;
}