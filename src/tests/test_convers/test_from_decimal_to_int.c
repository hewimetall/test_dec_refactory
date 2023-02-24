#include "test.h"

START_TEST(s21_from_decimal_to_int_1) {
  DEC_INIT(src);
  int number = 0;

  int result = s21_from_decimal_to_int(src, &number);

  ck_assert_int_eq(number, 0);
  ck_assert_int_eq(result, ARITHMETIC_OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
  DEC_INIT(src);
  int number = 1000;

  int result = s21_from_decimal_to_int(src, &number);

  ck_assert_int_eq(number, 0);
  ck_assert_int_eq(result, ARITHMETIC_OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
  DEC_INIT(src);
  int number = 1000;
  src.data[0] = 1;
  src.head.sign = 1;
  int result = s21_from_decimal_to_int(src, &number);

  ck_assert_int_eq(number, -1);
  ck_assert_int_eq(result, ARITHMETIC_OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_4) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, 0}, {{1, 1, 1, 1}}};
  int number = 0;

  int result = s21_from_decimal_to_int(src, &number);

  ck_assert_int_eq(result, CONVERTATION_ERROR);
}
END_TEST

Suite *suite_s21_from_decimal_to_int(void) {
  Suite *suite = suite_create("=== FROM_DECIMAL_TO_INT   TEST ===");

  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, s21_from_decimal_to_int_1);
  tcase_add_test(tc, s21_from_decimal_to_int_2);
  tcase_add_test(tc, s21_from_decimal_to_int_3);
  tcase_add_test(tc, s21_from_decimal_to_int_4);

  suite_add_tcase(suite, tc);

  return suite;
}
