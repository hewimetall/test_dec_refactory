#include "test.h"

START_TEST(s21_is_greater_1) {
  s21_decimal value_1 = {{0, 18, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{0, 18, 0}, {{0, 0, 0, 1}}};

  int res = FALSE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_2) {
  s21_decimal value_1 = {{13, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{0, 0, 0}, {{0}}};

  int res = FALSE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_3) {
  s21_decimal value_1 = {{165, 2, 0}, {{0}}};
  s21_decimal value_2 = {{0, 1, 2}, {{0, 0, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_4) {
  s21_decimal value_1 = {{0, 12, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{1, 0, 0}, {{0, 0, 0, 1}}};

  int res = FALSE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_5) {
  s21_decimal value_1 = {{0, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{0, 0, 0}, {{0, 0, 0, 1}}};

  int res = FALSE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_6) {
  s21_decimal value_1 = {{12, 0, 77}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{10, 151, 0}, {{0, 0, 0, 1}}};

  int res = FALSE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_7) {
  s21_decimal value_1 = {{5, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 0, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_8) {
  s21_decimal value_1 = {{5, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 0, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_9) {
  s21_decimal value_1 = {{12, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 0, 0, 1}}};

  int res = FALSE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_10) {
  s21_decimal value_1 = {{12, 0, 0}, {{0, 5, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 6, 0, 1}}};

  int res = FALSE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_11) {
  s21_decimal value_1 = {{12, 0, 0}, {{0, 6, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 5, 0, 1}}};

  int res = TRUE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_greater_12) {
  s21_decimal value_1 = {{12, 0, 0}, {{0, 6, 0, 1}}};
  s21_decimal value_2 = {{12, 0, 0}, {{0, 6, 0, 1}}};

  int res = FALSE;
  int res1 = s21_is_greater(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

Suite *suite_s21_is_greater(void) {
  Suite *suite = suite_create("=== GREATER       TEST ===");

  TCase *tc_insert = tcase_create("tc");

  tcase_add_test(tc_insert, s21_is_greater_1);
  tcase_add_test(tc_insert, s21_is_greater_2);
  tcase_add_test(tc_insert, s21_is_greater_3);
  tcase_add_test(tc_insert, s21_is_greater_4);
  tcase_add_test(tc_insert, s21_is_greater_5);
  tcase_add_test(tc_insert, s21_is_greater_6);
  tcase_add_test(tc_insert, s21_is_greater_7);
  tcase_add_test(tc_insert, s21_is_greater_8);
  tcase_add_test(tc_insert, s21_is_greater_9);
  tcase_add_test(tc_insert, s21_is_greater_10);
  tcase_add_test(tc_insert, s21_is_greater_11);
  tcase_add_test(tc_insert, s21_is_greater_12);

  suite_add_tcase(suite, tc_insert);

  return suite;
}