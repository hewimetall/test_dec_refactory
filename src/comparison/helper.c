#include "head.h"

/** @brief Функция сравнения
 * Переворачивает аргументы если степени(exp) разные и вызывает функцию _s21_is
 *  @return int
 *          > 0 -> a > b  1
 *          = 0 -> a == b 0
 *          < 0 -> a < b  -1
 * + = 0 , - = 1;
   a b  res   res_data
 / - -  !( a ? b ) 11  !(?)
 / + +  a ? b 00  ?

 / + -  a > b 01  >
 / - +  a < b 10  <
 */
int s21_is(s21_decimal a, s21_decimal b, int *err) {
  int res = 1;
  short sign = a.head.sign << 1 | b.head.sign;
  if (sign == 0b11 || sign == 0b00) {
    *err = dec_normalize(&a, &b);
    res = compare(a, b);
  }
  if (sign == 0b11 || sign == 0b10) res *= -1;
  return res;
}
