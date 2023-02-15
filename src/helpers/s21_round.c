#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
    int error = 0;
    if (s21_is_equal(*result,DECIMAL_ZERO)) {
        error = 1;
    } else {
        *result = value;
        int exp = 0;
        int sign = 0;
        exp = result->head.exp;
        sign = result->head.sign;
        if (exp > 0) {
            while (exp > 1) {
                shift_exp(1, result);
                exp--;
            }
            s21_decimal five;
            five = DECIMAL_ZERO;
            five.data[0] = 5;
            simple_add(result, five, &result);
            result->head.exp = exp;
            shift_exp(1, result);
        }
        if (sign) result->head.sign;
    }
    return error;
}