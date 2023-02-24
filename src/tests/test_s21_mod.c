#include <stdio.h>

#include "test.h"

START_TEST(basic_mod) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);
  DEC_INIT(true_ans);

  dec1.data[0] = 101;
  dec1.head.exp = 1;
  dec2.data[0] = 4;

  true_ans.data[0] = 21;
  true_ans.head.exp = 1;
  int status = s21_mod(dec1, dec2, &ans);

  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_mod_2) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);
  DEC_INIT(true_ans);

  dec1.data[0] = 4036421147;
  dec1.data[1] = 382;
  dec1.head.exp = 4;

  dec2.data[0] = 2945631615;
  dec2.data[1] = 658;
  dec2.head.exp = 6;

  true_ans.data[0] = 867247046;
  true_ans.data[1] = 90;
  true_ans.head.exp = 6;

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;
  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));

  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_mod_3) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);
  DEC_INIT(true_ans);

  dec1.data[0] = 2891627761;
  dec1.data[1] = 3474792174;
  dec1.data[2] = 8;
  dec1.head.flags = 2147811328;

  dec2.data[0] = 1870970698;
  dec2.data[1] = 1989793225;
  dec2.head.flags = 720896;

  true_ans.data[0] = 1717205652;
  true_ans.data[1] = 1236686312;
  true_ans.head.flags = 720896 + MINUS_SIGN;

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;
  // printf("true_ans = %d, ans = %d\n true_exp = %d, exp = %d\n true_sign = %d,
  // sign = %d\n ", true_ans.data[2], ans.data[2], true_ans.head.__,
  // ans.head.__, true_ans.head.___, ans.head.___);

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(readme_mod) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);
  DEC_INIT(true_ans);

  dec1.data[0] = 4294967295;
  dec1.data[1] = 4294967295;
  dec1.data[2] = 4294967295;

  dec2.data[0] = 1;
  dec2.head.flags = 196608;

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(division_on_zero) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);

  dec1.data[0] = 4294967295;
  dec1.data[1] = 4294967295;
  dec1.data[2] = 4294967295;

  dec2.data[0] = 0;
  dec2.head.flags = 196608;

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = S21_ZERO_DIV;

  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(division_zero) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);
  DEC_INIT(true_ans);
  dec1.data[0] = 0;
  dec1.head.flags = 196608;

  dec2.data[0] = 217948;
  dec2.head.flags = 196608;

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

Suite* suite_s21_mod(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("===S21 MOD TEST===");
  tc_core = tcase_create("tc");

  tcase_add_test(tc_core, basic_mod);
  tcase_add_test(tc_core, basic_mod_2);
  tcase_add_test(tc_core, basic_mod_3);
  tcase_add_test(tc_core, readme_mod);
  tcase_add_test(tc_core, division_on_zero);
  tcase_add_test(tc_core, division_zero);
  suite_add_tcase(s, tc_core);

  return s;
}
