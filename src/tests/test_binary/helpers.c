#include "test.h"

START_TEST(helper_set_unset) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);
  for (int i = 96; i > 0; i--) {
    ck_assert_int_eq(get_bit(decimal, i), get_bit(decimal_v, i));
  }

  for (int i = 96; i > 0; i--) {
    set_bit(&decimal, i, 1), set_bit_1(&decimal_v, i);
  }
  for (int i = 96; i > 0; i--) {
    ck_assert_int_eq(get_bit(decimal, i), get_bit(decimal_v, i));
  }
  for (int i = 96; i > 0; i--) {
    set_bit(&decimal, i, 0), set_bit_0(&decimal_v, i);
  }
  for (int i = 96; i > 0; i--) {
    ck_assert_int_eq(get_bit(decimal, i), get_bit(decimal_v, i));
  }
}
END_TEST

START_TEST(helper_opt) {
  DEC_INIT(decimal);
  DEC_INIT(decimal_v);

  for (int i = 96; i > 0; i--) {
    set_bit_0(&decimal, i);
  }
  zerro_data(&decimal_v);

  for (int i = 96; i > 0; i--) {
    ck_assert_int_eq(get_bit(decimal, i), get_bit(decimal_v, i));
  }
  decimal.head.flags = 12;
  clean_value(&decimal);
  ck_assert_int_eq(decimal.head.flags, 0);
}
END_TEST

Suite* suite_binary_help(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("=== HELP  TEST ===");
  tc_core = tcase_create("tc");

  tcase_add_test(tc_core, helper_set_unset);
  tcase_add_test(tc_core, helper_opt);
  suite_add_tcase(s, tc_core);

  return s;
}