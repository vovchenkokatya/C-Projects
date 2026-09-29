//
// Created by Katya on 29.09.2026.
//
#include <stdio.h>
#include <math.h>

int main() {
    double x, eps;
    printf("Enter a value for x: ");
    scanf("%lf", &x);
    printf("Enter a value for eps (e > 0): ");
    scanf("%lf", &eps);

    double sum = 0.0;
    double term = 1.0;
    unsigned n = 1;

    while (fabs(term) >= eps) {
        sum += term;
        term *= x / n;
        n++;
    }

    printf("Result (Approximated e^%lf): %lf\n", x, sum);

    return 0;
}