#include "test.h"

START_TEST(test_01_def_mul) {
  s21_decimal value_1 = {{13, 0, 0}, {{0, 0, 0, 0}}};
  s21_decimal value_2 = {{10, 0, 0}, {{0, 0, 0, 0}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), ARITHMETIC_OK);

  ck_assert_int_eq(result.data[0], 130);
  ck_assert_int_eq(result.data[1], 0x00000000);
  ck_assert_int_eq(result.data[2], 0x00000000);
}
END_TEST

START_TEST(test_02_def_mul) {
  s21_decimal value_1 = {{0x4CCCD0B4, 0x3018, 0}, {{0, 0, 0, 0}}};
  s21_decimal value_2 = {{10, 0, 0}, {{0, 0, 0, 0}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), ARITHMETIC_OK);

  ck_assert_int_eq(result.data[0], 0x00002708);
  ck_assert_int_eq(result.data[1], 0x0001E0F3);
  ck_assert_int_eq(result.data[2], 0x00000000);
}
END_TEST

START_TEST(test_03_def_mul) {
  s21_decimal value_1 = {{0x3C, 0, 0}, {{0, 0, 0, 0}}};
  s21_decimal value_2 = {{10, 0, 0}, {{0, 0, 0, 0}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), ARITHMETIC_OK);

  ck_assert_int_eq(result.data[0], 0x00000258);
  ck_assert_int_eq(result.data[1], 0x00000000);
  ck_assert_int_eq(result.data[2], 0x00000000);
}
END_TEST

START_TEST(test_04_overfull_mul) {
  s21_decimal value_1 = {{0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{111, 111, 111}, {{0, 0, 0, 1}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), COUNT_ERROR);

  ck_assert_int_eq(result.data[0], 0);
  ck_assert_int_eq(result.data[1], 0);
  ck_assert_int_eq(result.data[2], 0);
}
END_TEST

START_TEST(test_05_2field_ttest) {
  s21_decimal value_1 = {{0x52231, 0x233, 0}, {{0, 0, 0, 0}}};
  s21_decimal value_2 = {{1241, 0, 0}, {{0, 0, 0, 0}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), ARITHMETIC_OK);

  ck_assert_int_eq(result.data[0], 0x18E2BF89);
  ck_assert_int_eq(result.data[1], 0x000AA93B);
  ck_assert_int_eq(result.data[2], 0x00000000);
}
END_TEST

START_TEST(test_06_diffSigns_mul) {
  s21_decimal value_1 = {{254, 0, 0}, {{0, 0, 0, 0}}};
  s21_decimal value_2 = {{430, 0, 0}, {{0, 0, 0, 1}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), ARITHMETIC_OK);

  ck_assert_int_eq(result.data[0], 0x1AAA4);
  ck_assert_int_eq(result.data[1], 0x00000000);
  ck_assert_int_eq(result.data[2], 0x00000000);
  ck_assert_int_eq(result.head.sign, 1);
}
END_TEST

START_TEST(test_07_samesigns_mul) {
  s21_decimal value_1 = {{254, 0, 0}, {{0, 0, 0, 1}}};
  s21_decimal value_2 = {{430, 0, 0}, {{0, 0, 0, 1}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), ARITHMETIC_OK);

  ck_assert_int_eq(result.data[0], 0x1AAA4);
  ck_assert_int_eq(result.data[1], 0x00000000);
  ck_assert_int_eq(result.data[2], 0x00000000);
  ck_assert_int_eq(result.head.sign, 0);
}
END_TEST

START_TEST(test_08_3fields_mul) {
  s21_decimal value_1 = {{1, 1, 1}, {{0, 0, 0, 0}}};
  s21_decimal value_2 = {{2, 0, 0}, {{0, 0, 0, 0}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), ARITHMETIC_OK);

  ck_assert_int_eq(result.data[0], 2);
  ck_assert_int_eq(result.data[1], 2);
  ck_assert_int_eq(result.data[2], 2);
  ck_assert_int_eq(result.head.sign, 0);
}
END_TEST

START_TEST(test_09_mulbyzero_mul) {
  s21_decimal value_1 = {{1, 1, 1}, {{0, 0, 0, 0}}};
  s21_decimal value_2 = {{0, 0, 0}, {{0, 0, 0, 0}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), ARITHMETIC_OK);

  ck_assert_int_eq(result.data[0], 0);
  ck_assert_int_eq(result.data[1], 0);
  ck_assert_int_eq(result.data[2], 0);
  ck_assert_int_eq(result.head.sign, 0);
}
END_TEST

START_TEST(test_10_overfull_mul) {
  s21_decimal value_1 = {{0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00}, {{0, 0, 0, 0}}};
  s21_decimal value_2 = {{111, 111, 111}, {{0, 0, 0, 1}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), S21_NEGATIVE_INFINITY);

  ck_assert_int_eq(result.data[0], 0);
  ck_assert_int_eq(result.data[1], 0);
  ck_assert_int_eq(result.data[2], 0);
}
END_TEST

START_TEST(test_11_overfull_exp_mul) {
  s21_decimal value_1 = {{0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00}, {{0, 0, 0, 0}}};
  s21_decimal value_2 = {{111, 111, 111}, {{0, 1, 0, 0}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), COUNT_ERROR);

  ck_assert_int_eq(result.data[0], 0);
  ck_assert_int_eq(result.data[1], 0);
  ck_assert_int_eq(result.data[2], 0);
}
END_TEST

START_TEST(test_12_overfull_exp_mul) {
  s21_decimal value_1 = {{0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00}, {{0, 0, 0, 0}}};
  s21_decimal value_2 = {{111, 111, 111}, {{0, 1, 0, 1}}};
  DEC_INIT(result);

  ck_assert_int_eq(s21_mul(value_1, value_2, &result), S21_NEGATIVE_INFINITY);

  ck_assert_int_eq(result.data[0], 0);
  ck_assert_int_eq(result.data[1], 0);
  ck_assert_int_eq(result.data[2], 0);
}
END_TEST

Suite *suite_s21_mul(void) {
  Suite *suite = suite_create("===S21 MUL TEST===");

  TCase *tc_insert = tcase_create("mul_test");

  tcase_add_test(tc_insert, test_01_def_mul);
  tcase_add_test(tc_insert, test_02_def_mul);
  tcase_add_test(tc_insert, test_03_def_mul);
  tcase_add_test(tc_insert, test_04_overfull_mul);
  tcase_add_test(tc_insert, test_05_2field_ttest);
  tcase_add_test(tc_insert, test_06_diffSigns_mul);
  tcase_add_test(tc_insert, test_07_samesigns_mul);
  tcase_add_test(tc_insert, test_08_3fields_mul);
  tcase_add_test(tc_insert, test_09_mulbyzero_mul);
  tcase_add_test(tc_insert, test_10_overfull_mul);
  tcase_add_test(tc_insert, test_11_overfull_exp_mul);
  tcase_add_test(tc_insert, test_12_overfull_exp_mul);

  suite_add_tcase(suite, tc_insert);

  return suite;
}
