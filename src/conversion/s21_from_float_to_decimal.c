#include "head.h"

#define MAX_POW 28
#define FLOAT_ACCURACY 7
#define S21_MAX_UINT 4294967295
#define START_INFO 96

void integral_part_to_dec(float src, s21_decimal *dst) {
  char str[100] = {0};
  DEC_INIT(tmp);

  sprintf(str, "%f", src);
  int i = 0;
  while (str[i] != '.') i++;
  str[i] = 0;
  int j = 0;
  int num = str[j];
  s21_from_int_to_decimal(num, &tmp);
  s21_add(*dst, tmp, dst);
  while (j != i) {
    int num = str[j];
    s21_mul(*dst, s21_pow10(1), dst);
    s21_from_int_to_decimal(num, &tmp);
    s21_add(*dst, tmp, dst);
    j++;
  }
}

int revert_data(int len, char str[len], char *rev) {
  int exp = 0;
  len--;
  int is_exp = 1;
  while ((str[len] == 0 || str[len] == '0') && len != 0) len--;
  for (; len >= 0; len--) {
    if (str[len] == '.')
      is_exp--;
    else if (str[len])
      *rev = str[len], rev++;
    if (is_exp) exp++;
  }
  return exp;
}

s21_decimal data_is_good(char *rev) {
  DEC_INIT(data);
  DEC_INIT(tmp);
  int err = 0;

  int shift = 0;
  while (*rev) {
    tmp.data[0] = (*rev - '0');
    tmp = binary_multiplication(tmp, s21_pow10(shift), &err);
    data = binary_addition(tmp, data, &err);
    shift++;
    rev++;
  }
  return data;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int sign = src < 0;
  int return_val = 0;
  if (sign) src *= -1;
  if (src == 0.) {
    clean_value(dst);

    // dst->state = S21_NULL;
  } else if (src >= MAX_DECIMAL) {
    return_val = 1;
    // dst->state = S21_PLUS_INF;
  } else if (src <= MIN_DECIMAL) {
    return_val = 1;
    // dst->state = S21_MINUS_INF;
  } else if (fabs(src) < powl(10.0, -1 * MAX_POW)) {
    return_val = 1;
  } else {
    clean_value(dst);
    char str[1000] = {0};
    char rev[1000] = {0};
    sprintf(str, "%.5f", src);
    int exp = revert_data(999, str, rev);
    *dst = data_is_good(rev);
    dst->head.sign = sign;
    dst->head.exp = exp;
  }
  return return_val;
}
