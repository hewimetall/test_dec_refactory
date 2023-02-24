#include "head.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  clean_value(dst);
  int status = CONVERTATION_OK;
  if (dst) {
    if (src >= 0) {
      dst->data[0] = (unsigned int)src;
    } else {
      src *= -1;
      dst->head.sign = 1;
      dst->data[0] = (unsigned int)src;
    }
  } else {
    status = CONVERTATION_ERROR;
  }
  return status;
}
