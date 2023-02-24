#include "test.h"

START_TEST(pow_test) {
  ck_assert_int_eq(s21_pow10(0).data[0], 1);
  ck_assert_int_eq(s21_pow10(1).data[0], 10);
}

START_TEST(shiftl_test) {
  DEC_INIT(decimal);

  decimal.data[0] = -1;
  decimal.data[1] = -1;
  decimal.data[2] = -1;

  for (int i = 0; i < 96; i++) shiftl(&decimal);
  ck_assert_int_eq(eq_zero(decimal), TRUE);
}

START_TEST(shiftr_test) {
  DEC_INIT(decimal);

  decimal.data[0] = -1;
  decimal.data[1] = -1;
  decimal.data[2] = -1;

  for (int i = 96; i > 0; i--) shiftr(&decimal);
  ck_assert_int_eq(eq_zero(decimal), TRUE);
}

Suite* suite_binary_other(void) {
  Suite* s;
  TCase* tc_pow;
  TCase* tc_shift;

  s = suite_create("=== OTHER TEST ===");
  tc_pow = tcase_create("pow");
  tc_shift = tcase_create("shift");

  tcase_add_test(tc_pow, pow_test);

  tcase_add_test(tc_shift, shiftr_test);
  tcase_add_test(tc_shift, shiftl_test);

  suite_add_tcase(s, tc_pow);
  suite_add_tcase(s, tc_shift);

  return s;
}