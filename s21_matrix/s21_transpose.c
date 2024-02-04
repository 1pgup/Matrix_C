#include "../s21_matrix.h"

int s21_transpose(matrix_t* A, matrix_t* result) {
  if (!A || !A->matrix || !result) return INVALID_MATRIX_ERROR;

  int err = s21_create_matrix(A->columns, A->rows, result);

  if (!err) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }

  return err;
}