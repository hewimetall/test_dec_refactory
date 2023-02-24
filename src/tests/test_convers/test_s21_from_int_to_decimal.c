#include "test.h"

START_TEST(s21_from_int_to_decimal_1) {
  int src = 0;
  DEC_INIT(dec);

  int result = s21_from_int_to_decimal(src, &dec);

  ck_assert_int_eq(src, dec.data[0]);
  ck_assert_int_eq(result, ARITHMETIC_OK);
}
END_TEST

START_TEST(s21_from_int_to_decimal_2) {
  int src = 1;
  DEC_INIT(dec);

  int result = s21_from_int_to_decimal(src, &dec);

  ck_assert_int_eq(src, dec.data[0]);
  ck_assert_int_eq(result, ARITHMETIC_OK);
}
END_TEST

START_TEST(s21_from_int_to_decimal_3) {
  int src = -1;
  DEC_INIT(dec);

  int result = s21_from_int_to_decimal(src, &dec);

  ck_assert_int_eq(1, dec.data[0]);
  ck_assert_int_eq(1, dec.head.sign);
  ck_assert_int_eq(result, ARITHMETIC_OK);
}
END_TEST

Suite *suite_s21_from_int_to_decimal(void) {
  Suite *suite = suite_create("\n === FROM_INT_TO_DECIMAL   TEST ===");

  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, s21_from_int_to_decimal_1);
  tcase_add_test(tc, s21_from_int_to_decimal_2);
  tcase_add_test(tc, s21_from_int_to_decimal_3);

  suite_add_tcase(suite, tc);

  return suite;
}
