#include "test.h"

// два положительных числа, первое больше второго
START_TEST(basic_sub) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);
  DEC_INIT(true_ans);

  // 532167 - 123456 = 408711;
  dec1.data[0] = 532167;

  dec2.data[0] = 123456;

  true_ans.data[0] = 408711;

  int status = s21_sub(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

// два положительных числа, второе больше первого
START_TEST(basic_sub_2) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);
  dec1.data[0] = 123456;
  dec2.data[0] = 532167;
  // 123456 - 532167 = -408711;

  DEC_INIT(true_ans);
  true_ans.data[0] = 408711;
  true_ans.head.sign = 1;

  int status = s21_sub(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, eq_val(ans, true_ans));
  ck_assert_int_eq(ans.head.flags, true_ans.head.flags);
  ck_assert_int_eq(status, true_status);
}
END_TEST

// два отрицательных числа, первое по модулю больше второго
START_TEST(basic_sub_3) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);
  DEC_INIT(true_ans);

  // -532167 - (-123456) = -408711;
  //  -123456 - -532167 = -408711;
  // 123456 - 532167  = -408711
  dec1.data[0] = 532167;
  dec1.head.sign = 1;

  dec2.data[0] = 123456;
  dec2.head.sign = 1;

  true_ans.data[0] = 408711;
  true_ans.head.sign = 1;
  int status = s21_sub(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, eq_val(ans, true_ans));
  ck_assert_int_eq(ans.head.flags, true_ans.head.flags);
  ck_assert_int_eq(status, true_status);
}
END_TEST

// два отрицательных числа, второе по модулю больше первого
START_TEST(basic_sub_4) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);
  DEC_INIT(true_ans);

  // -61287 - (-234787) = 173500
  dec1.data[0] = 61287;
  dec1.head.sign = 1;

  dec2.data[0] = 234787;
  dec2.head.sign = 1;

  true_ans.data[0] = 173500;

  int status = s21_sub(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, eq_val(ans, true_ans));
  ck_assert_int_eq(ans.head.flags, true_ans.head.flags);
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(sub_with_dot) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);

  // 532.167 - 0.000000000001236 = 532.166999999998764 =
  // 111 01100010 10100011 00010001 00100100 00101111 01101011 00101100

  dec1.data[0] = 532167;
  dec1.head.flags = 196608;  // 3 знака после запятой

  dec2.data[0] = 1236;
  dec2.head.flags = 983040;  // 15 знаков после запятой

  DEC_INIT(true_ans);
  true_ans.data[0] = 607087404;
  true_ans.data[1] = 123904785;
  true_ans.head.flags = 983040;  // 18 знаков после запятой
  int status = s21_sub(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(sub_with_dot_2) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);

  dec1.data[0] = 532167;
  dec1.head.flags = 196608;  // 3 знака после запятой

  dec2.data[0] = 0;
  dec2.head.flags = 0;  // 15 знаков после запятой

  DEC_INIT(true_ans);
  true_ans.data[0] = 532167;
  true_ans.head.flags = 196608;

  int status = s21_sub(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

// если знаки у чисел не совпадают, вычитание признается сложением
START_TEST(return_to_add) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);
  // -2361234 - 48695 = -2361234 + (-48695) = 2409929
  dec1.data[0] = 2361234;
  dec1.head.flags = MINUS_SIGN;

  dec2.data[0] = 48695;

  DEC_INIT(true_ans);
  true_ans.data[0] = 2409929;
  true_ans.head.sign = 1;

  int status = s21_sub(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(return_to_add_2) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);
  // 6347852 - (-723184) = 6347852 + 723184 = 7071036
  dec1.data[0] = 6347852;

  dec2.data[0] = 723184;
  dec2.head.flags = MINUS_SIGN;

  DEC_INIT(true_ans);
  true_ans.data[0] = 7071036;

  int status = s21_sub(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_sub) {
  DEC_INIT(dec1);
  DEC_INIT(dec2);
  DEC_INIT(ans);

  // пример из README
  dec1.data[0] = 4294967295;
  dec1.data[1] = 4294967295;
  dec1.data[2] = 4294967295;

  dec2.data[0] = 1;
  dec2.data[1] = 0;
  dec2.data[2] = 0;

  DEC_INIT(true_ans);
  true_ans.data[0] = 4294967294;
  true_ans.data[1] = 4294967295;
  true_ans.data[2] = 4294967295;
  int status = s21_sub(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, eq_val(ans, true_ans));
  ck_assert_int_eq(ans.head.flags, true_ans.head.flags);
  ck_assert_int_eq(status, true_status);
}
END_TEST

Suite *suite_s21_sub(void) {
  Suite *suite = suite_create("===S21 SUB TEST===");
  TCase *tc_insert = tcase_create("tc");

  tcase_add_test(tc_insert, basic_sub);
  tcase_add_test(tc_insert, basic_sub_2);
  tcase_add_test(tc_insert, basic_sub_3);
  tcase_add_test(tc_insert, basic_sub_4);
  tcase_add_test(tc_insert, sub_with_dot);
  tcase_add_test(tc_insert, sub_with_dot_2);
  tcase_add_test(tc_insert, return_to_add);
  tcase_add_test(tc_insert, return_to_add_2);
  tcase_add_test(tc_insert, big_values_sub);
  suite_add_tcase(suite, tc_insert);

  return suite;
}
