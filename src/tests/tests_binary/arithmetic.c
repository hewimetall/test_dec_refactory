#include "test.h"

START_TEST(binary_addition_pos) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  DEC_INIT(res);
  int err = 0;

  decimal.data[0] = UINT_MAX;
  decimal_v.data[0] = 1;

  res = binary_addition(decimal, decimal_v, &err);
  ck_assert_int_eq(err, ARITHMETIC_OK);
  ck_assert_int_eq(res.data[1], 1);
}
END_TEST

START_TEST(binary_addition_neg) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  DEC_INIT(res);
  decimal.data[0] = UINT_MAX;
  decimal.data[1] = UINT_MAX;
  decimal.data[2] = UINT_MAX;

  decimal_v.data[0] = 1;
  int err = 0;
  res = binary_addition(decimal, decimal_v, &err);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(binary_subtraction_pos) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  DEC_INIT(res);
  int err = 0;

  decimal.data[0] = UINT_MAX;
  decimal.data[1] = UINT_MAX;
  decimal.data[2] = UINT_MAX;

  decimal_v.data[0] = UINT_MAX;
  decimal_v.data[1] = UINT_MAX;
  decimal_v.data[2] = UINT_MAX;

  res = binary_subtraction(decimal, decimal_v, &err);
  ck_assert_int_eq(res.data[0], 0);
  ck_assert_int_eq(err, ARITHMETIC_OK);
}
END_TEST

START_TEST(binary_subtraction_neg) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  DEC_INIT(res);
  decimal.data[0] = 0;
  decimal_v.data[0] = 1;
  int err = 0;
  res = binary_subtraction(decimal, decimal_v, &err);

  ck_assert_int_eq(res.data[0], UINT_MAX);
  ck_assert_int_eq(err, ARITHMETIC_OK);
}
END_TEST

START_TEST(binary_multiplication_pos) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  DEC_INIT(res);
  int err = 0;

  decimal.data[0] = 2;
  decimal_v.data[0] = 2;

  res = binary_multiplication(decimal, decimal_v, &err);
  ck_assert_int_eq(res.data[0], 4);
  ck_assert_int_eq(err, ARITHMETIC_OK);
  decimal.data[0] = UINT_MAX;
  decimal_v.data[0] = 2;

  res = binary_multiplication(decimal, decimal_v, &err);
  // UINT_MAX * 2
  union _to64 data = {.data64 = UINT_MAX};
  data.data64 *= 2;
  ck_assert_int_eq(res.data[0], data.data32[0]);
  ck_assert_int_eq(res.data[1], data.data32[1]);
  ck_assert_int_eq(err, ARITHMETIC_OK);
}
END_TEST

START_TEST(binary_multiplication_neg) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  DEC_INIT(res);
  int err = 0;

  decimal.data[0] = UINT_MAX;
  decimal.data[1] = UINT_MAX;
  decimal.data[2] = UINT_MAX;

  decimal_v.data[0] = 2;
  res = binary_multiplication(decimal, decimal_v, &err);
  ck_assert_int_eq(err, 1);
}
END_TEST

Suite* suite_binary_arith(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("arith");
  tc_core = tcase_create("binary");

  tcase_add_test(tc_core, binary_addition_pos);
  tcase_add_test(tc_core, binary_addition_neg);

  tcase_add_test(tc_core, binary_subtraction_pos);
  tcase_add_test(tc_core, binary_subtraction_neg);

  tcase_add_test(tc_core, binary_multiplication_pos);
  tcase_add_test(tc_core, binary_multiplication_neg);

  suite_add_tcase(s, tc_core);

  return s;
}