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
  decimal.data[0] = UINT_MAX;
  decimal.data[1] = UINT_MAX;
  decimal.data[2] = UINT_MAX;

  decimal_v.data[0] = 1;
  int err = 0;
  binary_addition(decimal, decimal_v, &err);
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

START_TEST(binary_subtraction_pos2) {
  DEC_INIT(a);
  DEC_INIT(b);
  DEC_INIT(c);
  DEC_INIT(res);
  int err = 0;
  a.data[0] = 123;

  b.data[0] = 100;

  c.data[0] = 23;

  res = binary_subtraction(a, b, &err);
  ck_assert_int_eq(err, ARITHMETIC_OK);
  ck_assert_int_eq(eq_val(res, c), 1);
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

  ck_assert_int_eq(res.data[0], 1);
  ck_assert_int_eq(err, ARITHMETIC_OK);
  decimal.data[0] = 10;
  decimal_v.data[0] = 10;
  err = 0;
  res = binary_subtraction(decimal, decimal_v, &err);

  ck_assert_int_eq(res.data[0], 0);
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
  int err = 0;

  decimal.data[0] = UINT_MAX;
  decimal.data[1] = UINT_MAX;
  decimal.data[2] = UINT_MAX;

  decimal_v.data[0] = 2;
  binary_multiplication(decimal, decimal_v, &err);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(binary_division_pos) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  DEC_INIT(res);
  DEC_INIT(mull);
  int err = 0;

  decimal.data[0] = 12;
  decimal_v.data[0] = 4;

  res = binary_division(decimal, decimal_v, &err, &mull);
  ck_assert_int_eq(res.data[0], 3);
  ck_assert_int_eq(err, ARITHMETIC_OK);

  err = 0;

  decimal.data[0] = UINT_MAX;
  decimal_v.data[0] = 2;

  res = binary_division(decimal, decimal_v, &err, (void*)0);
  ck_assert_int_eq(res.data[0], UINT_MAX / 2);
  ck_assert_int_eq(err, ARITHMETIC_OK);

  zerro_data(&decimal);
  zerro_data(&decimal_v);

  set_bit_1(&decimal, 44);
  set_bit_1(&decimal_v, 31);
  res = binary_division(decimal, decimal_v, &err, (void*)0);

  ck_assert_int_eq(res.data[0], 8192);

  ck_assert_int_eq(err, ARITHMETIC_OK);

  err = 0;

  decimal = s21_pow10(4);
  decimal_v = s21_pow10(2);

  res = binary_division(decimal, decimal_v, &err, (void*)0);
  ck_assert_int_eq(eq_val(decimal_v, res), TRUE);
  ck_assert_int_eq(err, ARITHMETIC_OK);
}
END_TEST

Suite* suite_binary_arith(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("\n === ARITH TEST ===");
  tc_core = tcase_create("tc");

  tcase_add_test(tc_core, binary_addition_pos);
  tcase_add_test(tc_core, binary_addition_neg);

  tcase_add_test(tc_core, binary_subtraction_pos);
  tcase_add_test(tc_core, binary_subtraction_neg);

  tcase_add_test(tc_core, binary_multiplication_pos);
  tcase_add_test(tc_core, binary_subtraction_pos2);
  tcase_add_test(tc_core, binary_multiplication_neg);

  tcase_add_test(tc_core, binary_division_pos);

  suite_add_tcase(s, tc_core);

  return s;
}