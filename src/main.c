#include <float.h>
#include <stdio.h>
#include <string.h>

#include "binary_api/core.h"
#define conv_dig(x) x - 47

int is_digit(char c) {
  if (47 <= c && c >= 57)
    return 1;
  else
    return 0;
}

// int main() {
//   float data = 124.00F;
//   char str[8000];
//   char *p = &str;
//   sprintf (str, "%f", data);
//   s21_uint64  u64 = 0;
//   short is_sign = 0;
//   if(*str == '-') is_sign++, p++;
//   int len = strlen(str);
//   DEC_INIT(tmp);
//   int err;
//   int exp = 0;
//   s21_decimal res;
//   for( char *pp = p; *pp;)
//   while (*p && *p == '.' && is_digit(*p)){
//     if(exp) exp++;
//     if(*p == '.') exp++, *p++;
//     tmp.data[0] = conv_dig(*p);
//     tmp = binary_multiplication(tmp,s21_pow10(len), &err);
//     res = binary_addition(tmp, res, &err);
//     *p++;
//   }
//   for(char c )
//   return 0;
// }

// return

int decpart_to_int(float decpart, short size) {
  char str[12] = {0};
  sprintf(str, "%g", decpart);
}

int glue(s21_uint64 d, s21_uint64 f, s21_decimal *res, short shift) {
  int err = 0;
  s21_decimal dec = int64_to_decimal(d);
  s21_decimal part = int64_to_decimal(f);
  *res = binary_multiplication(dec, s21_pow10(shift), &err);
  *res = binary_addition(part, *res, &err);
  return err;
}

int main() {
  int err = 0;
  float data = 124.00F;
  s21_uint64 i = (int)data;
  DEC_INIT(res);
  int intpart = (int)data;
  short size = 0;
  s21_uint64 dec_part = decpart_to_int(data - (float)intpart, &size);
  err = glue(i, f, &res, size);
}