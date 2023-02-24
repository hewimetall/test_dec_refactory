#include "test.h"

START_TEST(from_float_to_decimal_simple) {
  DEC_INIT(decimal);
  DEC_INIT(res);
  res.data[0] = 1005;
  res.head.exp = 1;
  int status = 0;
  float number = 100.5;

  s21_from_float_to_decimal(number, &decimal);
  status = s21_is_equal(res, decimal);

  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(float_eq_float) {
  DEC_INIT(decimal);
  float A = 100.5;
  float B = 0.0;

  s21_from_float_to_decimal(A, &decimal);
  s21_from_decimal_to_float(decimal, &B);

  ck_assert_float_eq(A, B);
}
END_TEST

START_TEST(float_eq_float_minus) {
  DEC_INIT(decimal);
  float A = -100.5;
  float B = 0.0;

  s21_from_float_to_decimal(A, &decimal);
  s21_from_decimal_to_float(decimal, &B);

  ck_assert_float_eq(A, B);
}
END_TEST

START_TEST(float_eq_float_hard_test) {
  DEC_INIT(decimal);
  float A = -1000.201;
  float B = 0.0;

  s21_from_float_to_decimal(A, &decimal);
  s21_from_decimal_to_float(decimal, &B);

  ck_assert_float_eq(A, B);
}
END_TEST

START_TEST(float_decimal_float_1) {
  DEC_INIT(decimal);
  float f = 0.0016;

  s21_from_float_to_decimal(f, &decimal);

  ck_assert_float_eq(decimal.data[0], 16);
}
END_TEST

START_TEST(float_decimal_float_2) {
  DEC_INIT(decimal);
  float f = -3.0, res = 0;

  s21_from_float_to_decimal(f, &decimal);
  s21_from_decimal_to_float(decimal, &res);

  ck_assert_float_eq(f, res);
}
END_TEST

START_TEST(float_decimal_float_3) {
  DEC_INIT(decimal);
  float f = 0, res = 0;

  s21_from_float_to_decimal(f, &decimal);
  s21_from_decimal_to_float(decimal, &res);

  ck_assert_float_eq(f, res);
}
END_TEST

Suite* suite_s21_from_float_to_decimal(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("=== FROM_FLOAT_TO_DEC     TEST ===");
  tc_core = tcase_create("tc");

  tcase_add_test(tc_core, float_decimal_float_1);
  tcase_add_test(tc_core, float_decimal_float_2);
  tcase_add_test(tc_core, float_decimal_float_3);

  tcase_add_test(tc_core, from_float_to_decimal_simple);
  tcase_add_test(tc_core, float_eq_float);
  tcase_add_test(tc_core, float_eq_float_minus);
  tcase_add_test(tc_core, float_eq_float_hard_test);

  suite_add_tcase(s, tc_core);

  return s;
}