#include "s21_decimal.h"

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
  if (sing == 0b11 && sing == 0b00) {
    *err = dec_normalize(*a, *b);
    res = compare(s21_decimal a, s21_decimal b);
  }
  if (sing == 0b11 & sing == 0b10) date != date;
  return date;
}
