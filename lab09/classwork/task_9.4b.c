//
// Created by Katya on 25.10.2026.
//
#include <stdio.h>
#include "matrix_flat.h"

int main(void) {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    printf("Enter the first matrix:\n");
    double *mat1 = input_matrix(n);
    if (mat1 == NULL) {
        return 1;
    }

    printf("Enter the second matrix:\n");
    double *mat2 = input_matrix(n);
    if (mat2 == NULL) {
        delete_matrix(mat1);
        return 1;
    }

    double *result = multiply_matrices(mat1, mat2, n);
    if (result == NULL) {
        delete_matrix(mat1);
        delete_matrix(mat2);
        return 1;
    }

    printf("Product:\n");
    print_matrix(result, n);

    delete_matrix(mat1);
    delete_matrix(mat2);
    delete_matrix(result);
    return 0;
}


