#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "comparison/comp.h"

/** @brief wraper for _s21_is.
 *
 * Обертка для ф _s21_is
 * Переворачивает аргументы если степени(exp) разные и вызывает функцию _s21_is
 *  @return int
 *          > 0 -> a > b
 *          = 0 -> a == b
 *          < 0 -> a < b
 */

int main() {
  DEC_INIT(v1);
  DEC_INIT(v2);
  DEC_INIT(res);
  v1.data[0] = 1<<31;
  
  v2.data[0] = MAX_INPUT;
  v2.data[1] = -1;

  // v1.head.exp = 1;
  int err = 0;
  int data =s21_is(v1, v2, &err);
  // printf("%d\t%u",data.data[0],data.data[0]);
  // printf("%d\n%u\n%u- %d", v2.head.exp, v2.data[0], data, err);
}