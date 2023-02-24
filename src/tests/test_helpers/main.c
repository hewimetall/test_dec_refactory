#include "test.h"
#ifdef TESTS_HELP
int main(void) {
  Suite *test_suites[] = {suite_s21_negate(), suite_s21_floor(),
                          suite_s21_truncate(), suite_s21_round()

  };

  SRunner *sr = srunner_create(test_suites[0]);
  srunner_set_fork_status(sr, CK_NOFORK);
  int nf;

  for (size_t i = 1; i < 4; i++) srunner_add_suite(sr, test_suites[i]);
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

#endif