
#include "core.h"

/**
    1. Init
    1:  0110 1011
    2:  0001 1010
    C:  0000 0000
    2. BIT AND (посмотреть где случается переполнение)
    1:     0110 1011
    2:     0001 1010
    C:     0000 1010
    3. SHIFT L CARRY (сдвигаем, чтобы смочь прибавить переполненные единицы.
   Запомнили переполнение. Здесь может произойти оверфлоу, тк нам не хватит
   места) C:     0001 0100
    4. BIT XOR. (V1, V2) (кор реально прибавляет два числа, обнуляя
   переполнение) 
    1:     0110 1011 
    2:     0001 1010 New 
    C:     0111 0001
    5. Если Керри не ноль (если еще есть что прибавлять), то продолжаем цикл
 */

s21_decimal binary_addition(s21_decimal value_1, s21_decimal value_2, int *err) {
    *err = ARITHMETIC_OK;
    s21_decimal carry = {{0},{.flags=0}};

    while (!eq_zero(value_2)) {
        zerro_data(&carry);
        carry = bit_and(value_1, value_2);
        *err = shiftl(&carry);
        value_1 = bit_xor(value_1, value_2);

        value_2 = carry;

        if (*err)
            break;
    }

    return value_1;
}

s21_decimal binary_subtraction(s21_decimal value_1, s21_decimal value_2, int *err) {
    *err = ARITHMETIC_OK;
    value_1.data[3] = 0;
    value_2.data[3] = -1;
    s21_decimal carry = {0};
    if(!eq_zero(value_2)){
        value_2 = binary_addition(bit_not(value_2), s21_pow10(0), err);
    }
    return binary_addition(value_1,value_2, err);
}

s21_decimal binary_multiplication(s21_decimal value_1, s21_decimal value_2, int *err) {
    *err = ARITHMETIC_OK;
    s21_decimal result = {0};
    DEC_INIT(f);
    f.data[0]=1;
    while (!eq_zero(value_2) && !(*err)) {
        if (!eq_zero(bit_and(value_2, s21_pow10(0)))) {
            result = binary_addition(result, value_1, err);
            if (*err)
                break;
        }

        *err = shiftl(&value_1);
        shiftr(&value_2);
    }
    return result;
}