#include "test.h"
#ifdef TESTS_CONV
int main(void) {
  Suite *test_suites[] = {
    suite_binary_arith(),
  };

  SRunner *sr = srunner_create(test_suites[0]);
  srunner_set_fork_status(sr, CK_NOFORK);
  int nf;

  for (size_t i = 1; i < ARRAY_SIZE_BINARY; i++) srunner_add_suite(sr, test_suites[i]);
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

#endif