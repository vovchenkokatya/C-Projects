#include <stdio.h>
#include <math.h>
//
// Created by Katya on 14.09.2026.
//
double calc_sqrt(unsigned n) {
    double y = 0;
    for (unsigned i = n; i >= 1; --i) {
        y = sqrt(3*i + y);
    }
    return y;
}

int main() {
    unsigned n;
    printf("Enter n: ");
    scanf("%u", &n);
    double result = calc_sqrt(n);
    printf("Result = %f\n", result);
}