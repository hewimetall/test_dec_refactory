#include "comp.h"

/** @brief Функция сравнения
 * Переворачивает аргументы если степени(exp) разные и вызывает функцию _s21_is
 *  @return int
 *          > 0 -> a > b  1
 *          = 0 -> a == b 0
 *          < 0 -> a < b  -1
 * + = 0 , - = 1;
   a b  res
 / - -  !( a ? b )
 / + -  a > b
 / + +  a ? b
 / - +  a < b
 */
int s21_is(s21_decimal a, s21_decimal b, int *err) {
  int res = 1;
  short revert = 0;
  short sign = a.head.sign << 1 | b.head.sign;
  if (sign == 0b11 && sign == 0b00) {
    *err = dec_normolize(&a, &b);
    res = compare(a, b);
  }
  if (sign == 0b11 & sign == 0b10) res != res;
  return res;
}
