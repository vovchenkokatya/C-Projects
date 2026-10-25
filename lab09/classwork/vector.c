//
// Created by Katya on 25.10.2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void delete_vector(double *vect) {
    free(vect);
}

double *input_vector(int n) {
    double *vect = (double *)malloc(n * sizeof(double));
    if (vect == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &vect[i]) != 1) {
            delete_vector(vect);
            return NULL;
        }
    }
    return vect;
}

double *subtract_vectors(const double *vect1, const double *vect2, int n) {
    double *result = (double *)malloc(n * sizeof(double));
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        result[i] = vect1[i] - vect2[i];
    }
    return result;
}

void print_vector(const double *vect, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lf ", vect[i]);
    }
    printf("\n");
}