#include "test.h"

START_TEST(test_01_s21_add) {
  DEC_INIT(a);
  DEC_INIT(b);
  DEC_INIT(c);
  DEC_INIT(res);
  a.data[0] = 1;
  b.data[0] = 1;
  c.data[0] = 2;
  ck_assert_int_eq(s21_add(a, b, &res), ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

START_TEST(test_02_s21_add) {
  DEC_INIT(a);
  DEC_INIT(b);
  DEC_INIT(c);
  DEC_INIT(res);
  a.data[0] = 1;
  a.head.sign = 1;
  b.data[0] = 1;
  c.data[0] = 0;
  ck_assert_int_eq(s21_add(a, b, &res), ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

START_TEST(test_03_s21_add) {
  DEC_INIT(a);
  DEC_INIT(b);
  DEC_INIT(c);
  DEC_INIT(res);
  a.data[0] = __UINT32_MAX__;
  b.data[0] = 1;
  c.data[1] = 1;
  ck_assert_int_eq(s21_add(a, b, &res), ARITHMETIC_OK);
  ck_assert_int_eq(res.data[0], 0);
  ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

START_TEST(test_04_s21_add) {
  DEC_INIT(a);
  DEC_INIT(b);
  DEC_INIT(res);
  a.data[0] = __UINT32_MAX__;
  a.data[1] = __UINT32_MAX__;
  a.data[2] = __UINT32_MAX__;
  b.data[0] = __UINT32_MAX__;
  ck_assert_int_eq(s21_add(a, b, &res), S21_INFINITY);
}
END_TEST

START_TEST(test_041_s21_add) {
  DEC_INIT(a);
  DEC_INIT(b);
  DEC_INIT(res);
  a.data[0] = __UINT32_MAX__;
  a.data[1] = __UINT32_MAX__;
  a.data[2] = __UINT32_MAX__;
  b.data[0] = 1;
  b.head.exp = 1;
  ck_assert_int_eq(s21_add(a, b, &res), S21_INFINITY);
}
END_TEST

START_TEST(test_044_s21_add) {
  DEC_INIT(a);
  DEC_INIT(b);
  DEC_INIT(c);
  DEC_INIT(res);
  a.data[0] = 123;
  a.head.exp = 2;

  b.data[0] = 1;

  c.data[0] = 223;
  c.head.exp = 2;

  ck_assert_int_eq(s21_add(a, b, &res), ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

START_TEST(test_05_s21_add) {
  DEC_INIT(a);
  DEC_INIT(b);
  DEC_INIT(c);
  DEC_INIT(res);
  a.data[0] = 1;
  b.data[0] = 1;
  c.data[0] = 2;
  a.head.sign = 1;
  b.head.sign = 1;
  c.head.sign = 1;

  ck_assert_int_eq(s21_add(a, b, &res), ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

START_TEST(test_06_s21_add) {
  DEC_INIT(a);
  DEC_INIT(b);
  DEC_INIT(res);
  a.data[0] = __UINT32_MAX__;
  a.data[1] = __UINT32_MAX__;
  a.data[2] = __UINT32_MAX__;
  a.head.sign = 1;
  b.data[0] = __UINT32_MAX__;
  b.head.sign = 1;
  ck_assert_int_eq(s21_add(a, b, &res), S21_NEGATIVE_INFINITY);
}
END_TEST

START_TEST(test_061_s21_add) {
  DEC_INIT(a);
  DEC_INIT(b);
  DEC_INIT(res);
  a.data[0] = __UINT32_MAX__;
  a.data[1] = __UINT32_MAX__;
  a.data[2] = __UINT32_MAX__;
  a.head.sign = 1;
  b.data[0] = 1;
  b.head.sign = 1;
  b.head.exp = 1;
  ck_assert_int_eq(s21_add(a, b, &res), S21_NEGATIVE_INFINITY);
}
END_TEST

Suite *suite_s21_add(void) {
  Suite *suite = suite_create("\n ===S21 ADD TEST===");
  TCase *tc_insert = tcase_create("add_test");

  tcase_add_test(tc_insert, test_01_s21_add);
  tcase_add_test(tc_insert, test_02_s21_add);
  tcase_add_test(tc_insert, test_03_s21_add);
  tcase_add_test(tc_insert, test_04_s21_add);
  tcase_add_test(tc_insert, test_041_s21_add);
  tcase_add_test(tc_insert, test_044_s21_add);
  tcase_add_test(tc_insert, test_05_s21_add);
  tcase_add_test(tc_insert, test_06_s21_add);
  tcase_add_test(tc_insert, test_061_s21_add);

  suite_add_tcase(suite, tc_insert);

  return suite;
}