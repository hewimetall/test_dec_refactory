#include "test.h"

START_TEST(from_float_to_decimal_simple) {
  DEC_INIT(decimal);
  s21_decimal res = {{1005, 0, 0}, {{0, 1, 0, 0}}};
  int status = 0;
  float number = 100.5;

  ck_assert_int_eq(s21_from_float_to_decimal(number, &decimal), 0);
  status = s21_is_equal(res, decimal);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(float_eq_float) {
  DEC_INIT(decimal);
  float A = 100.5;
  float B = 0.0;

  ck_assert_int_eq(s21_from_float_to_decimal(A, &decimal), 0);
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &B), 0);

  ck_assert_float_eq(A, B);
}
END_TEST

START_TEST(float_eq_float_minus) {
  DEC_INIT(decimal);
  float A = -100.5;
  float B = 0.0;

  ck_assert_int_eq(s21_from_float_to_decimal(A, &decimal), 0);
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &B), 0);

  ck_assert_float_eq(A, B);
}
END_TEST

START_TEST(float_eq_float_hard_test) {
  DEC_INIT(decimal);
  float A = -1000.201;
  float B = 0.0;

  ck_assert_int_eq(s21_from_float_to_decimal(A, &decimal), 0);
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &B), 0);

  ck_assert_float_eq(A, B);
}
END_TEST

START_TEST(float_decimal_float_1) {
  DEC_INIT(decimal);
  float f = 0.0000000001, res = 0;

  ck_assert_int_eq(s21_from_float_to_decimal(f, &decimal), 0);
  printf("%d - %d\n", decimal.data[0], decimal.head.exp);
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &res), 0);

  ck_assert_float_eq(res, 0);
}
END_TEST

START_TEST(float_decimal_float_2) {
  DEC_INIT(decimal);
  float f = -3.0, res = 0;

  ck_assert_int_eq(s21_from_float_to_decimal(f, &decimal), 0);
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &res), 0);

  ck_assert_float_eq(f, res);
}
END_TEST

START_TEST(float_decimal_float_3) {
  DEC_INIT(decimal);
  float f = 0., res = 0.;

  ck_assert_int_eq(s21_from_float_to_decimal(f, &decimal), 0);
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &res), 0);

  ck_assert_float_eq(f, res);
}
END_TEST

START_TEST(float_decimal_float_5) {
  DEC_INIT(decimal);
  float f = 7.9e29, res = 0;

  ck_assert_int_eq(s21_from_float_to_decimal(f, &decimal), 1);
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &res), 0);

  ck_assert_float_eq(0, res);
}
END_TEST

Suite* float_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("conversion");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, float_decimal_float_1);
  tcase_add_test(tc_core, float_decimal_float_2);
  tcase_add_test(tc_core, float_decimal_float_3);
  tcase_add_test(tc_core, float_decimal_float_5);

  tcase_add_test(tc_core, from_float_to_decimal_simple);
  tcase_add_test(tc_core, float_eq_float);
  tcase_add_test(tc_core, float_eq_float_minus);
  tcase_add_test(tc_core, float_eq_float_hard_test);

  suite_add_tcase(s, tc_core);

  return s;
}