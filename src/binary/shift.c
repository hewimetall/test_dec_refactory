#include "head.h"

// Логический (беззнаковый) сдвиг в лево
int shiftl(s21_decimal *a) {
  // Check if the 31th bit is set
  short b1_tmp = get_bit(*a, 31);
  a->data[0] <<= 1;

  short b2_tmp = get_bit(*a, 63);
  a->data[1] <<= 1;
  // binary shift to the left makes last bit equal to zero (because this is
  // pow(a, 2)) b1_tmp - remembered sign
  if (b1_tmp) set_bit_1(a, 32);

  int is_overflow = get_bit(*a, 95);
  a->data[2] <<= 1;

  if (b2_tmp) set_bit_1(a, 64);

  return (is_overflow);
}

// Логический (беззнаковый) сдвиг в право
void shiftr(s21_decimal *a) {
  short b1_tmp = get_bit(*a, 64);
  a->data[2] >>= 1;
  set_bit_0(a, 95);

  short b2_tmp = get_bit(*a, 32);
  a->data[1] >>= 1;
  set_bit_0(a, 63);
  if (b1_tmp) set_bit_1(a, 63);

  a->data[0] >>= 1;

  set_bit_0(a, 31);

  if (b2_tmp) set_bit_1(a, 31);
}
