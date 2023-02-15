#include "s21_decimal.h"

s21_uint64 _pow10(int exp) {
  const s21_uint64 arr[] = {1,
                            10,
                            100,
                            1000,
                            10000,
                            100000,
                            1000000,
                            10000000,
                            100000000,
                            1000000000,
                            10000000000,
                            100000000000,
                            1000000000000,
                            10000000000000,
                            100000000000000,
                            1000000000000000,
                            10000000000000000,
                            100000000000000000,
                            1000000000000000000};
  return arr[exp];
}
s21_decimal s21_pow10(int exp) {
  union _to64 pow = {.data64 = _pow10(exp)};
  s21_decimal d = DECIMAL_ONE;
  d.data[0] = pow.data32[0];
  d.data[1] = pow.data32[1];
  return d;
}
