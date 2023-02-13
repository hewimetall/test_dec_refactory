// #include "test.h"

// START_TEST(compere_pos) {
//   DEC_INIT(decimal);
//   DEC_INIT(decimal_v);
//   short res = 0;

//   decimal.data[0] = UINT_MAX;
//   decimal_v.data[0] = 1;

//   res = binary_addition(decimal, decimal_v, &err);
//   ck_assert_int_eq(err, ARITHMETIC_OK);
//   ck_assert_int_eq(res, 1);
  
// }
// END_TEST

// START_TEST(compere_neg) {
//   DEC_INIT(decimal);
//   DEC_INIT(decimal_v);
//   DEC_INIT(res);
//   int err = 0;

//   decimal.data[0] = UINT_MAX;
//   decimal_v.data[0] = 1;

//   res = binary_addition(decimal, decimal_v, &err);
//   ck_assert_int_eq(err, ARITHMETIC_OK);
//   ck_assert_int_eq(res.data[1], 1);
// }
// END_TEST

// // Suite* suite_binary_comp(void) {
// //   Suite* s;
// //   TCase* tc_core;

// //   s = suite_create("comp");
// //   tc_core = tcase_create("binary");

// //   tcase_add_test(tc_core, compere_pos);
// // //   tcase_add_test(tc_core, compere_neg);

// //   suite_add_tcase(s, tc_core);

// //   return s;
// // }