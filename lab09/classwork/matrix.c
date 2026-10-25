//
// Created by Katya on 25.10.2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void delete_matrix(MATRIX mat, int n) {
    if (mat == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

MATRIX create_matrix(int n) {
    MATRIX mat = (MATRIX)malloc(n * sizeof(double *));
    if (mat == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        mat[i] = (double *)calloc(n, sizeof(double));
        if (mat[i] == NULL) {
            delete_matrix(mat, i);
            return NULL;
        }
    }
    return mat;
}

MATRIX input_matrix(int n) {
    MATRIX mat = create_matrix(n);
    if (mat == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%lf", &mat[i][j]) != 1) {
                delete_matrix(mat, n);
                return NULL;
            }
        }
    }
    return mat;
}

MATRIX multiply_matrices(const MATRIX mat1, const MATRIX mat2, int n) {
    MATRIX result = create_matrix(n);
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

void print_matrix(const MATRIX mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", mat[i][j]);
        }
        printf("\n");
    }
}