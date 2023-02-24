#include "test.h"

START_TEST(s21_is_less_1) {
  s21_decimal value_1 = {{0, 15, 0}, {{0}}};  // 64424509440
  s21_decimal value_2 = {{1, 0, 0}, {{0}}};   //
  value_1.head.sign = 1;
  value_2.head.sign = 1;
  int res = 1;
  int res1 = s21_is_less(value_1, value_2);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_less_2) {
  s21_decimal value_1 = {{
                             1,
                             15,
                             0,
                         },
                         {{0}}};
  s21_decimal value_2 = {{0x0000000F, 0x00000001, 0}, {{0}}};

  int res = 0;
  int res1 = s21_is_less(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_less_3) {
  s21_decimal value_1 = {{
                             1,
                             0,
                             0,
                         },
                         {{0}}};
  s21_decimal value_2 = {{151, 13, 0}, {{0}}};
  value_2.head.sign = 1;

  int res = 0;
  int res1 = s21_is_less(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_less_4) {
  s21_decimal value_1 = {{13, 13, 37}, {{0}}};
  s21_decimal value_2 = {{0, 0, 0}, {{0}}};
  value_1.head.sign = 1;

  int res = 1;
  int res1 = s21_is_less(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_less_5) {
  s21_decimal value_1 = {{5, 8, 13}, {{0}}};
  s21_decimal value_2 = {{3, 0, 0}, {{0}}};

  int res = 0;
  int res1 = s21_is_less(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_less_6) {
  s21_decimal value_1 = {{7, 1311, 0}, {{0}}};
  s21_decimal value_2 = {{8, 0, 13}, {{0}}};

  value_1.head.sign = 1;
  value_2.head.sign = 1;

  int res = FALSE;
  int res1 = s21_is_less(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_is_less_7) {
  s21_decimal value_1 = {{2, 0, 121}, {{0}}};
  s21_decimal value_2 = {{0, 12, 11}, {{0}}};
  value_2.head.sign = 1;

  int res = 0;
  int res1 = s21_is_less(value_1, value_2);

  ck_assert_int_eq(res, res1);
}
END_TEST

Suite *suite_s21_is_less(void) {
  Suite *suite = suite_create("=== LESS          TEST ===");

  TCase *tc_insert = tcase_create("tc");

  tcase_add_test(tc_insert, s21_is_less_1);
  tcase_add_test(tc_insert, s21_is_less_2);
  tcase_add_test(tc_insert, s21_is_less_3);
  tcase_add_test(tc_insert, s21_is_less_4);
  tcase_add_test(tc_insert, s21_is_less_5);
  tcase_add_test(tc_insert, s21_is_less_6);
  tcase_add_test(tc_insert, s21_is_less_7);
  suite_add_tcase(suite, tc_insert);

  return suite;
}