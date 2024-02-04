#include "s21_matrix_suites.h"

START_TEST(create_matrix1) {
  int rows = 1;
  int cols = 1;

  matrix_t m = {0};

  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix2) {
  int rows = 5;
  int cols = 2;

  matrix_t m = {0};

  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix3) {
  int rows = 15;
  int cols = 30;

  matrix_t m = {0};

  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix4) {
  int rows = -3;
  int cols = 10;

  matrix_t m = {0};

  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), INVALID_MATRIX_ERROR);
}
END_TEST

START_TEST(create_matrix5) {
  int rows = 10;
  int cols = -3;

  matrix_t m = {0};

  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), INVALID_MATRIX_ERROR);
}

START_TEST(create_matrix6) {
  int rows = 2;
  int cols = 2;

  ck_assert_int_eq(s21_create_matrix(rows, cols, NULL), INVALID_MATRIX_ERROR);
}

Suite *suite_s21_create_matrix(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_create_matrix");
  tc = tcase_create("Core");

  tcase_add_test(tc, create_matrix1);
  tcase_add_test(tc, create_matrix2);
  tcase_add_test(tc, create_matrix3);
  tcase_add_test(tc, create_matrix4);
  tcase_add_test(tc, create_matrix5);
  tcase_add_test(tc, create_matrix6);

  suite_add_tcase(s, tc);
  return s;
}