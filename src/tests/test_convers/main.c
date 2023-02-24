#include "test.h"
#ifdef TESTS_CONV
int main(void) {
  Suite *test_suites[] = {suite_s21_from_int_to_decimal(),
                          suite_s21_from_decimal_to_float(),
                          suite_s21_from_decimal_to_int(),
                          suite_s21_from_float_to_decimal(), float_suite()};

  SRunner *sr = srunner_create(test_suites[0]);
  srunner_set_fork_status(sr, CK_NOFORK);
  int nf;

  for (size_t i = 1; i < 5; i++) srunner_add_suite(sr, test_suites[i]);
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

#endif