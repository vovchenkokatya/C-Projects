//
// Created by Katya on 05.10.2026.
//
#include <stdio.h>

#define MAX 10

void printMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void transposeInPlace(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}

int main() {
    int matrix[MAX][MAX], transpose[MAX][MAX];
    int n = 3;

    int counter = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = counter++;
        }
    }

    printf("Початкова матриця:\n");
    printMatrix(matrix, n, n);

    transposeMatrix(matrix, transpose, n, n);
    printf("\nТранспонована матриця (transposeMatrix):\n");
    printMatrix(transpose, n, n);

    return 0;
}