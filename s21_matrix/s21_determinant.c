#include "../s21_matrix.h"

int s21_determinant(matrix_t* A, double* result) {
  if (!A || !A->matrix || !result) return INVALID_MATRIX_ERROR;

  if (A->rows != A->columns) return CALC_ERROR;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
    return OK;
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    return OK;
  }

  int err = OK;
  int i, k, j, sign;
  double det = 0;

  matrix_t tmp = {0};

  err = s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
  for (k = 0; k < A->columns; k++) {
    for (i = 1; i < A->rows; i++) {
      for (j = 0; j < A->columns; j++) {
        if (j != k) {
          tmp.matrix[i - 1][j < k ? j : j - 1] = A->matrix[i][j];
        }
      }
    }

    if (k % 2 == 0)
      sign = 1;
    else
      sign = -1;

    err = s21_determinant(&tmp, result);

    if (err) {
      s21_remove_matrix(&tmp);
      break;
    } else {
      det += sign * A->matrix[0][k] * (*result);
    }
  }

  if (!err) {
    *result = det;
    s21_remove_matrix(&tmp);
  }

  return err;
}