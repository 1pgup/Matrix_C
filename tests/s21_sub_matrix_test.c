#include "s21_matrix_suites.h"

START_TEST(sub_matrix1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;

  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &a);
  s21_create_matrix(rows, cols, &b);
  s21_create_matrix(rows, cols, &c);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      b.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      c.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_sub_matrix(&a, &b, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&c, &res), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
  s21_remove_matrix(&c);
}
END_TEST

START_TEST(sub_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;

  matrix_t a = {0};
  matrix_t res = {0};

  s21_create_matrix(rows, cols, &a);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }

  ck_assert_int_eq(s21_sub_matrix(&a, NULL, &res), INVALID_MATRIX_ERROR);

  s21_remove_matrix(&a);
}
END_TEST

Suite *suite_s21_sub_matrix(void) {
  Suite *s = suite_create("s21_sub_matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_loop_test(tc, sub_matrix1, 0, 50);
  tcase_add_test(tc, sub_matrix2);

  suite_add_tcase(s, tc);
  return s;
}