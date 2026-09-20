//
// Created by Katya on 20.09.2026.
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

static bool is_zero_sinc(double x) {
    return fabs(x) < 1e-9;
}

double sinc(double x) {
    if (is_zero_sinc(x)) {
        return 1.0;
    }
    return sin(x) / x;
}

double sinc_derivative(double x) {
    if (is_zero_sinc(x)) {
        return 0.0;
    }
    return (x * cos(x) - sin(x)) / (x * x);
}

int test_sinc(void) {
    if (!is_zero_sinc(sinc(0.0) - 1.0)) {
        printf("Test sinc(0) failed\n");
        return 1;
    }
    if (!is_zero_sinc(sinc_derivative(0.0) - 0.0)) {
        printf("Test sinc_derivative(0) failed\n");
        return 1;
    }

    double half_pi = 3.14159265358979323846 / 2.0;
    double expected_val = 1.0 / half_pi;
    double expected_deriv = -1.0 / (half_pi * half_pi);

    if (!is_zero_sinc(sinc(half_pi) - expected_val)) {
        printf("Test sinc(pi/2) failed\n");
        return 1;
    }
    if (!is_zero_sinc(sinc_derivative(half_pi) - expected_deriv)) {
        printf("Test sinc_derivative(pi/2) failed\n");
        return 1;
    }

    return 0;
}