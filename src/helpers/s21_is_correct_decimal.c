#include "head.h"

int s21_is_correct_decimal(s21_decimal value) {
  int ret = 1;

  int exp = value.head.exp;
  if (exp < 0 || exp > 28) {
    ret = 0;
  }
  if (value.head.__ || value.head.___) {
    ret = 0;
  }
  if (value.head.sign != 0 && value.head.sign != 1) {
    ret = 0;
  }

  return ret;
}