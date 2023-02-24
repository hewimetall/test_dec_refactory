#include "head.h"

// returns 0 meaning positive 1 negative
int get_bit(s21_decimal n, int pos) {
  return (n.data[pos / 32] >> (pos % 32)) & 1;
}

// optimizete func
void set_bit_1(s21_decimal *n, int pos) {
  ADD_BIT(n->data[pos / 32], pos % 32);
}

void set_bit_0(s21_decimal *n, int pos) {
  ZERO_BIT(n->data[pos / 32], pos % 32);
}

void set_bit(s21_decimal *n, int pos, int bit) {
  bit ? set_bit_1(n, pos) : set_bit_0(n, pos);
}

void zerro_data(s21_decimal *val) {
  val->data[0] = 0;
  val->data[1] = 0;
  val->data[2] = 0;
}
void clean_value(s21_decimal *val) {
  zerro_data(val);
  val->head.flags = 0;
}
