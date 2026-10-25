//
// Created by Katya on 25.10.2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "matrix_flat.h"

void delete_matrix(double *mat) {
    free(mat);
}

double *input_matrix(int n) {
    double *mat = (double *)calloc((size_t)n * n, sizeof(double));
    if (mat == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%lf", &mat[(size_t)i * n + j]) != 1) {
                delete_matrix(mat);
                return NULL;
            }
        }
    }
    return mat;
}

double *multiply_matrices(const double *mat1, const double *mat2, int n) {
    double *result = (double *)calloc((size_t)n * n, sizeof(double));
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[(size_t)i * n + j] +=
                    mat1[(size_t)i * n + k] * mat2[(size_t)k * n + j];
            }
        }
    }
    return result;
}

void print_matrix(const double *mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", mat[(size_t)i * n + j]);
        }
        printf("\n");
    }
}