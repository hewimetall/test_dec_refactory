#include "test.h"

START_TEST(s21_trun_1) {
  DEC_INIT(dec1);
  DEC_INIT(res1);
  DEC_INIT(result);
  dec1.data[0] = 123;
  dec1.head.exp = 1;
  result.data[0] = 123;
  ck_assert_int_eq(s21_truncate(dec1, &res1), COUNT_OK);

  ck_assert_int_eq(res1.data[0], res1.data[0]);
  ck_assert_int_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_trun_2) {
  DEC_INIT(dec1);
  DEC_INIT(res1);
  DEC_INIT(result);

  dec1.data[1] = 1;
  dec1.head.exp = 1;
  ck_assert_int_eq(s21_truncate(dec1, &res1), COUNT_OK);

  ck_assert_int_eq(res1.data[0], res1.data[0]);
  ck_assert_int_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_truncate_1) {
  DEC_INIT(dec1);
  DEC_INIT(res1);
  DEC_INIT(result);
  dec1.head.flags = 0x000A0000;
  dec1.data[2] = 0x0;
  dec1.data[1] = 0xFFFFFFFF;
  dec1.data[0] = 0xFFFFFFFF;  //  1844674407.3709551615

  result.head.flags = 0x0;
  result.data[2] = 0x0;
  result.data[1] = 0x0;
  result.data[0] = 0x6DF37F67;

  ck_assert_int_eq(s21_truncate(dec1, &res1), COUNT_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_truncate_2) {
  DEC_INIT(dec1);
  DEC_INIT(res1);
  DEC_INIT(result);
  dec1.head.flags = 0b10000000000011000000000000000000;
  dec1.data[2] = 0x0;
  dec1.data[1] = 0xFFFFFFFF;
  dec1.data[0] = 0xFFFFFFFF;

  result.head.flags = 0b10000000000000000000000000000000;
  result.data[2] = 0x0;
  result.data[1] = 0x0;
  result.data[0] = 0x1197998;

  ck_assert_int_eq(s21_truncate(dec1, &res1), COUNT_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_truncate_3) {
  DEC_INIT(dec1);
  DEC_INIT(res1);
  DEC_INIT(result);
  dec1.head.flags = 0x80000000;
  dec1.data[2] = 0x0;
  dec1.data[1] = 0xFFFFFFFF;
  dec1.data[0] = 0xFFFFFFFF;

  result.head.flags = 0x80000000;
  result.data[2] = 0x0;
  result.data[1] = 0xFFFFFFFF;
  result.data[0] = 0xFFFFFFFF;

  ck_assert_int_eq(s21_truncate(dec1, &res1), COUNT_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_truncate_4) {
  DEC_INIT(dec1);
  DEC_INIT(res1);
  DEC_INIT(result);
  dec1.data[0] = 0b00000000000000000000000001101101;
  dec1.data[1] = 0b00000000000011000110010101011011;
  dec1.data[2] = 0b00000000000000000011000000111001;
  dec1.head.flags = 0b00000000000011100000000000000000;

  result.data[0] = 0b10000111101111000001011000011110;
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b00000000000000000000000000000000;

  ck_assert_int_eq(s21_truncate(dec1, &res1), COUNT_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_truncate_5) {
  DEC_INIT(dec1);
  DEC_INIT(res1);
  DEC_INIT(result);
  dec1.data[0] = 0b11011110101001001000000010110110;
  dec1.data[1] = 0b01011111101001011101111110100000;
  dec1.data[2] = 0b00011111111010011010111101100000;
  dec1.head.flags = 0b00000000000010010000000000000000;

  result.data[0] = 0b00110100101011011100000100111110;
  result.data[1] = 0b10001001000100001000011110111001;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b00000000000000000000000000000000;

  ck_assert_int_eq(s21_truncate(dec1, &res1), COUNT_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_truncate_6) {
  DEC_INIT(dec1);
  DEC_INIT(res1);
  DEC_INIT(result);
  dec1.head.flags = 0x80090000;
  dec1.data[2] = 0;
  dec1.data[1] = 0xFFFFEA34;
  dec1.data[0] = 0xFF837E4F;

  ck_assert_int_eq(s21_truncate(dec1, &result), COUNT_OK);

  res1.head.flags = 0x80000000;
  res1.data[2] = 0;
  res1.data[1] = 0x4;
  res1.data[0] = 0x4B829C70;
  ck_assert_int_eq(res1.head.flags, result.head.flags);
  ck_assert_int_eq(res1.data[2], result.data[2]);
  ck_assert_int_eq(res1.data[1], result.data[1]);
  ck_assert_int_eq(res1.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_truncate_7) {
  DEC_INIT(dec1);
  DEC_INIT(result);
  DEC_INIT(result_origin);
  dec1.data[0] = 0b11010000101000110011000001101101;
  dec1.data[1] = 0b00011111100110100110101101011000;
  dec1.data[2] = 0;
  dec1.head.flags = 0b00000000000010010000000000000000;

  ck_assert_int_eq(s21_truncate(dec1, &result), COUNT_OK);

  result_origin.head.flags = 0;
  result_origin.data[2] = 0;
  result_origin.data[1] = 0;
  result_origin.data[0] = 0b10000111101111000001011000011110;
  ck_assert_int_eq(result_origin.head.flags, result.head.flags);
  ck_assert_int_eq(result_origin.data[2], result.data[2]);
  ck_assert_int_eq(result_origin.data[1], result.data[1]);
  ck_assert_int_eq(result_origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_truncate_8) {
  DEC_INIT(dec1);
  DEC_INIT(res1);
  DEC_INIT(result);
  dec1.data[0] = 0b01111000101001111011110011000110;
  dec1.data[1] = 0b10011111111111001111101010000100;
  dec1.data[2] = 0b00011111111010011010111101101101;
  dec1.head.flags = 0b00000000000111000000000000000000;

  result.data[0] = 0b00000000000000000000000000000000;
  result.data[1] = 0b00000000000000000000000000000000;
  result.data[2] = 0b00000000000000000000000000000000;
  result.head.flags = 0b00000000000000000000000000000000;

  ck_assert_int_eq(s21_truncate(dec1, &res1), COUNT_OK);
  ck_assert_float_eq(res1.data[0], result.data[0]);
  ck_assert_float_eq(res1.data[1], result.data[1]);
  ck_assert_float_eq(res1.data[2], result.data[2]);
  ck_assert_float_eq(res1.head.flags, result.head.flags);
}
END_TEST

START_TEST(s21_truncateTest1) {
  // 6766

  DEC_INIT(src1);
  DEC_INIT(origin);
  DEC_INIT(result);
  // src1 = 2;

  src1.data[0] = 0b00000000000000000000000000000010;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b00000000000000000000000000000000;

  ck_assert_int_eq(s21_truncate(src1, &result), COUNT_OK);

  origin.data[0] = 0b00000000000000000000000000000010;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_truncateTest2) {
  // 6787
  DEC_INIT(src1);
  DEC_INIT(origin);
  DEC_INIT(result);
  // src1 = 3.5;

  src1.data[0] = 0b00000000000000000000000000100011;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b00000000000000010000000000000000;

  ck_assert_int_eq(s21_truncate(src1, &result), COUNT_OK);

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

START_TEST(s21_truncateTest3) {
  // 6850
  DEC_INIT(src1);
  DEC_INIT(origin);
  DEC_INIT(result);
  // src1 = -9878798789;

  src1.data[0] = 0b01001100110100101000000111000101;
  src1.data[1] = 0b00000000000000000000000000000010;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b10000000000000000000000000000000;
  ck_assert_int_eq(s21_truncate(src1, &result), COUNT_OK);

  origin.data[0] = 0b01001100110100101000000111000101;
  origin.data[1] = 0b00000000000000000000000000000010;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_truncateTest4) {
  // 6871
  DEC_INIT(src1);
  DEC_INIT(origin);
  DEC_INIT(result);
  // src1 = -545454512454545.35265454545645;

  src1.data[0] = 0b10000010111000100101101011101101;
  src1.data[1] = 0b11111001111010000010010110101101;
  src1.data[2] = 0b10110000001111101111000010010100;
  src1.head.flags = 0b10000000000011100000000000000000;

  ck_assert_int_eq(s21_truncate(src1, &result), COUNT_OK);

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

START_TEST(s21_truncateTest5) {
  // 6892
  DEC_INIT(src1);
  DEC_INIT(origin);
  DEC_INIT(result);
  // src1 = -5.492654545456454545645464;

  src1.data[0] = 0b00000111100110110001111110011000;
  src1.data[1] = 0b01100110010010001001000110100011;
  src1.data[2] = 0b00000000000001001000101100011101;
  src1.head.flags = 0b10000000000110000000000000000000;

  ck_assert_int_eq(s21_truncate(src1, &result), COUNT_OK);

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

START_TEST(s21_truncateTest6) {
  // 6913
  DEC_INIT(src1);
  DEC_INIT(origin);
  DEC_INIT(result);
  // src1 = 7961327845421.879754123131254;

  src1.data[0] = 0b01001110111001000011100101110110;
  src1.data[1] = 0b01001011001101011010000111011001;
  src1.data[2] = 0b00011001101110010111010010111111;
  src1.head.flags = 0b00000000000011110000000000000000;
  ck_assert_int_eq(s21_truncate(src1, &result), COUNT_OK);

  origin.data[0] = 0b10100100000111100100000000101101;
  origin.data[1] = 0b00000000000000000000011100111101;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_truncateTest7) {
  // 6934
  DEC_INIT(src1);
  DEC_INIT(origin);
  DEC_INIT(result);
  // src1 = -12345677.187654345678987654346;

  src1.data[0] = 0b01111000100010101111010011001010;
  src1.data[1] = 0b01100010000010101110010010000111;
  src1.data[2] = 0b00100111111001000001101011010101;
  src1.head.flags = 0b10000000000101010000000000000000;

  ck_assert_int_eq(s21_truncate(src1, &result), COUNT_OK);

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

START_TEST(s21_truncateTest8) {
  // 6955
  DEC_INIT(src1);
  DEC_INIT(origin);
  DEC_INIT(result);
  // src1 = 2.5086531268974139743;

  src1.data[0] = 0b01100101111011101101100101011111;
  src1.data[1] = 0b01011100001001010100001101000110;
  src1.data[2] = 0b00000000000000000000000000000001;
  src1.head.flags = 0b00000000000100110000000000000000;
  ck_assert_int_eq(s21_truncate(src1, &result), COUNT_OK);

  origin.data[0] = 0b00000000000000000000000000000010;
  origin.data[1] = 0b00000000000000000000000000000000;
  origin.data[2] = 0b00000000000000000000000000000000;
  origin.head.flags = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.head.flags, result.head.flags);
  ck_assert_int_eq(origin.data[2], result.data[2]);
  ck_assert_int_eq(origin.data[1], result.data[1]);
  ck_assert_int_eq(origin.data[0], result.data[0]);
}
END_TEST

START_TEST(s21_truncateTest9) {
  // 6976
  DEC_INIT(src1);
  DEC_INIT(origin);
  DEC_INIT(result);
  // src1 = 1;

  src1.data[0] = 0b00000000000000000000000000000001;
  src1.data[1] = 0b00000000000000000000000000000000;
  src1.data[2] = 0b00000000000000000000000000000000;
  src1.head.flags = 0b00000000000000000000000000000000;

  ck_assert_int_eq(s21_truncate(src1, &result), COUNT_OK);

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

START_TEST(s21_truncateTest10) {
  s21_decimal value = {{UINT_MAX, UINT_MAX, UINT_MAX}, {{1, 1, 1, 1}}};
  DEC_INIT(result);

  int ret = s21_truncate(value, &result);

  ck_assert_int_eq(result.data[0], 0);
  ck_assert_int_eq(result.data[1], 0);
  ck_assert_int_eq(result.data[2], 0);
  ck_assert_int_eq(result.head.flags, 0);
  ck_assert_int_eq(ret, 1);
}
END_TEST

Suite *suite_s21_truncate(void) {
  Suite *suite = suite_create("=== TRUNCATE  TEST ===");

  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, s21_trun_1);
  tcase_add_test(tc, s21_trun_2);
  tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, s21_truncate_3);
  tcase_add_test(tc, s21_truncate_4);
  tcase_add_test(tc, s21_truncate_5);
  tcase_add_test(tc, s21_truncate_6);
  tcase_add_test(tc, s21_truncate_7);
  tcase_add_test(tc, s21_truncate_8);
  tcase_add_test(tc, s21_truncateTest1);
  tcase_add_test(tc, s21_truncateTest2);
  tcase_add_test(tc, s21_truncateTest3);
  tcase_add_test(tc, s21_truncateTest4);
  tcase_add_test(tc, s21_truncateTest5);
  tcase_add_test(tc, s21_truncateTest6);
  tcase_add_test(tc, s21_truncateTest7);
  tcase_add_test(tc, s21_truncateTest8);
  tcase_add_test(tc, s21_truncateTest9);
  tcase_add_test(tc, s21_truncateTest10);

  suite_add_tcase(suite, tc);

  return suite;
}