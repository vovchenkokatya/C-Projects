//
// Created by Katya on 28.09.2026.
//
#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3

void print_double_matrix(double matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void change_element_in_index(double matrix[N][M], int row, int col, double new_value) {
    if (row >= 0 && row < N && col >= 0 && col < M) {
        matrix[row][col] = new_value;
    } else {
        printf("Error: Index out of range\n");
    }
}

void task2() {
    double matrix[N][M] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    print_double_matrix(matrix);

    int i, j;
    double a;
    printf("Enter the row and column to change: ");
    scanf("%d %d", &i, &j);
    printf("Enter the new value: ");
    scanf("%lf", &a);

    change_element_in_index(matrix, i, j, a);
    print_double_matrix(matrix);
}

int main() {
    task2();
    return 0;
}
