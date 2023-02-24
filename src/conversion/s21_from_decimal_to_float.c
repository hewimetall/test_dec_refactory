#include "head.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0.f;
  int status = CONVERTATION_OK, sign = src.head.sign;
  if (s21_is_correct_decimal(src)) {
    if (!dst)
      status = CONVERTATION_ERROR;
    else {
      long double tmp = 0;
      for (int i = 0; i < 96; i++) tmp += (double)pow(2, i) * get_bit(src, i);

      while (src.head.exp--) tmp /= 10.0;

      if (sign) tmp *= -1.0;

      *dst = tmp;
    }
  } else {
    status = COUNT_ERROR;
  }
  return status;
}