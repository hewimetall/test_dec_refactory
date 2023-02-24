#ifndef S21_STRUCTURES_H_
#define S21_STRUCTURES_H_

typedef unsigned int s21_uint;
typedef unsigned long long s21_uint64;
typedef long long s21_int64;
typedef unsigned short s21_bool;

union _to64 {
  /* data */
  s21_uint64 data64;
  s21_uint data32[2];
};

union __header {
  struct {
    s21_uint __ : 16;
    s21_uint exp : 8;
    s21_uint ___ : 7;
    s21_uint sign : 1;
  };
  s21_uint flags;
};

typedef struct s21_decimal {
  s21_uint data[3];
  union __header head;
} s21_decimal;

typedef enum arithmetic_result {
  ARITHMETIC_OK = 0,
  S21_INFINITY = 1,
  S21_NEGATIVE_INFINITY = 2,
  S21_ZERO_DIV = 3,
} arithmetic_result;

typedef enum arithmetic_consts { POSITIVE = 0, NEGATIVE = 1 } arithmetic_consts;

typedef enum comparison_result {
  FALSE = 0,
  TRUE = 1,
} comparison_result;

typedef enum {
  CONVERTATION_OK = 0,
  CONVERTATION_ERROR = 1
} convertation_result;

typedef enum { COUNT_OK = 0, COUNT_ERROR = 1 } count_result;

#endif  // S21_STRUCTURES_H_
