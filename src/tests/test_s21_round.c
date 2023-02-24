#include "test.h"

START_TEST(s21_round_1) {
  s21_decimal dec1;
  dec1.data[0] = 0b00000000000000000000000010100101;
  dec1.data[1] = 0b00000000000000000000000000000000;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b10000000000000010000000000000000;
  s21_decimal result;
  result.data[0] = 0b00000000000000000000000000010001;
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b10000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal dec1;
  dec1.data[0] = 0b11111111111111111111111111111111;
  dec1.data[1] = 0b00000000001111111111111111111111;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b00000000000000110000000000000000;
  s21_decimal result;
  result.data[0] = 0b01001101110100101111000110101010;
  result.data[1] = 0b00000000000000000001000001100010;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b00000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal dec1;
  dec1.data[0] = 0b00000000000011110111001001110100;
  dec1.data[1] = 0b00000000000000000000000000000000;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b10000000000000110000000000000000;
  s21_decimal result;
  result.data[0] = 0b00000000000000000000001111110100;
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b10000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal dec1;
  dec1.data[0] = 0b10000000000000000000001111110100;
  dec1.data[1] = 0b00000000000001000000000000000000;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b10000000000001110000000000000000;
  s21_decimal result;
  result.data[0] = 0b00000110101101011111110101111101;
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b10000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal dec1;
  dec1.data[0] = 0b10000000000000000000001111110100;
  dec1.data[1] = 0b00000000000000000000000000000000;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b00000000000000000000000000000000;
  s21_decimal result;
  result.data[0] = 0b10000000000000000000001111110100;
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b00000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal dec1;

  dec1.data[0] = 0b01100011000011111111111111111111;
  dec1.data[1] = 0b01101011110001110101111000101101;
  dec1.data[2] = 0b00000000000000000000000000000101;
  dec1.head.flags = 0b10000000000010100000000000000000;
  s21_decimal result;
  result.data[0] = 0b01010100000010111110010000000000;
  result.data[1] = 0b00000000000000000000000000000010;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b10000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal dec1;
  dec1.data[0] = 0b01010101001110101110101110110001;
  dec1.data[1] = 0b00001101101101001101101001011111;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b10000000000100100000000000000000;
  s21_decimal result;
  result.data[0] = 0b00000000000000000000000000000001;
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b10000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal dec1;
  dec1.data[0] = 0b10010011111100000001110001010010;
  dec1.data[1] = 0b00000000000000000000000100100000;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b00000000000010100000000000000000;
  s21_decimal result;
  result.data[0] = 0b00000000000000000000000001111100;
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b00000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_9) {
  s21_decimal dec1;
  dec1.data[0] = 0b11001101110001110111110001000000;
  dec1.data[1] = 0b00111110001001010000001001100000;
  dec1.data[2] = 0b00100000010011111100111001011110;
  dec1.head.flags = 0b10000000000001000000000000000000;
  s21_decimal result;
  result.data[0] = 0b10100000111111100100111000000100;
  result.data[1] = 0b00011011110011101100110011101101;
  result.data[2] = 0b00000000000000001101001111000010;
  result.head.flags = 0b10000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);

  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_10) {
  s21_decimal dec1;
  dec1.data[0] = 0b10100000111111100100111000000100;
  dec1.data[1] = 0b00011011110011101100110011101101;
  dec1.data[2] = 0b00000000000000001101001111000010;
  dec1.head.flags = 0b00000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  s21_decimal result;
  result.data[0] = 0b10100000111111100100111000000100;
  result.data[1] = 0b00011011110011101100110011101101;
  result.data[2] = 0b00000000000000001101001111000010;
  result.head.flags = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_11) {
  s21_decimal dec1;
  dec1.data[0] = 0b10010111011100111001111111111111;
  dec1.data[1] = 0b00111100000010000011000110001101;
  dec1.data[2] = 0b00000000000000000000000000000001;
  dec1.head.flags = 0b00000000000001110000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  s21_decimal result;
  result.data[0] = 0b00110110101101101000110001000000;
  result.data[1] = 0b00000000000000000000001000010010;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal dec1;
  dec1.data[0] = 0b10010111011100111001111111111111;
  dec1.data[1] = 0b00111100000010000011000110001101;
  dec1.data[2] = 0b00000000000000000000000000000001;
  dec1.head.flags = 0b10000000000001110000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  s21_decimal result;
  result.data[0] = 0b00110110101101101000110001000000;
  result.data[1] = 0b00000000000000000000001000010010;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b10000000000000000000000000000000;
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_roundTest1) {
  s21_decimal src1, origin;
  src1.data[0] = 2;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b00000000000000000000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 2;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest2) {
  s21_decimal src1, origin;
  src1.data[0] = 0b00000000000000000000000000100011;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b00000000000000010000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b00000000000000000000000000000100;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest3) {
  s21_decimal src1, origin;
  src1.data[0] = 0b00000000000000000000000000100011;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b10000000000000010000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b00000000000000000000000000000100;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest4) {
  s21_decimal src1, origin;
  src1.data[0] = 0b00000000000000000000000000000000;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b00000000000000000000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b00000000000000000000000000000000;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest5) {
  s21_decimal src1, origin;
  src1.data[0] = 0b11011110101101001010101001100001;
  src1.data[1] = 0b11110100111110000101111011101001;
  src1.data[2] = 0b00000000000000000000000000000010;
  src1.head.flags = 0b10000000000001010000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b10000110011101001011101110010001;
  origin.data[1] = 0b00000000000000011111000000010110;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest6) {
  s21_decimal src1, origin;
  src1.data[0] = 0b00000111100110110001111110011000;
  src1.data[1] = 0b01100110010010001001000110100011;
  src1.data[2] = 0b00000000000001001000101100011101;
  src1.head.flags = 0b10000000000110000000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b00000000000000000000000000000101;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest7) {
  s21_decimal src1, origin;
  src1.data[0] = 0b01001110111001000011100101110110;
  src1.data[1] = 0b01001011001101011010000111011001;
  src1.data[2] = 0b00011001101110010111010010111111;
  src1.head.flags = 0b00000000000011110000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b10100100000111100100000000101110;
  origin.data[1] = 0b00000000000000000000011100111101;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest8) {
  s21_decimal src1, origin;
  src1.data[0] = 0b01111000100010101111010011001010;
  src1.data[1] = 0b01100010000010101110010010000111;
  src1.data[2] = 0b00100111111001000001101011010101;
  src1.head.flags = 0b10000000000101010000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b00000000101111000110000101001101;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest9) {
  s21_decimal src1, origin;
  src1.data[0] = 0b10101111110010001101100101011111;
  src1.data[1] = 0b01101000101000101011010010000001;
  src1.data[2] = 0b00000000000000000000000000000001;
  src1.head.flags = 0b00000000000100110000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b00000000000000000000000000000011;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest10) {
  s21_decimal src1, origin;
  src1.data[0] = 0b00000000000000000000000000000001;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b00000000000000000000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b00000000000000000000000000000001;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest11) {
  s21_decimal src1, origin;
  src1.data[0] = 0b00000000000000000000000000001011;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b00000000000000010000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b00000000000000000000000000000001;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest12) {
  s21_decimal src1, origin;
  src1.data[0] = 0b00000000000000000000000000001011;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b10000000000000010000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b00000000000000000000000000000001;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest13) {
  s21_decimal src1, origin;
  src1.data[0] = 0b00000000000000000000100110011000;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b00000000000000100000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b00000000000000000000000000011001;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_roundTest14) {
  s21_decimal src1, origin;
  src1.data[0] = 0b00000000000000000000100001001100;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b10000000000000110000000000000000;
  DEC_INIT(result);
  ck_assert_int_eq(s21_round(src1, &result), CONVERTATION_OK);
  origin.data[0] = 0b00000000000000000000000000000010;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_round_2_5) {
  s21_decimal dec1;
  dec1.data[0] = 0b00000000000000000000000000011001;
  dec1.data[1] = 0b00000000000000000000000000000000;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.data[0] = 0b00000000000000000000000000000011;
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b00000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_3_5) {
  s21_decimal dec1;
  dec1.data[0] = 0b00000000000000000000000000100011;
  dec1.data[1] = 0b00000000000000000000000000000000;
  dec1.data[2] = 0b00000000000000000000000000000000;
  dec1.head.flags = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.data[0] = 0b00000000000000000000000000000100;
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b00000000000000000000000000000000;
  s21_decimal res1;
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_round_13) {
  s21_decimal dec1 = {{2, 0, 121}, {{1, 1, 1, 1}}};
  DEC_INIT(res1);
  ck_assert_int_eq(s21_round(dec1, &res1), CONVERTATION_ERROR);
}
END_TEST

Suite *suite_s21_round(void) {
  Suite *suite = suite_create("=== ROUND     TEST ===");

  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_4);
  tcase_add_test(tc, s21_round_5);
  tcase_add_test(tc, s21_round_6);
  tcase_add_test(tc, s21_round_7);
  tcase_add_test(tc, s21_round_8);
  tcase_add_test(tc, s21_round_9);
  tcase_add_test(tc, s21_round_10);
  tcase_add_test(tc, s21_round_11);
  tcase_add_test(tc, s21_round_12);
  tcase_add_test(tc, s21_round_13);

  tcase_add_test(tc, s21_roundTest1);
  tcase_add_test(tc, s21_roundTest2);
  tcase_add_test(tc, s21_roundTest3);
  tcase_add_test(tc, s21_roundTest4);
  tcase_add_test(tc, s21_roundTest5);
  tcase_add_test(tc, s21_roundTest6);
  tcase_add_test(tc, s21_roundTest7);
  tcase_add_test(tc, s21_roundTest8);
  tcase_add_test(tc, s21_roundTest9);
  tcase_add_test(tc, s21_roundTest10);
  tcase_add_test(tc, s21_roundTest11);
  tcase_add_test(tc, s21_roundTest12);
  tcase_add_test(tc, s21_roundTest13);
  tcase_add_test(tc, s21_roundTest14);

  tcase_add_test(tc, s21_round_2_5);
  tcase_add_test(tc, s21_round_3_5);

  suite_add_tcase(suite, tc);

  return suite;
}