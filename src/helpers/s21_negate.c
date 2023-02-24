#include "head.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int status = COUNT_OK;
  if (s21_is_correct_decimal(value)) {
    if (s21_is_correct_decimal(value) && result) {
      *result = value;

      if (result->head.sign == 0)
        result->head.sign = 1;
      else if (result->head.sign == 1)
        result->head.sign = 0;

    } else {
      status = COUNT_ERROR;
    }
  } else {
    status = COUNT_ERROR;
  }
  return status;
}