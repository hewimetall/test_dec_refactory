#include "head.h"

/**
 * @brief: Побитовое сравнения числа.
 * @return:
 *   a > b == 1
 *   a == b == 0
 *   a < b == -1
 */
short compare(s21_decimal a, s21_decimal b) {
  short data = 0;
  for (int i = sizeof(a.data) * 8 - 1; i >= 0 && !data; --i)
    data = get_bit(a, i) - get_bit(b, i);
  return data;
}
// fast_opt

int eq_zero(s21_decimal value) {
  return (value.data[0] == 0 && value.data[1] == 0 && value.data[2] == 0);
}
int eq_max(s21_decimal value) {
  return (value.data[0] == __UINT32_MAX__ && value.data[1] == __UINT32_MAX__ &&
          value.data[2] == __UINT32_MAX__);
}
int eq_val(s21_decimal value1, s21_decimal value2) {
  return (value1.data[0] == value2.data[0] &&
          value1.data[1] == value2.data[1] && value1.data[2] == value2.data[2]);
}