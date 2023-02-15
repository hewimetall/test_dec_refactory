#include "s21_decimal.h"
#include <math.h>

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  // Всегда 7
  long double tmp_d = (double) src;
  DEC_INIT(carry);
  tmp_d = roundl(tmp_d*1000000);
  int tmp = 0;
  while (tmp_d >0)
  {
    carry.data[0] = (int) tmp_d%UINT_MAX;
    tmp_d -= UINT_MAX;
    *dst = binary_addition(*dst,INT_MAX);
  }
  dst->head.exp = 7;
  return err;
}
