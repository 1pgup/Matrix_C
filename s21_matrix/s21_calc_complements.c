#include "../s21_matrix.h"

double s21_get_det_of_minor(matrix_t* A, int row, int col, int* err) {
  double det = 1;
  matrix_t tmp = {0};
  (*err) = s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);

  int row_index = 0;
  int col_index = 0;

  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;

    for (int j = 0; j < A->columns; j++) {
      if (j == col) continue;

      tmp.matrix[row_index][col_index] = A->matrix[i][j];
      col_index++;
    }

    col_index = 0;
    row_index++;
  }

  (*err) = s21_determinant(&tmp, &det);
  s21_remove_matrix(&tmp);

  return det;
}

int s21_calc_complements(matrix_t* A, matrix_t* result) {
  if (!A || !A->matrix || !result) return INVALID_MATRIX_ERROR;

  if (A->rows != A->columns) return CALC_ERROR;

  int err = s21_create_matrix(A->rows, A->columns, result);

  if (!err) {
    for (int i = 0; i < A->rows && !err; i++) {
      for (int j = 0; j < A->columns && !err; j++) {
        result->matrix[i][j] =
            s21_get_det_of_minor(A, i, j, &err) * pow(-1, i + j);
      }
    }
  }

  return err;
}