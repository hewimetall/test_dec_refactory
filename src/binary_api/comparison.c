#include "core.h"
#include "struct.h"

/*
    Побитовое сравнения числа.
    В случае работает так 
    a > b == 1
    a == b == 0
    a > b == -1
*/
short compere(s21_decimal a, s21_decimal b) {
    short data = 0;
    for(int i = sizeof(a.data)*8; i>=0 && !data; --i)
        data = get_bit(a,i) - get_bit(b,i); 
    return data;
}

int eq_zero(s21_decimal value) {
    return (value.data[0] == 0 && value.data[1] == 0 && value.data[2] == 0);
}
int eq_max(s21_decimal value) {
    return (value.data[0] == __UINT32_MAX__ && value.data[1] == __UINT32_MAX__ && value.data[2] == __UINT32_MAX__);
}