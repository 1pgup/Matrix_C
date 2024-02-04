#include "s21_matrix_suites.h"

START_TEST(mult_matr1) {
  int rows = 2;
  int cols = 3;

  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &a);
  s21_create_matrix(cols, rows, &b);
  s21_create_matrix(a.rows, b.columns, &c);

  for (int i = 0, val = -1; i < rows; i++)
    for (int j = 0; j < cols; j++) a.matrix[i][j] = val++;

  for (int i = 0, val = 3; i < cols; i++)
    for (int j = 0; j < rows; j++) b.matrix[i][j] = val++;

  c.matrix[0][0] = 4;
  c.matrix[0][1] = 4;
  c.matrix[1][0] = 49;
  c.matrix[1][1] = 58;

  ck_assert_int_eq(s21_mult_matrix(&a, &b, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&c, &res), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);

  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matr2) {
  int rows = 2;
  int cols = 3;

  matrix_t a = {0};

  s21_create_matrix(rows, cols, &a);

  ck_assert_int_eq(s21_mult_matrix(&a, NULL, NULL), INVALID_MATRIX_ERROR);

  s21_remove_matrix(&a);
}
END_TEST

Suite *suite_s21_mult_matrix(void) {
  Suite *s = suite_create("s21_mult_matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, mult_matr1);
  tcase_add_test(tc, mult_matr2);

  suite_add_tcase(s, tc);
  return s;
}