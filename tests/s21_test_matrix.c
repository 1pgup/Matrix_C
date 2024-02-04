#include "s21_matrix_suites.h"

int main() {
  int number_failed = 0;
  SRunner *sr;

  sr = srunner_create(NULL);

  srunner_add_suite(sr, suite_s21_create_matrix());
  srunner_add_suite(sr, suite_s21_determinant());
  srunner_add_suite(sr, suite_s21_calc_complements());
  srunner_add_suite(sr, suite_s21_eq_matrix());

  srunner_add_suite(sr, suite_s21_inverse_matrix());
  srunner_add_suite(sr, suite_s21_mult_matrix());
  srunner_add_suite(sr, suite_s21_transpose_matrix());
  srunner_add_suite(sr, suite_s21_sum_matrix());
  srunner_add_suite(sr, suite_s21_sub_matrix());
  srunner_add_suite(sr, suite_s21_mult_number_matrix());

  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
