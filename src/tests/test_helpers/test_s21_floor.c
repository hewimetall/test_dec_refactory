#include "test_main.h"
#define DEC_NULL              \
  {                           \
    {0, 0, 0}, { .flags = 0 } \
  }
#define DEC_INIT(x) s21_decimal x = DEC_NULL

void floor_test_function(float n, float accuracy) {
  DEC_INIT(var1);
  DEC_INIT(var2);

  float value1 = 0, value2 = 0;
  s21_from_float_to_decimal(n, &var1);
  s21_floor(var1, &var2);
  s21_from_decimal_to_float(var2, &value2);
  value1 = floorf(n);
  ck_assert_float_eq_tol(value1, value2, accuracy);
}

START_TEST(s21_floor_1) {
  float n = 0.9;
  floor_test_function(n, 1);
}
END_TEST
START_TEST(s21_floor_2) {
  float n = 0.9999;
  floor_test_function(n, 1);
}
END_TEST

START_TEST(s21_floor_3) {
  float n = -8388608.123;
  floor_test_function(n, 10);
}
END_TEST

Suite *suite_s21_floor(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_floor");
  tc = tcase_create("case_floor");

  tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);

  suite_add_tcase(s, tc);
  return s;
}
