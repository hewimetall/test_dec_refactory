#include "test_main.h"

START_TEST(test_01_s21_negate) {
  s21_decimal value = {{1, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal result = DECIMAL_ZERO;

  int ret = s21_negate(value, &result);

  ck_assert_int_eq(result.data[0], 1);
  ck_assert_int_eq(result.data[1], 0);
  ck_assert_int_eq(result.data[2], 0);
  ck_assert_int_eq(result.head.flags, 0);
  ck_assert_int_eq(ret, COUNT_OK);
}
END_TEST

START_TEST(test_02_s21_negate) {
  s21_decimal value = {{1, 0, 0}, {{0, 0, 0, 0}}};
  s21_decimal result = DECIMAL_ZERO;

  int ret = s21_negate(value, &result);

  ck_assert_int_eq(result.data[0], 1);
  ck_assert_int_eq(result.data[1], 0);
  ck_assert_int_eq(result.data[2], 0);
  ck_assert_int_eq(result.head.sign, 1);
  ck_assert_int_eq(ret, COUNT_OK);
}
END_TEST

START_TEST(test_03_s21_negate) {
  s21_decimal value = {{__INT_MAX__, __INT_MAX__, __INT_MAX__}, {{0, 0, 0, 0}}};
  s21_decimal result = DECIMAL_ZERO;

  int ret = s21_negate(value, &result);

  ck_assert_int_eq(result.data[0], __INT_MAX__);
  ck_assert_int_eq(result.data[1], __INT_MAX__);
  ck_assert_int_eq(result.data[2], __INT_MAX__);
  ck_assert_int_eq(result.head.sign, 1);
  ck_assert_int_eq(ret, COUNT_OK);
}
END_TEST

START_TEST(test_04_s21_negate) {
  s21_decimal value = {{__INT_MAX__, __INT_MAX__, __INT_MAX__, 0xFF0000}};
  s21_decimal result = DECIMAL_ZERO;

  int ret = s21_negate(value, &result);

  ck_assert_int_eq(result.data[0], 0);
  ck_assert_int_eq(result.data[1], 0);
  ck_assert_int_eq(result.data[2], 0);
  ck_assert_int_eq(result.head.flags, 0);
  ck_assert_int_eq(ret, COUNT_ERROR);
}
END_TEST

START_TEST(s21_negate_1) {
  s21_decimal res_a = DECIMAL_ZERO;
  s21_decimal src = DECIMAL_ZERO;
  int result = 0;
  s21_from_int_to_decimal(10, &src);
  s21_negate(src, &res_a);
  s21_from_decimal_to_int(res_a, &result);
  ck_assert_int_eq(-10, result);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal res_a = DECIMAL_ZERO;
  s21_decimal src = DECIMAL_ZERO;
  float result = 0;
  s21_from_float_to_decimal(10.12345, &src);
  s21_negate(src, &res_a);
  s21_from_decimal_to_float(res_a, &result);
  ck_assert_float_eq(-10.12345, result);
}
END_TEST

START_TEST(s21_negate_3) {
  float a = 10.1234e5;
  s21_decimal res_a = {0};
  s21_decimal src = {0};
  float result = 0;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res_a);
  s21_from_decimal_to_float(res_a, &result);
  ck_assert_float_eq(-10.1234e5, result);
}
END_TEST

Suite *suite_s21_negate(void) {
  Suite *suite = suite_create("NEGATE test");

  TCase *tc = tcase_create("negate_test");

  tcase_add_test(tc, test_01_s21_negate);
  tcase_add_test(tc, test_02_s21_negate);
  tcase_add_test(tc, test_03_s21_negate);
  tcase_add_test(tc, test_04_s21_negate);
  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, s21_negate_3);

  suite_add_tcase(suite, tc);

  return suite;
}