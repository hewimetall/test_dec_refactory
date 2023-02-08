#include "s21_decimal.h"
#include "s21_decimal.h"
#define conv_dig(x) (x - 47)

//  Дописать ошибки переполнения.
// inf && nun не обрпабатываем

/*
    Get decimal part in float;
*/
s21_uint64 decpart_to_int(float val) {
  int err = 0;
  s21_uint64 part = (s21_uint64)val;
  return part;
}

/*
    Get float part in float
*/
s21_uint64 floatpart_to_int(float val, short size) {
  if (val == 0) return (s21_uint64)0;
  char str[200] = {0};
  sprintf(str, "%g", val);
  short int n = strlen(str) - 3;  // 0.1 -> 1 , pow 1 == 10 , pow 0 == 1

  // data count in 0-7 -> 999999 < INT MAX
  int summ = 0;
  // summ = 10 ^ (n-1-i) * el[0] + ... + 10 ^(0) * el(n);
  for (char *p = &str + 2; *p; p++, n++) summ += conv_dig(*p) * s21_pow10(n);
  return summ;
}

/*
    Union dec | float part 
*/
int glue(s21_uint64 d, s21_uint64 f, s21_decimal *res, short shift) {
  int err = 0;
  s21_decimal dec = int64_to_decimal(d);
  s21_decimal part = int64_to_decimal(f);
  //  сдвигаем в 10 системы на shift.
  *res = binary_multiplication(dec, s21_pow10(shift), &err);
  // суммируем части 
  *res = binary_addition(part, *res, &err);
  res->head.exp = shift;
  return err;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int err = 0;
  short size = 0;
  short sign = src<0;
  if(sign) src *=-1;

  s21_uint64 dec_part = decpart_to_int(src);
  s21_uint64 float_part = floatpart_to_int(src - (float)dec_part, &size);
  
  err = glue(dec_part, float_part, dst, size);
  
  dst->head.sign = sign;
  return err;
}
