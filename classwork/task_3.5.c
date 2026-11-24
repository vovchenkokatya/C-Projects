//
// Created by Katya on 20.09.2026.
//
#include <stdio.h>

void find_min_max(double a, double b) {
    if (a > b) {
        printf("Bigger: %g\n", a);
        printf("smaller: %g\n", b);
    } else if (b > a) {
        printf("Bigger: %g\n", b);
        printf("smaller: %g\n", a);
    } else {
        printf("They are the same: %g\n", a);
    }
}

int main() {
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);

    find_min_max(a, b);

    return 0;
}