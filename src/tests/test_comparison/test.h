#ifndef TEST_COMP
#define TEST_COMP
#include <check.h>
#include <limits.h>

#include "binary/head.h"
#include "comparison/head.h"

Suite *suite_s21_is_less(void);
Suite *suite_s21_is_less_or_equal(void);
Suite *suite_s21_is_greater(void);
Suite *suite_s21_is_greater_or_equal(void);
Suite *suite_s21_is_equal(void);
Suite *suite_s21_is_not_equal(void);

#define ARRAY_SIZE_BINARY 1
#endif