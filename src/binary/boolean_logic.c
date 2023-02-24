#include "head.h"

s21_decimal bit_xor(s21_decimal a, s21_decimal b) {
  s21_decimal result = {0};
  result.data[0] = a.data[0] ^ b.data[0];
  result.data[1] = a.data[1] ^ b.data[1];
  result.data[2] = a.data[2] ^ b.data[2];
  return result;
}

s21_decimal bit_and(s21_decimal a, s21_decimal b) {
  s21_decimal result = {0};
  result.data[0] = a.data[0] & b.data[0];
  result.data[1] = a.data[1] & b.data[1];
  result.data[2] = a.data[2] & b.data[2];
  return result;
}

s21_decimal bit_or(s21_decimal a, s21_decimal b) {
  s21_decimal result = {0};
  result.data[0] = a.data[0] | b.data[0];
  result.data[1] = a.data[1] | b.data[1];
  result.data[2] = a.data[2] | b.data[2];
  return result;
}

s21_decimal bit_not(s21_decimal a) {
  s21_decimal result = {0};
  result.data[0] = ~a.data[0];
  result.data[1] = ~a.data[1];
  result.data[2] = ~a.data[2];
  return result;
}
