#include "s21_matrix_suites.h"

START_TEST(transpose_matrix1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;

  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &a);
  s21_create_matrix(cols, rows, &b);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double val = get_rand(-1e5, 1e5);
      a.matrix[i][j] = val;
      b.matrix[j][i] = val;
    }
  }

  ck_assert_int_eq(s21_transpose(&a, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&b, &res), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;

  matrix_t a = {0};

  s21_create_matrix(rows, cols, &a);

  ck_assert_int_eq(s21_transpose(&a, NULL), INVALID_MATRIX_ERROR);

  s21_remove_matrix(&a);
}
END_TEST

Suite *suite_s21_transpose_matrix(void) {
  Suite *s = suite_create("transpose_matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_loop_test(tc, transpose_matrix1, 0, 50);
  tcase_add_loop_test(tc, transpose_matrix2, 0, 50);

  suite_add_tcase(s, tc);
  return s;
}
