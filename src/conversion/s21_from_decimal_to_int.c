#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  
  int status = CONVERTATION_OK;
  if (!dst) status = CONVERTATION_ERROR;

  long double tmp = 0;
  for (int i = 0; i < 96; i++) tmp += (double)pow(2, i) * get_bit(src, i);

  while (src.head.exp--) tmp /= 10.0;

  if (src.head.sign) tmp *= -1.0;

  *dst = (int)(tmp + 0.5);
  
  return status;
}
