#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int status = COUNT_OK;

  if (!result)
    status = COUNT_ERROR;
  else
    *result = value;

  if (result->head.sign == 0)
    result->head.sign = 1;
  else if (result->head.sign == 1)
    result->head.sign = 0;
  else
    status = COUNT_ERROR;
  return status;
}