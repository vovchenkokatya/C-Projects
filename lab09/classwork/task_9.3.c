//
// Created by Katya on 25.10.2026.
//
#include <stdio.h>
#include "vector.h"

int main(void) {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    printf("Enter the first vector:\n");
    double *vect1 = input_vector(n);
    if (vect1 == NULL) {
        return 1;
    }

    printf("Enter the second vector:\n");
    double *vect2 = input_vector(n);
    if (vect2 == NULL) {
        delete_vector(vect1);
        return 1;
    }

    double *result = subtract_vectors(vect1, vect2, n);
    if (result == NULL) {
        delete_vector(vect1);
        delete_vector(vect2);
        return 1;
    }

    printf("Difference:\n");
    print_vector(result, n);

    delete_vector(vect1);
    delete_vector(vect2);
    delete_vector(result);
    return 0;
}