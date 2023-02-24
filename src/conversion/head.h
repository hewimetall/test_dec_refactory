#ifndef S21_COMVER_H_
#define S21_COMVER_H_
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary/head.h"
#include "helpers/head.h"
#include "s21_decimal.h"
#include "s21_struct.h"
#define ROUND_POW 7
/* Convertors and parsers */
int s21_from_int_to_decimal(int src, s21_decimal *dst);  // Из int debug ++
int s21_from_float_to_decimal(float src,
                              s21_decimal *dst);         // Из float debug ++
int s21_from_decimal_to_int(s21_decimal src, int *dst);  // В int debug ++
int s21_from_decimal_to_float(s21_decimal src, float *dst);  // В float debug ++
#endif
