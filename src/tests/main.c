#include "test_binary/test.h"
#include "test_comparison/test.h"
#include "test_convers/test.h"
#include "test_math/test.h"

int main(void)
{
  Suite *test_suites[] = {
      suite_binary_arith(), suite_binary_comp(),
      suite_binary_help(), suite_binary_norm(),
      suite_binary_other(), suite_binary_logic(),
      suite_s21_is_equal(), suite_s21_is_greater_or_equal(),
      suite_s21_is_greater(), suite_s21_is_less(),
      suite_s21_is_not_equal(), suite_s21_is_less_or_equal(),
      suite_s21_from_int_to_decimal(),
      suite_s21_from_decimal_to_float(),
      suite_s21_from_decimal_to_int(),
      suite_s21_from_float_to_decimal(), float_suite(),
      suite_s21_negate(), suite_s21_floor(),
      suite_s21_truncate(), suite_s21_round(),
      suite_s21_add(), suite_s21_mul(), suite_s21_sub(),
      suite_s21_mod(), suite_s21_div()
};
  SRunner *sr = srunner_create(test_suites[0]);
  srunner_set_fork_status(sr, CK_NOFORK);
  int nf;

  for (size_t i = 1; i < 1; i++)
    srunner_add_suite(sr, test_suites[i]);
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
