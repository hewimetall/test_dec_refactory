#include "core.h"

/*
  Data is good
  ALG
  1) get max exp
  2) update_exp
*/
int normolize(s21_decimal *v1, s21_decimal *v2) {
  int max = v1->head.exp > v2->head.exp;
  int err = ARITHMETIC_OK;
  if(max > 0){
    *v2 = binary_multiplication(*v2,s21_pow10(max), &err);
    v2->head.exp+=max;
  } else {
    *v1 = binary_multiplication(*v1,s21_pow10((-1)*max), &err); 
    v1->head.exp-=max;
  }
  return err;
}