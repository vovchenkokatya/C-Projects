//
// Created by Katya on 28.09.2026.
//
#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3

void print_matrix(int matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int swap_number(int matrix[N][M], int n, int m) {
    int change_done = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == n) {
                matrix[i][j] = m;
                change_done = 1;
            }
        }
    }
    return change_done;
}

void print_double_matrix(double matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[N][M] = {
        {1, 2, 3},
        {4, 5, 2},
        {7, 8, 9}
    };

    printf("Original matrix:\n");
    print_matrix(matrix);

    swap_number(matrix, 2, 99);

    printf("\nMatrix after swap:\n");
    print_matrix(matrix);

    return 0;
}
