#include "test.h"

START_TEST(s21_from_decimal_to_float_1) {
  s21_decimal src = {{18122, 0, 0}, {{0, 3, 0, 1}}};
  float number = 0.00;

  int result = s21_from_decimal_to_float(src, &number);

  ck_assert_float_eq(number, -18.122);
  ck_assert_int_eq(result, ARITHMETIC_OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
  s21_decimal src = {{18122, 0, 0}, {{0, 0, 0, 1}}};
  float number = 0.0;

  int result = s21_from_decimal_to_float(src, &number);

  ck_assert_float_eq(number, -18122);
  ck_assert_int_eq(result, ARITHMETIC_OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
  s21_decimal src = {{UINT_MAX, 0, 0}, {{0, 0, 0, 1}}};
  float number = 0.0;

  int result = s21_from_decimal_to_float(src, &number);

  ck_assert_float_eq(number, -(float)UINT_MAX);
  ck_assert_int_eq(result, ARITHMETIC_OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
  s21_decimal src = {{23450987, 0, 0}, {{0, 4, 0, 1}}};
  float number = 0.0;

  int result = s21_from_decimal_to_float(src, &number);

  ck_assert_float_eq(number, -2345.0987);
  ck_assert_int_eq(result, ARITHMETIC_OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_5) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, 0}, {{0, 0, 0, 0}}};
  float number = 0.0;

  int result = s21_from_decimal_to_float(src, &number);

  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(result, ARITHMETIC_OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_6) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, 0}, {{1, 1, 1, 1}}};
  float number = 0.0;

  int result = s21_from_decimal_to_float(src, &number);

  ck_assert_int_eq(result, CONVERTATION_ERROR);
}
END_TEST

Suite *suite_s21_from_decimal_to_float(void) {
  Suite *suite = suite_create("=== FROM_DECIMAL_TO_FLOAT TEST ===");

  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, s21_from_decimal_to_float_1);
  tcase_add_test(tc, s21_from_decimal_to_float_2);
  tcase_add_test(tc, s21_from_decimal_to_float_3);
  tcase_add_test(tc, s21_from_decimal_to_float_4);
  tcase_add_test(tc, s21_from_decimal_to_float_5);
  tcase_add_test(tc, s21_from_decimal_to_float_6);

  suite_add_tcase(suite, tc);

  return suite;
}
