#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "binary_api/core.h"

/** @brief wraper for _s21_is.
 *
 * Обертка для ф _s21_is
 * Переворачивает аргументы если степени(exp) разные и вызывает функцию _s21_is
 *  @return int
 *          > 0 -> a > b
 *          = 0 -> a == b
 *          < 0 -> a < b
 */
int s21_is(s21_decimal v1, s21_decimal v2, int *err) {
  int data = 0;
  *err = normolize(&v1, &v2);
  int is_left = 0;
  s21_decimal res = binary_subtraction(v1, v2, err);// <= 0
  printf("DATA:%d %d\n",eq_zero(res),res);
  if (eq_zero(res)) {
    res = binary_subtraction(v2, v1, err); // >= 0
    if (!eq_zero(res)) {
      is_left = -1;
    } else {
      is_left = 0;
    }
  } else {
    is_left = 1;
  }
  return is_left;
}

int main() {
  DEC_INIT(v1);
  DEC_INIT(v2);
  DEC_INIT(res);
  v1.data[0] = 1<<31;
  
  v2.data[0] = MAX_INPUT;
  v2.data[1] = -1;

  // v1.head.exp = 1;
  int err = 0;
  // int data =s21_is(v1, v2, &data);
  s21_decimal data = binary_subtraction(v1, v2, &err);
  printf("%d\t%u",data.data[0],data.data[0]);
  // printf("%d\n%u\n%u- %d", v2.head.exp, v2.data[0], data, err);
}