#include "s21_matrix_suites.h"

START_TEST(eq_matr) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;

  matrix_t a = {0};
  matrix_t b = {0};

  s21_create_matrix(rows, cols, &a);
  s21_create_matrix(rows, cols, &b);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double val = get_rand(DBL_MIN, DBL_MAX);
      a.matrix[i][j] = val;
      b.matrix[i][j] = val;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&a, &b), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(not_eq_matr) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;

  matrix_t a = {0};
  matrix_t b = {0};

  s21_create_matrix(rows, cols, &a);
  s21_create_matrix(rows, cols, &b);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
      b.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&a, &b), FAILURE);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

Suite *suite_s21_eq_matrix(void) {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_loop_test(tc, eq_matr, 0, 50);
  tcase_add_test(tc, not_eq_matr);

  suite_add_tcase(s, tc);
  return s;
}