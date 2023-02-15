#include "test_main.h"

START_TEST(basic_mod) {
  s21_decimal dec1 = DECIMAL_ZERO;
  s21_decimal dec2 = DECIMAL_ZERO;
  s21_decimal ans = DECIMAL_ZERO;
  s21_decimal true_ans = DECIMAL_ZERO;

  dec1.data[0] = 10;
  dec2.data[0] = 4;

  true_ans.data[0] = 2;

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_mod_2) {
  s21_decimal dec1 = DECIMAL_ZERO;
  s21_decimal dec2 = DECIMAL_ZERO;
  s21_decimal ans = DECIMAL_ZERO;
  s21_decimal true_ans = DECIMAL_ZERO;

  dec1.data[0] = 4036421147;
  dec1.data[1] = 382;
  dec1.data[3] = 262144;

  dec2.data[0] = 2945631615;
  dec2.data[1] = 658;
  dec2.data[3] = 2147876864;

  true_ans.data[0] = 867247046;
  true_ans.data[1] = 90;
  true_ans.data[3] = 393216;

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_mod_3) {
  s21_decimal dec1 = DECIMAL_ZERO;
  s21_decimal dec2 = DECIMAL_ZERO;
  s21_decimal ans = DECIMAL_ZERO;
  s21_decimal true_ans = DECIMAL_ZERO;

  dec1.data[0] = 2891627761;
  dec1.data[1] = 3474792174;
  dec1.data[2] = 8;
  dec1.data[3] = 2147811328;

  dec2.data[0] = 1870970698;
  dec2.data[1] = 1989793225;
  dec2.data[3] = 720896;

  true_ans.data[0] = 1717205652;
  true_ans.data[1] = 1236686312;
  true_ans.data[3] = 720896 + MINUS_SIGN;

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(readme_mod) {
  s21_decimal dec1 = DECIMAL_ZERO;
  s21_decimal dec2 = DECIMAL_ZERO;
  s21_decimal ans = DECIMAL_ZERO;
  s21_decimal true_ans = DECIMAL_ZERO;

  dec1.data[0] = 4294967295;
  dec1.data[1] = 4294967295;
  dec1.data[2] = 4294967295;

  dec2.data[0] = 1;
  dec2.data[3] = 196608;

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(division_on_zero) {
  s21_decimal dec1 = DECIMAL_ZERO;
  s21_decimal dec2 = DECIMAL_ZERO;
  s21_decimal ans = DECIMAL_ZERO;

  dec1.data[0] = 4294967295;
  dec1.data[1] = 4294967295;
  dec1.data[2] = 4294967295;

  dec2.data[0] = 0;
  dec2.data[3] = 196608;

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = S21_ZERO_DIV;

  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(division_zero) {
  s21_decimal dec1 = DECIMAL_ZERO;
  s21_decimal dec2 = DECIMAL_ZERO;
  s21_decimal ans = DECIMAL_ZERO;
  s21_decimal true_ans = DECIMAL_ZERO;
  dec1.data[0] = 0;
  dec1.data[3] = 196608;

  dec2.data[0] = 217948;
  dec2.data[3] = 196608;

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

Suite* suite_s21_mod(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_mod");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, basic_mod);
  tcase_add_test(tc_core, basic_mod_2);
  tcase_add_test(tc_core, basic_mod_3);
  tcase_add_test(tc_core, readme_mod);
  tcase_add_test(tc_core, division_on_zero);
  tcase_add_test(tc_core, division_zero);
  suite_add_tcase(s, tc_core);

  return s;
}