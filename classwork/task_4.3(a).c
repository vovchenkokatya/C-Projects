//
// Created by Katya on 14.09.2026.
//
#include <stdio.h>

double calc_pol_a(double x, unsigned n) {
    double sum = 1.0;
    double dod = 1.0;

    for (unsigned i = 1; i <= n; i++) {
        dod *= x;
        sum += dod;
    }
    return sum;
}

int main() {
    double x = 2.0;
    unsigned n = 3;
    double y = calc_pol_a(x, n);
    printf("y = %f\n", y);
}