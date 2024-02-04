#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  if (!A || !A->matrix || !result) return INVALID_MATRIX_ERROR;

  if (A->rows != A->columns) return CALC_ERROR;

  int err = OK;

  matrix_t tmp_compl = {0};
  matrix_t tmp_transp = {0};

  err = s21_calc_complements(A, &tmp_compl);

  err = s21_transpose(&tmp_compl, &tmp_transp);
  s21_remove_matrix(&tmp_compl);
  double det = 0;

  err = s21_determinant(A, &det);

  if (det)
    err = s21_mult_number(&tmp_transp, 1.0 / det, result);
  else
    err = CALC_ERROR;

  s21_remove_matrix(&tmp_transp);

  return err;
}