#ifdef TESTS_COMP
#include "test.h"
int main(void) {
  Suite *test_suites[] = {
      suite_s21_is_equal(),     suite_s21_is_greater_or_equal(),
      suite_s21_is_greater(),   suite_s21_is_less(),
      suite_s21_is_not_equal(), suite_s21_is_less_or_equal()};

  SRunner *sr = srunner_create(test_suites[0]);
  srunner_set_fork_status(sr, CK_NOFORK);
  int nf;

  for (size_t i = 1; i < 6; i++) srunner_add_suite(sr, test_suites[i]);
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

#endif