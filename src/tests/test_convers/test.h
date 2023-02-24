#ifndef S21_HELPER_H_
#define S21_HELPER_H_

#include <check.h>
#include <limits.h>

#include "binary/head.h"
#include "comparison/head.h"
#include "conversion/head.h"

/* Convertors and parsers */
Suite *suite_s21_from_int_to_decimal(void);
Suite *suite_s21_from_float_to_decimal(void);
Suite *suite_s21_from_decimal_to_int(void);
Suite *suite_s21_from_decimal_to_float(void);
Suite *float_suite(void);

#define ARRAY_SIZE_BINARY 1
#endif