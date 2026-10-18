//
// Created by Katya on 18.10.2026.
//

#include <stdio.h>

#define NMAX 20
#define MMAX 20

void input_matrix(int n, int m, double matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void print_matrix(int n, int m, double matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap_rows(int n, int m, double matrix[n][m]) {
    double min = matrix[0][0];
    double max = matrix[0][0];
    int min_i = 0;
    int max_i = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                min_i = i;
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                max_i = i;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        double temp = matrix[min_i][j];
        matrix[min_i][j] = matrix[max_i][j];
        matrix[max_i][j] = temp;
    }
}

int main(void) {
    int n, m;
    do {
        printf("enter the numbers n and m from 1 to 20: ");
        if (scanf("%d %d", &n, &m) != 2) {
            return 1;
        }
    } while (n < 1 || n > NMAX || m < 1 || m > MMAX);

    double matrix[n][m];
    printf("enter the N by M matrix:\n");
    input_matrix(n, m, matrix);

    printf("your matrix is:\n");
    print_matrix(n, m, matrix);

    swap_rows(n, m, matrix);
    printf("matrix with swapped rows:\n");
    print_matrix(n, m, matrix);

    return 0;
}
