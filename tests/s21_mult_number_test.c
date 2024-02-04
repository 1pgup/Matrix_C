#include "s21_matrix_suites.h"

START_TEST(mult_number_matrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;

  matrix_t a = {0};
  matrix_t b = {0};

  s21_create_matrix(rows, cols, &a);
  s21_create_matrix(rows, cols, &b);

  double num = get_rand(-10e5, 10e5);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      a.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      b.matrix[i][j] = a.matrix[i][j] * num;
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&a, num, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&b, &res), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_s21_mult_number_matrix(void) {
  Suite *s = suite_create("s21_mult_number_matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_loop_test(tc, mult_number_matrix, 0, 50);

  suite_add_tcase(s, tc);
  return s;
}