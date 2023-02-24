#include <check.h>

#include "test.h"

START_TEST(s21_small_negative_01) {
  s21_decimal dec1 = {{165, 0, 0}, {{0, 1, 0, 1}}};
  s21_decimal result = {{17, 0, 0}, {{0, 0, 0, 1}}};
  DEC_INIT(res1);
  ck_assert_int_eq(s21_floor(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.sign, result.head.sign);
}
END_TEST

START_TEST(s21_big_positive_floor_02) {
  s21_decimal dec1 = {{0xFFFFFFFF, 0x3FFFFF, 0}, {{0, 3, 0, 0}}};
  s21_decimal result = {{0x4DD2F1A9, 0x1062, 0}, {{0, 0, 0, 0}}};
  DEC_INIT(res1);
  ck_assert_int_eq(s21_floor(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.sign, result.head.sign);
}
END_TEST

START_TEST(s21_def_negative_floor_03) {
  s21_decimal dec1 = {{0xF7274, 0, 0}, {{0, 3, 0, 1}}};
  s21_decimal result = {{0x3F5, 0, 0}, {{0, 0, 0, 1}}};
  DEC_INIT(res1);
  ck_assert_int_eq(s21_floor(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.sign, result.head.sign);
}
END_TEST

START_TEST(s21_floor_4) {
  DEC_INIT(dec1);
  dec1.data[0] = 0b10000000000000000000001111110100;  // 112590205.4327284
  dec1.data[1] = 0b00000000000001000000000000000000;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b10000000000001110000000000000000;
  DEC_INIT(result);
  result.data[0] = 0b00000110101101011111110101111101;  // 112590205
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b10000000000000000000000000000000;
  DEC_INIT(res1);
  ck_assert_int_eq(s21_floor(dec1, &res1), 0);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.sign, result.head.sign);
}
END_TEST

START_TEST(s21_floor_5) {
  DEC_INIT(dec1);
  dec1.data[0] = 0b10000000000000000000001111110100;  // 2147484660
  dec1.data[1] = 0b00000000000000000000000000000000;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b00000000000000000000000000000000;
  DEC_INIT(result);
  result.data[0] = 0b10000000000000000000001111110100;  // 2147484660
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b00000000000000000000000000000000;
  DEC_INIT(res1);
  ck_assert_int_eq(s21_floor(dec1, &res1), 0);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.sign, result.head.sign);
}
END_TEST

START_TEST(s21_floor_6) {
  DEC_INIT(dec1);

  dec1.data[0] = 0b01100011000011111111111111111111;  // -9999999999.9999999999
  dec1.data[1] = 0b01101011110001110101111000101101;
  dec1.data[2] = 0b00000000000000000000000000000101;
  dec1.head.flags = 0b10000000000010100000000000000000;  // 10
  DEC_INIT(result);
  result.data[0] = 0b01010100000010111110010000000000;  // -10000000000
  result.data[1] = 0b00000000000000000000000000000010;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b10000000000000000000000000000000;
  DEC_INIT(res1);
  ck_assert_int_eq(s21_floor(dec1, &res1), 0);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.sign, result.head.sign);
}
END_TEST

START_TEST(s21_floor_7) {
  DEC_INIT(dec1);
  dec1.data[0] = 0b01010101001110101110101110110001;  // -0.987654321287654321
  dec1.data[1] = 0b00001101101101001101101001011111;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b10000000000100100000000000000000;  // 18
  DEC_INIT(result);
  result.data[0] = 0b00000000000000000000000000000001;  // -1
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b10000000000000000000000000000000;
  DEC_INIT(res1);
  ck_assert_int_eq(s21_floor(dec1, &res1), 0);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.sign, result.head.sign);
}
END_TEST

START_TEST(s21_floor_8) {
  DEC_INIT(dec1);
  dec1.data[0] = 0b10010011111100000001110001010010;  // 123.9432567890
  dec1.data[1] = 0b00000000000000000000000100100000;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b00000000000010100000000000000000;
  DEC_INIT(result);
  result.data[0] = 0b00000000000000000000000001111011;  // 123
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b00000000000000000000000000000000;
  DEC_INIT(res1);
  ck_assert_int_eq(s21_floor(dec1, &res1), 0);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.sign, result.head.sign);
}
END_TEST

START_TEST(s21_floor_9) {
  s21_decimal dec1 = {{2, 0, 121}, {{1, 1, 1, 1}}};
  DEC_INIT(res1);
  ck_assert_int_eq(s21_floor(dec1, &res1), CONVERTATION_ERROR);
}
END_TEST

Suite *suite_s21_floor(void) {
  Suite *s = suite_create("=== FLOOR     TEST ===");

  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, s21_small_negative_01);
  tcase_add_test(tc, s21_big_positive_floor_02);
  tcase_add_test(tc, s21_def_negative_floor_03);
  tcase_add_test(tc, s21_floor_4);
  tcase_add_test(tc, s21_floor_5);
  tcase_add_test(tc, s21_floor_6);
  tcase_add_test(tc, s21_floor_7);
  tcase_add_test(tc, s21_floor_8);
  tcase_add_test(tc, s21_floor_9);

  suite_add_tcase(s, tc);

  return s;
}
