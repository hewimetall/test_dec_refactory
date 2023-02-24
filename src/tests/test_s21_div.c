#include <stdio.h>

#include "test.h"

START_TEST(short_div) {
  s21_decimal dec1 = {{65536, 0, 0}, {{0, 0, 0, 0}}};
  s21_decimal dec2 = {{32768, 0, 0}, {{0, 0, 0, 0}}};
  s21_decimal ans = DEC_NULL;
  s21_decimal true_ans = {{2, 0, 0}, {{0, 0, 0, 0}}};

  int status = s21_div(dec1, dec2, &ans);

  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_div) {
  s21_decimal dec1 = {{9, 0, 0}, {{0, 1, 0, 0}}};
  s21_decimal dec2 = {{6, 0, 0}, {{0, 1, 0, 0}}};
  s21_decimal ans = DEC_NULL;
  s21_decimal true_ans = {{15, 0, 0}, {{0, 1, 0, 0}}};

  int status = s21_div(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_div_2) {
  s21_decimal dec1 = {{14, 0, 0}, {{0, 0, 0, 0}}};
  s21_decimal dec2 = {{9, 0, 0}, {{0, 0, 0, 0}}};
  s21_decimal ans = DEC_NULL;
  s21_decimal true_ans = DEC_NULL;

  true_ans.data[0] = 3280877796;
  true_ans.data[1] = 1621842184;
  true_ans.data[2] = 843268356;
  true_ans.head.flags = 1835008;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_div_3) {
  s21_decimal dec1 = {{14, 0, 0}, {{0, 1, 0, 0}}};
  s21_decimal dec2 = {{9, 0, 0}, {{0, 1, 0, 1}}};
  s21_decimal ans = DEC_NULL;
  s21_decimal true_ans = DEC_NULL;

  true_ans.data[0] = 3280877796;
  true_ans.data[1] = 1621842184;
  true_ans.data[2] = 843268356;
  true_ans.head.exp = 28;
  true_ans.head.sign = 1;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(div_by_zero) {
  s21_decimal dec1 = {{2814903, 0, 0}, {{0, 1, 0, 0}}};
  s21_decimal dec2 = {{0, 0, 0}, {{0, 1, 0, 1}}};
  s21_decimal ans = DEC_NULL;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = S21_ZERO_DIV;
  // printf("true_ans = %d, ans = %d", true_ans.data[0], ans.data[0]);

  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(div_zero) {
  s21_decimal dec1 = {{0, 0, 0}, {{0, 1, 0, 0}}};
  s21_decimal dec2 = {{4578783, 0, 0}, {{0, 0, 0, 0}}};
  s21_decimal ans = DEC_NULL;
  s21_decimal true_ans = DEC_NULL;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(result_too_big) {
  s21_decimal dec1 = {{4294967294, 4294967294, 4294967294}, {{0, 0, 0, 0}}};
  s21_decimal dec2 = {{1, 0, 0}, {{0, 1, 0, 1}}};
  s21_decimal ans = DEC_NULL;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = S21_INFINITY;

  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(result_too_small) {
  s21_decimal dec1 = {{1, 0, 0}, {{0, 1, 0, 1}}};
  s21_decimal dec2 = {{4294967294, 4294967294, 4294967294}, {{0, 0, 0, 0}}};
  s21_decimal ans = DEC_NULL;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = S21_NEGATIVE_INFINITY;
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_div) {
  s21_decimal dec1 = {{4294967295, 4294967295, 4294967295}, {{0, 0, 0, 0}}};
  s21_decimal dec2 = {{1, 0, 0}, {{0, 0, 0, 0}}};
  s21_decimal ans = DEC_NULL;
  s21_decimal true_ans = {{4294967295, 4294967295, 4294967295}, {{0, 0, 0, 0}}};

  dec1.head.flags = 1179648;
  dec2.head.flags = 1179648;

  int status = s21_div(dec1, dec2, &ans);
  // printf("true_ans = %d, ans = %d", true_ans.data[0], ans.data[0]);

  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_div_2) {
  s21_decimal dec1 = {{4294967295, 4294967295, 4294967295}, {{0, 0, 0, 0}}};
  s21_decimal dec2 = {{4294967295, 4294967295, 4294967295}, {{0, 0, 0, 1}}};
  s21_decimal ans = DEC_NULL;
  s21_decimal true_ans = {{1, 0, 0}, {{0, 0, 0, 1}}};

  int status = s21_div(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_div_3) {
  s21_decimal dec1 = {{1996679748, 4232406046, 151016884}, {{0, 0, 0, 0}}};
  s21_decimal dec2 = {{2671657829, 165868194, 0}, {{0, 0, 0, 0}}};
  s21_decimal ans = DEC_NULL;
  s21_decimal true_ans = {{178532910, 4081246736, 2119837296}, {{0, 0, 0, 0}}};

  dec1.head.flags = 2148335616;
  dec2.head.flags = 327680;
  true_ans.head.flags = 2149253120;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;
  // printf("true_ans = %u, ans = %u\n", true_ans.head.exp, ans.head.exp);

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}

START_TEST(big_values_div_4) {
  s21_decimal dec1 = {{1188260494, 2547073670, 423}, {{0, 0, 0, 0}}};
  s21_decimal dec2 = {{1658453339, 2896612263, 67010}, {{0, 0, 0, 0}}};
  s21_decimal ans = DEC_NULL;
  s21_decimal true_ans = {{2998137797, 614149364, 3426771}, {{0, 0, 0, 0}}};

  dec1.head.flags = 786432;
  dec2.head.flags = 786432;
  true_ans.head.flags = 1835008;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = ARITHMETIC_OK;
  // printf("true_ans = %d, ans = %u\n", true_ans.data[2], ans.data[2]);

  ck_assert_int_eq(TRUE, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}

Suite* suite_s21_div(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("===S21 DIV TEST===");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, short_div);
  tcase_add_test(tc_core, basic_div);
  tcase_add_test(tc_core, basic_div_2);
  tcase_add_test(tc_core, basic_div_3);
  tcase_add_test(tc_core, div_by_zero);
  tcase_add_test(tc_core, div_zero);
  tcase_add_test(tc_core, result_too_small);
  tcase_add_test(tc_core, result_too_big);
  tcase_add_test(tc_core, big_values_div);
  tcase_add_test(tc_core, big_values_div_2);
  tcase_add_test(tc_core, big_values_div_3);
  tcase_add_test(tc_core, big_values_div_4);
  suite_add_tcase(s, tc_core);

  return s;
}