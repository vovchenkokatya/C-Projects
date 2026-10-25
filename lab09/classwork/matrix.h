//
// Created by Katya on 25.10.2026.
//

#ifndef UNI_LABS_MATRIX_H
#define UNI_LABS_MATRIX_H

#endif //UNI_LABS_MATRIX_H
#ifndef MATRIX_H
#define MATRIX_H

typedef double **MATRIX;

MATRIX create_matrix(int n);
MATRIX input_matrix(int n);
MATRIX multiply_matrices(const MATRIX mat1, const MATRIX mat2, int n);
void print_matrix(const MATRIX mat, int n);
void delete_matrix(MATRIX mat, int n);

#endif