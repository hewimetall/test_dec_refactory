#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>
#include <limits.h>

#include "s21_decimal.h"

Suite* suite_binary_arith(void);
Suite* suite_binary_comp(void);
Suite* suite_binary_help(void);
Suite* suite_binary_norm(void);
Suite* suite_binary_other(void);
Suite* suite_binary_logic(void);

Suite* suite_s21_is_less(void);
Suite* suite_s21_is_less_or_equal(void);
Suite* suite_s21_is_greater(void);
Suite* suite_s21_is_greater_or_equal(void);
Suite* suite_s21_is_equal(void);
Suite* suite_s21_is_not_equal(void);

Suite *suite_s21_floor(void);
Suite *suite_s21_round(void);
Suite *suite_s21_truncate(void);
Suite *suite_s21_negate(void);
Suite *suite_s21_shift10(void);

Suite* suite_s21_from_int_to_decimal(void);
Suite* suite_s21_from_float_to_decimal(void);
Suite* suite_s21_from_decimal_to_int(void);
Suite* suite_s21_from_decimal_to_float(void);
Suite* float_suite(void);

Suite* suite_s21_add(void);
Suite* suite_s21_div(void);
Suite* suite_s21_mul(void);
Suite* suite_s21_sub(void);
Suite* suite_s21_mod(void);

#endif