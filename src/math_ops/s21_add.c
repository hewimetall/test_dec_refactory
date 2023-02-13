#include "s21_decimal.h"

int simple_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  union _to64 data = {0};
  int err = 0;

  for (short int i = 0; i < 3; i++) {
    data.data64 = data.data32[1];
    _add_to64(value_1.data[i], value_2.data[i], data.data64);
    result->data[i] = data.data32[0];
  }
  if (data.data32[1] != 0)
    return S21_INFINITY;
  else
    return ARITHMETIC_OK;
}

int shift_exp(int n, s21_decimal *value) {
  union _to64 p = {{0}};
  s21_decimal pow = {0}, tmp = {0};
  s21_decimal summ = {0};
  int err = 0;
  
  p.data64 = _pow10(n);
  pow.data[0] = p.data32[0];
  pow.data[1] = p.data32[1];
  
  for (s21_uint64 i = 0; i < p.data64 && p.data64 - 1l && !err; ++i) {
    err = simple_add(*value, summ, &summ);
  }
  if (p.data64 - 1l) (* value) = summ;
  if (err) return S21_INFINITY;
  return ARITHMETIC_OK;
}


int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = ARITHMETIC_OK;

  if (value_1.head.sign ^ value_2.head.sign) {
    if (value_1.head.sign) {
      value_1.head.sign = 0;
      res = s21_sub(value_2, value_1, result);
    } else {
      value_2.head.sign = 0;
      res = s21_sub(value_1, value_2, result);
    }

  } else {
    res = dec_normalize(&value_1, &value_2);
    //  Нет раницы тк оба числа имею равную экп после выравниванию
    result->head.exp = value_1.head.exp;

    if (res == ARITHMETIC_OK) {
      int sign = value_2.head.sign & value_2.head.sign;
      res = simple_add(value_1, value_2, result);
      result->head.sign = sign;
    
    }
  }
  return res;
}
