#include "test.h"
#ifdef TESTS_CORE
int main(void) {
  Suite *test_suites[] = {suite_binary_arith(), suite_binary_comp(),
                          suite_binary_help(),  suite_binary_norm(),
                          suite_binary_other(), suite_binary_logic()};

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