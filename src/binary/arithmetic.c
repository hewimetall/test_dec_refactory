#include "head.h"

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
    Особые точки:
        MAX v1 v2;
 */

s21_decimal binary_addition(s21_decimal value_1, s21_decimal value_2,
                            int *err) {
  *err = ARITHMETIC_OK;
  DEC_INIT(carry);
  while (!eq_zero(value_2)) {
    zerro_data(&carry);
    carry = bit_and(value_1, value_2);
    *err = shiftl(&carry);
    value_1 = bit_xor(value_1, value_2);
    value_2 = carry;

    if (*err) {
      break;
    }
  }
  return value_1;
}

s21_decimal binary_subtraction(s21_decimal value_1, s21_decimal value_2,
                               int *err) {
  *err = ARITHMETIC_OK;
  DEC_INIT(carry);
  // optimaze fast
  if (eq_zero(value_2)) {
    carry = value_1;
  } else if (eq_val(value_2, DECIMAL_ONE)) {
    if (value_1.data[0])
      value_1.data[0]--;
    else if (value_1.data[1])
      value_1.data[1]--;
    else if (value_1.data[2])
      value_1.data[2]--;
    else
      value_1.data[0] = 1;
    carry = value_1;
  } else if (value_1.data[1] == 0 && value_1.data[2] == 0 &&
             value_2.data[1] == 0 && value_2.data[2] == 0)
    carry.data[0] = value_1.data[0] - value_2.data[0];
  else if (!eq_zero(value_2) && !eq_max(value_2)) {
    value_2 = binary_addition(bit_not(value_2), DECIMAL_ONE, err);
    if (eq_max(value_2)) {
      set_bit_0(&value_1, 0);
      carry = value_1;
    } else {
      carry = binary_addition(value_1, value_2, err);
    }
  } else if (eq_max(value_2) && !eq_max(value_1)) {
    // IF VAL - MAX = 0;
    *err = 1;
  }
  return carry;
}

s21_decimal binary_multiplication(s21_decimal value_1, s21_decimal value_2,
                                  int *err) {
  *err = ARITHMETIC_OK;
  DEC_INIT(result);
  while (!eq_zero(value_2) && !(*err)) {
    if (!eq_zero(bit_and(value_2, DECIMAL_ONE))) {
      result = binary_addition(result, value_1, err);
      if (*err) break;
    }
    *err = shiftl(&value_1);
    shiftr(&value_2);
  }
  return result;
}

/**
 * @brief: Возврящяет максимальный  близкий целое часное.
 * Работает как int / int
 */
s21_decimal binary_division(s21_decimal value_1, s21_decimal value_2, int *err,
                            s21_decimal *mod) {
  *err = ARITHMETIC_OK;
  DEC_INIT(Q);
  DEC_INIT(R);
  if (mod) clean_value(mod);

  if (eq_zero(value_2))
    *err = S21_ZERO_DIV;
  else if (eq_val(value_2, DECIMAL_ONE))
    Q = value_1;
  else if (value_1.data[1] == 0 && value_1.data[2] == 0 &&
           value_2.data[1] == 0 && value_2.data[2] == 0) {
    Q.data[0] = value_1.data[0] / value_2.data[0];
    R.data[0] = value_1.data[0] % value_2.data[0];
  } else {
    for (int i = 95; i >= 0; i--) {
      shiftl(&R);
      set_bit(&R, 0, get_bit(value_1, i));
      if (compare(R, value_2) >= 0) {
        R = binary_subtraction(R, value_2, err);

        set_bit_1(&Q, i);
      }
    }
  }
  if (mod != 0) {
    *mod = R;
  }
  return Q;
}
