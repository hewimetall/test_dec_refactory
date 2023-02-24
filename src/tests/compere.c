#include "test.h"

START_TEST(compere_normale) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);

  ck_assert_int_eq(compare(decimal, decimal_v), 0);

  decimal.data[1] = 12;
  decimal_v.data[1] = 12;
  ck_assert_int_eq(compare(decimal, decimal_v), 0);

  decimal.data[1] = 12;
  decimal_v.data[1] = 11;
  ck_assert_int_gt(compare(decimal, decimal_v), 0);

  decimal.data[1] = 11;
  decimal_v.data[1] = 12;
  ck_assert_int_lt(compare(decimal, decimal_v), 0);
}
END_TEST

START_TEST(compere_max) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);

  decimal.data[2] = UINT_MAX;

  ck_assert_int_gt(compare(decimal, decimal_v), 0);
  ck_assert_int_lt(compare(decimal_v, decimal), 0);
}
END_TEST

Suite* suite_binary_comp(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("=== COMP  TEST ===");
  tc_core = tcase_create("binary");

  tcase_add_test(tc_core, compere_normale);
  tcase_add_test(tc_core, compere_max);

  suite_add_tcase(s, tc_core);

  return s;
}