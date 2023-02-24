#include "head.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int status = CONVERTATION_OK;
  if (s21_is_correct_decimal(src)) {
    binary_division(src, s21_pow10(src.head.exp), &status, (void *)0);
    if (src.data[1] == 0 && src.data[2] == 0) *dst = src.data[0];
    if (src.head.sign) *dst *= -1;
  } else {
    status = COUNT_ERROR;
  }
  return status;
}
