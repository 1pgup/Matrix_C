#include "s21_matrix_suites.h"

START_TEST(determinant1) {
  int size = 4;

  matrix_t a = {0};

  s21_create_matrix(size, size, &a);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) a.matrix[i][j] = 1;

  double res = 0;

  ck_assert_int_eq(s21_determinant(&a, &res), OK);
  ck_assert_double_eq_tol(res, 0, 1e-6);

  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant2) {
  int size = 2;

  matrix_t a = {0};

  s21_create_matrix(size, size, &a);

  a.matrix[0][0] = -5;
  a.matrix[0][1] = -4;
  a.matrix[1][0] = -2;
  a.matrix[1][1] = -3;

  double res = 0;

  ck_assert_int_eq(s21_determinant(&a, &res), OK);
  ck_assert_double_eq_tol(res, 7, 1e-6);

  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant3) {
  int size = 3;

  matrix_t a = {0};

  s21_create_matrix(size, size, &a);

  a.matrix[0][0] = 2;
  a.matrix[0][1] = 3;
  a.matrix[0][2] = 1;
  a.matrix[1][0] = 7;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 1;
  a.matrix[2][0] = 9;
  a.matrix[2][1] = -2;
  a.matrix[2][2] = 1;

  double res = 0;

  ck_assert_int_eq(s21_determinant(&a, &res), OK);
  ck_assert_double_eq_tol(res, -32, 1e-6);

  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant4) {
  int size = 5;

  matrix_t a = {0};

  s21_create_matrix(size, size, &a);

  a.matrix[0][1] = 6;
  a.matrix[0][2] = -2;
  a.matrix[0][3] = -1;
  a.matrix[0][4] = 5;
  a.matrix[1][3] = -9;
  a.matrix[1][4] = -7;
  a.matrix[2][1] = 15;
  a.matrix[2][2] = 35;
  a.matrix[3][1] = -1;
  a.matrix[3][2] = -11;
  a.matrix[3][3] = -2;
  a.matrix[3][4] = 1;
  a.matrix[4][0] = -2;
  a.matrix[4][1] = -2;
  a.matrix[4][2] = 3;
  a.matrix[4][4] = -2;

  double res = 0;

  ck_assert_int_eq(s21_determinant(&a, &res), OK);
  ck_assert_double_eq_tol(res, 2480, 1e-6);

  s21_remove_matrix(&a);
}
END_TEST

Suite *suite_s21_determinant(void) {
  Suite *s = suite_create("s21_determinant");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, determinant1);
  tcase_add_test(tc, determinant2);
  tcase_add_test(tc, determinant3);
  tcase_add_test(tc, determinant4);

  suite_add_tcase(s, tc);
  return s;
}