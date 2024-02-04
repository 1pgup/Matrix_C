#include "s21_matrix_suites.h"

START_TEST(s21_inverse1) {
  matrix_t a = {0}, b = {0}, c = {0};

  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &c);

  a.matrix[0][0] = 2.0;
  a.matrix[0][1] = 5.0;
  a.matrix[0][2] = 7.0;
  a.matrix[1][0] = 6.0;
  a.matrix[1][1] = 3.0;
  a.matrix[1][2] = 4.0;
  a.matrix[2][0] = 5.0;
  a.matrix[2][1] = -2.0;
  a.matrix[2][2] = -3.0;

  s21_inverse_matrix(&a, &b);

  c.matrix[0][0] = 1.0;
  c.matrix[0][1] = -1.0;
  c.matrix[0][2] = 1.0;
  c.matrix[1][0] = -38.0;
  c.matrix[1][1] = 41.0;
  c.matrix[1][2] = -34.0;
  c.matrix[2][0] = 27.0;
  c.matrix[2][1] = -29.0;
  c.matrix[2][2] = 24.0;

  ck_assert_int_eq(s21_eq_matrix(&b, &c), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
}
END_TEST

START_TEST(s21_inverse2) {
  matrix_t a = {0}, b = {0}, c = {0};

  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &c);

  a.matrix[0][0] = 2.8;
  a.matrix[0][1] = 1.3;
  a.matrix[0][2] = 7.01;
  a.matrix[1][0] = -1.03;
  a.matrix[1][1] = -2.3;
  a.matrix[1][2] = 3.01;
  a.matrix[2][0] = 0;
  a.matrix[2][1] = -3;
  a.matrix[2][2] = 2;

  s21_inverse_matrix(&a, &b);

  c.matrix[0][0] = 44300.0 / 367429.0;
  c.matrix[0][1] = -236300.0 / 367429.0;
  c.matrix[0][2] = 200360.0 / 367429.0;
  c.matrix[1][0] = 20600.0 / 367429.0;
  c.matrix[1][1] = 56000.0 / 367429.0;
  c.matrix[1][2] = -156483.0 / 367429.0;
  c.matrix[2][0] = 30900.0 / 367429.0;
  c.matrix[2][1] = 84000.0 / 367429.0;
  c.matrix[2][2] = -51010.0 / 367429.0;

  ck_assert_int_eq(s21_eq_matrix(&b, &c), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
}
END_TEST

START_TEST(s21_inverse3) {
  matrix_t a = {0}, b = {0}, c = {0};

  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &c);

  a.matrix[0][0] = 2;
  a.matrix[0][1] = 5;
  a.matrix[0][2] = 7;
  a.matrix[1][0] = 6;
  a.matrix[1][1] = 3;
  a.matrix[1][2] = 4;
  a.matrix[2][0] = 5;
  a.matrix[2][1] = -2;
  a.matrix[2][2] = -3;

  s21_inverse_matrix(&a, &b);

  c.matrix[0][0] = 1;
  c.matrix[0][1] = -1;
  c.matrix[0][2] = 1;
  c.matrix[1][0] = -38;
  c.matrix[1][1] = 41;
  c.matrix[1][2] = -34;
  c.matrix[2][0] = 27;
  c.matrix[2][1] = -29;
  c.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&c, &b), SUCCESS);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
}
END_TEST

START_TEST(s21_inverse4) {
  matrix_t a = {0}, b = {0};

  s21_create_matrix(1, 1, &a);

  a.matrix[0][0] = 1431.12312331;

  ck_assert_int_eq(s21_inverse_matrix(&a, &b), OK);
  ck_assert_int_eq(b.matrix[0][0] == (1.0 / a.matrix[0][0]), 1);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_inverse5) {
  matrix_t a = {0}, b = {0};

  s21_create_matrix(1, 1, &a);

  ck_assert_int_eq(s21_inverse_matrix(&a, &b), CALC_ERROR);

  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_inverse6) {
  matrix_t a = {0}, b = {0};

  ck_assert_int_eq(s21_inverse_matrix(&a, &b), INVALID_MATRIX_ERROR);
}
END_TEST

START_TEST(s21_inverse7) {
  matrix_t a = {0}, b = {0};

  s21_create_matrix(1, 4, &a);

  ck_assert_int_eq(s21_inverse_matrix(&a, &b), CALC_ERROR);

  s21_remove_matrix(&a);
}
END_TEST

Suite *suite_s21_inverse_matrix(void) {
  Suite *s = suite_create("s21_inverse_matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, s21_inverse1);
  tcase_add_test(tc, s21_inverse2);
  tcase_add_test(tc, s21_inverse3);
  tcase_add_test(tc, s21_inverse4);
  tcase_add_test(tc, s21_inverse5);
  tcase_add_test(tc, s21_inverse6);
  tcase_add_test(tc, s21_inverse7);

  suite_add_tcase(s, tc);
  return s;
}