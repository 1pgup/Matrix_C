#ifndef S21_MATRIX_SUITES
#define S21_MATRIX_SUITES

#include <check.h>
#include <float.h>
#include <stdlib.h>
#include <time.h>

#include "../s21_matrix.h"

double get_rand(double min, double max);

Suite *suite_s21_create_matrix();
Suite *suite_s21_determinant();
Suite *suite_s21_calc_complements();
Suite *suite_s21_eq_matrix();
Suite *suite_s21_inverse_matrix();
Suite *suite_s21_mult_matrix();
Suite *suite_s21_transpose_matrix();
Suite *suite_s21_sum_matrix();
Suite *suite_s21_sub_matrix();
Suite *suite_s21_mult_number_matrix();

#endif /* S21_MATRIX_SUITES */