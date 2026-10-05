#include <stdio.h>
#include <math.h>

#define MAX 100

double sum_subdiagonal(double array[MAX][MAX], int n, int m, int k) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - j == k) {
                sum += array[i][j];
            }
        }
    }
    return sum;
}

int main() {
    // test
    printf("Testing sum_subdiagonal function:\n");

    double test_matrix[MAX][MAX] = {
        {1., 2., 3.},
        {4., 5., 6.},
        {7., 8., 9.}
    };

    double test_sums[5] = {3., 8., 15., 12., 7.}; // Array to store test sums for k = -2..2

    for(int test_k = -2, i = 0; test_k <= 2; test_k++, i++) {
        double test_sum = sum_subdiagonal(test_matrix, 3, 3, test_k);
        if(fabs(test_sum - test_sums[i]) <= 1e-6) {
            printf("Test passed for k=%d\n", test_k);
        } else {
            printf("Test failed for k=%d\n", test_k);
        }
    }

    return 0;
}