#include "test.h"

START_TEST(s21_is_greater_or_equal_1) {
  s21_decimal value_1 = {{0, 18, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{0, 18, 0}, {{0, 0, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_2) {
  s21_decimal value_1 = {{13, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{0, 0, 0}, {{0}}};

  int res = FALSE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_3) {
  s21_decimal value_1 = {{165, 2, 0}, {{0}}};
  s21_decimal value_2 = {{0, 1, 2}, {{0, 0, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_4) {
  s21_decimal value_1 = {{0, 12, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{1, 0, 0}, {{0, 0, 0, 1}}};

  int res = FALSE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_5) {
  s21_decimal value_1 = {{0, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{0, 0, 0}, {{0, 0, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_6) {
  s21_decimal value_1 = {{12, 0, 77}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{10, 151, 0}, {{0, 0, 0, 1}}};

  int res = FALSE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_7) {
  s21_decimal value_1 = {{5, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 0, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_8) {
  s21_decimal value_1 = {{5, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 0, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_9) {
  s21_decimal value_1 = {{12, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 0, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_10) {
  s21_decimal value_1 = {{12, 0, 0}, {{0, 5, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 6, 0, 1}}};

  int res = FALSE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_11) {
  s21_decimal value_1 = {{12, 0, 0}, {{0, 6, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 5, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_12) {
  s21_decimal value_1 = {{12, 0, 0}, {{0, 6, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 6, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater_or_equal(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

Suite *suite_s21_is_greater_or_equal(void) {
  Suite *suite = suite_create("=== GREATER/EQUAL TEST ===");

  TCase *tc_insert = tcase_create("tc");

  tcase_add_test(tc_insert, s21_is_greater_or_equal_1);
  tcase_add_test(tc_insert, s21_is_greater_or_equal_2);
  tcase_add_test(tc_insert, s21_is_greater_or_equal_3);
  tcase_add_test(tc_insert, s21_is_greater_or_equal_4);
  tcase_add_test(tc_insert, s21_is_greater_or_equal_5);
  tcase_add_test(tc_insert, s21_is_greater_or_equal_6);
  tcase_add_test(tc_insert, s21_is_greater_or_equal_7);
  tcase_add_test(tc_insert, s21_is_greater_or_equal_8);
  tcase_add_test(tc_insert, s21_is_greater_or_equal_9);
  tcase_add_test(tc_insert, s21_is_greater_or_equal_10);
  tcase_add_test(tc_insert, s21_is_greater_or_equal_11);
  tcase_add_test(tc_insert, s21_is_greater_or_equal_12);

  suite_add_tcase(suite, tc_insert);

  return suite;
}