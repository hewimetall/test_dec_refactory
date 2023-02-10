#include "s21_decimal.h"

/** @brief wraper for _s21_is.
 *
 * Обертка для ф _s21_is
 * Переворачивает аргументы если степени(exp) разные и вызывает функцию _s21_is
 *  @return int
 *          > 0 -> a > b
 *          = 0 -> a == b
 *          < 0 -> a < b
 */
int s21_is(s21_decimal a, s21_decimal b, int *err) {
  *err = normolize(s21_decimal *v1, s21_decimal *v2);
  s21_decimal res = binary_subtraction(v1,v2,err);
  if (!*err) int date = res.data[2] | res.data[1] | res.data[0];
  if (res.head.sign) date *= -1;
  return date;
}
