#include "s21_matrix_suites.h"

START_TEST(s21_calc_compl1) {
  matrix_t a = {0}, b = {0}, c = {0};

  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &c);

  a.matrix[0][0] = 1.0;
  a.matrix[0][1] = 2.0;
  a.matrix[0][2] = 3.0;
  a.matrix[1][0] = 0.0;
  a.matrix[1][1] = 4.0;
  a.matrix[1][2] = 2.0;
  a.matrix[2][0] = 5.0;
  a.matrix[2][1] = 2.0;
  a.matrix[2][2] = 1.0;

  s21_calc_complements(&a, &b);

  c.matrix[0][0] = 0.0;
  c.matrix[0][1] = 10.0;
  c.matrix[0][2] = -20.0;
  c.matrix[1][0] = 4.0;
  c.matrix[1][1] = -14.0;
  c.matrix[1][2] = 8.0;
  c.matrix[2][0] = -8.0;
  c.matrix[2][1] = -2.0;
  c.matrix[2][2] = 4.0;

  ck_assert_int_eq(s21_eq_matrix(&b, &c), SUCCESS);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
}
END_TEST

START_TEST(s21_calc_compl2) {
  matrix_t a = {0}, b = {0}, c = {0};

  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &c);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 2;
  a.matrix[2][0] = 5;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 1;

  s21_calc_complements(&a, &b);

  c.matrix[0][0] = 0;
  c.matrix[0][1] = 10;
  c.matrix[0][2] = -20;
  c.matrix[1][0] = 4;
  c.matrix[1][1] = -14;
  c.matrix[1][2] = 8;
  c.matrix[2][0] = -8;
  c.matrix[2][1] = -2;
  c.matrix[2][2] = 4;

  ck_assert_int_eq(s21_eq_matrix(&b, &c), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
}
END_TEST

START_TEST(s21_calc_compl3) {
  matrix_t a = {0}, b = {0};

  ck_assert_int_eq(s21_calc_complements(&a, &b), INVALID_MATRIX_ERROR);
}
END_TEST

START_TEST(s21_calc_compl4) {
  matrix_t a = {0}, b = {0};

  s21_create_matrix(1, 2, &a);

  ck_assert_int_eq(s21_calc_complements(&a, &b), CALC_ERROR);

  s21_remove_matrix(&a);
}
END_TEST

Suite *suite_s21_calc_complements(void) {
  Suite *s = suite_create("s21_calc_complements");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, s21_calc_compl1);
  tcase_add_test(tc, s21_calc_compl2);
  tcase_add_test(tc, s21_calc_compl3);
  tcase_add_test(tc, s21_calc_compl4);

  suite_add_tcase(s, tc);
  return s;
}