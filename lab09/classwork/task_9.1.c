//
// Created by Katya on 25.10.2026.
//
#include <stdio.h>
#include <stdlib.h>

double *input_array(int n) {
    double *arr = (double *)malloc(n * sizeof(double));

    if (arr == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);

        if (scanf("%lf", &arr[i]) != 1) {
            free(arr);
            return NULL;
        }
    }

    return arr;
}

double sum_squares(const double *arr, int n) {
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i] * arr[i];
    }

    return sum;
}

int main(void) {
    int n;

    printf("Enter the size of the array: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    double *arr = input_array(n);

    if (arr == NULL) {
        printf("Failed to create the array\n");
        return 1;
    }

    printf("The sum of squares is: %lf\n", sum_squares(arr, n));

    free(arr);

    return 0;
}
