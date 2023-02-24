#include "test.h"

START_TEST(shiftl_ten_test) {
  DEC_INIT(val1);
  DEC_INIT(val2);
  val1 = s21_pow10(1);
  val2 = s21_pow10(2);
  int err = shiftl_10(&val1);
  ck_assert_int_eq(eq_val(val1, val2), ARITHMETIC_OK);
  ck_assert_int_eq(err, ARITHMETIC_OK);
}
END_TEST

START_TEST(shiftr_ten_test) {
  DEC_INIT(val1);
  DEC_INIT(val2);
  val1 = s21_pow10(1);
  val2 = s21_pow10(2);
  int err = shiftr_10(&val2);
  ck_assert_int_eq(eq_val(val1, val2), ARITHMETIC_OK);
  ck_assert_int_eq(err, ARITHMETIC_OK);
}
END_TEST

Suite *suite_s21_shift10(void) {
  Suite *suite = suite_create("=== SHIFT_TEN TEST ===");

  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, shiftl_ten_test);
  tcase_add_test(tc, shiftr_ten_test);

  suite_add_tcase(suite, tc);

  return suite;
}