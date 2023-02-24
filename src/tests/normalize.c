#include "test.h"

START_TEST(norm_eq) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  decimal.data[0] = 1;
  decimal.head.exp = 1;

  decimal_v.data[0] = 1;
  decimal_v.head.exp = 1;

  ck_assert_int_eq(dec_normalize(&decimal, &decimal_v), ARITHMETIC_OK);
  ck_assert_int_eq(decimal.data[0], 1);
  ck_assert_int_eq(decimal_v.data[0], 1);
  ck_assert_int_eq(compare(decimal, decimal_v), 0);
  ck_assert_int_eq(decimal_v.head.exp, decimal.head.exp);

  decimal_v.head.exp = 28;
  decimal.head.exp = 28;

  ck_assert_int_eq(dec_normalize(&decimal, &decimal_v), ARITHMETIC_OK);
  ck_assert_int_eq(decimal.data[0], 1);
  ck_assert_int_eq(decimal_v.data[0], 1);
  ck_assert_int_eq(compare(decimal, decimal_v), 0);
  ck_assert_int_eq(decimal_v.head.exp, decimal.head.exp);
}

START_TEST(norm_le) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  decimal.data[0] = 1;
  decimal.head.exp = 1;

  decimal_v.data[0] = 1;
  decimal_v.head.exp = 2;

  ck_assert_int_eq(dec_normalize(&decimal, &decimal_v), ARITHMETIC_OK);
  ck_assert_int_eq(decimal.data[0], 10);
  ck_assert_int_eq(decimal_v.data[0], 1);
  ck_assert_int_eq(compare(decimal, decimal_v), 1);
  ck_assert_int_eq(decimal_v.head.exp, decimal.head.exp);

  decimal.data[0] = 1;
  decimal.head.exp = 27;

  decimal_v.data[0] = 1;
  decimal_v.head.exp = 28;

  ck_assert_int_eq(dec_normalize(&decimal, &decimal_v), ARITHMETIC_OK);
  ck_assert_int_eq(decimal.data[0], 10);
  ck_assert_int_eq(decimal_v.data[0], 1);
  ck_assert_int_eq(compare(decimal, decimal_v), 1);
  ck_assert_int_eq(decimal_v.head.exp, decimal.head.exp);
}

START_TEST(norm_ge) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  decimal.data[0] = 1;
  decimal.head.exp = 2;

  decimal_v.data[0] = 1;
  decimal_v.head.exp = 1;

  ck_assert_int_eq(dec_normalize(&decimal, &decimal_v), ARITHMETIC_OK);
  ck_assert_int_eq(decimal.data[0], 1);
  ck_assert_int_eq(decimal_v.data[0], 10);
  ck_assert_int_eq(compare(decimal, decimal_v), -1);
  ck_assert_int_eq(decimal_v.head.exp, decimal.head.exp);

  decimal.data[0] = 1;
  decimal.head.exp = 28;

  decimal_v.data[0] = 1;
  decimal_v.head.exp = 27;

  ck_assert_int_eq(dec_normalize(&decimal, &decimal_v), ARITHMETIC_OK);
  ck_assert_int_eq(decimal.data[0], 1);
  ck_assert_int_eq(decimal_v.data[0], 10);
  ck_assert_int_eq(compare(decimal, decimal_v), -1);
  ck_assert_int_eq(decimal_v.head.exp, decimal.head.exp);
}
START_TEST(norm_neg) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  decimal.data[0] = 1;
  decimal.head.exp = 2;

  decimal_v.data[0] = 1;
  decimal_v.head.exp = 1;

  ck_assert_int_eq(dec_normalize(&decimal, &decimal_v), ARITHMETIC_OK);
  ck_assert_int_eq(decimal.data[0], 1);
  ck_assert_int_eq(decimal_v.data[0], 10);
  ck_assert_int_eq(compare(decimal, decimal_v), -1);
  ck_assert_int_eq(decimal_v.head.exp, decimal.head.exp);

  decimal.data[0] = 1;
  decimal.head.exp = 28;

  decimal_v.data[0] = 1;
  decimal_v.head.exp = 0;

  ck_assert_int_eq(dec_normalize(&decimal, &decimal_v), 2);
  ck_assert_int_eq(compare(decimal, decimal_v), -1);
  ck_assert_int_eq(decimal_v.head.exp, decimal.head.exp);
}

Suite* suite_binary_norm(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("=== NORM  TEST ===");
  tc_core = tcase_create("tc");

  tcase_add_test(tc_core, norm_eq);
  tcase_add_test(tc_core, norm_le);
  tcase_add_test(tc_core, norm_ge);
  tcase_add_test(tc_core, norm_neg);

  suite_add_tcase(s, tc_core);

  return s;
}