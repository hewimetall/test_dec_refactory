#ifndef S21_HELPER_H_
#define S21_HELPER_H_
#include <check.h>
#include <limits.h>

#include "binary/head.h"
#include "conversion/head.h"
#include "helpers/head.h"

Suite *suite_s21_floor(void);
Suite *suite_s21_round(void);
Suite *suite_s21_truncate(void);
Suite *suite_s21_negate(void);
Suite *suite_s21_shift10(void);

#define ARRAY_SIZE_BINARY 1
#endif
