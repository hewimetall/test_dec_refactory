#include "core.h"

// returns 0 meaning positive 1 negative
int get_bit(s21_decimal n, int pos) {
  return (n.data[pos / 32] >> (pos % 32)) & 1;
}

void set_bit(s21_decimal *n, int pos, s21_bool bit) {
  SET_BIT(n->data[pos / 32], bit, pos % 32);
}

// optimizete func
void set_bit_1(s21_decimal *n, int pos) {
  ADD_BIT(n->data[pos / 32], pos % 32);
}

void set_bit_0(s21_decimal *n, int pos) {
  ZERO_BIT(n->data[pos / 32], pos % 32);
}

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

void zerro_data(s21_decimal *val) {
  val->data[0] = 0;
  val->data[1] = 0;
  val->data[2] = 0;
}

s21_decimal int64_to_decimal(s21_uint64 a) {
  DEC_INIT(b);
  union _to64 to = {.data64 = a};
  b.data[0] = to.data32[0];
  b.data[1] = to.data32[1];
  return b;
}