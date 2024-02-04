#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  if (rows <= 0 || columns <= 0 || !result) return INVALID_MATRIX_ERROR;

  int err = OK;

  result->rows = rows;
  result->columns = columns;

  result->matrix = malloc(sizeof(double*) * rows);
  if (result->matrix)
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = malloc(sizeof(double) * columns);
    }
  else
    err = CALC_ERROR;

  if (!err) {
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++) result->matrix[i][j] = 0;
  }

  return err;
}