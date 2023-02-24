#include "test.h"

START_TEST(bit_xor_test) {
  DEC_INIT(decimal);
  decimal = bit_xor(decimal, decimal);
  ck_assert_int_eq(decimal.data[0], 0 ^ 0);
}

START_TEST(bit_and_test) {
  DEC_INIT(decimal);
  decimal = bit_and(decimal, decimal);
  ck_assert_int_eq(decimal.data[0], 0 & 0);
}

START_TEST(bit_or_test) {
  DEC_INIT(decimal);
  decimal = bit_or(decimal, decimal);
  ck_assert_int_eq(decimal.data[0], 0 | 0);
}

START_TEST(bit_not_test) {
  DEC_INIT(decimal);
  decimal = bit_not(decimal);
  ck_assert_int_eq(decimal.data[0], ~0u);
}

Suite* suite_binary_logic(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("=== LOGIC TEST ===");
  tc_core = tcase_create("tc");

  tcase_add_test(tc_core, bit_xor_test);
  tcase_add_test(tc_core, bit_and_test);
  tcase_add_test(tc_core, bit_or_test);
  tcase_add_test(tc_core, bit_not_test);

  suite_add_tcase(s, tc_core);

  return s;
}