#ifdef TESTS_MATH
#include "test.h"

int main(void) {
  Suite *test_suites[] = {suite_s21_add(), suite_s21_mul(), suite_s21_sub(),
                          suite_s21_mod(), suite_s21_div()};

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