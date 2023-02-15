#include "s21_decimal.h"

s21_decimal int64_to_decimal(s21_uint64 a) {
    s21_decimal b = DECIMAL_ZERO;
    union _to64 to = {.data64 = a};
    b.data[0] = to.data32[0];
    b.data[1] = to.data32[1];
    return b;
}