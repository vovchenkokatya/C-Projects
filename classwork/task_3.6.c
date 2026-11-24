//
// Created by Katya on 20.09.2026.
//
#include <stdio.h>
#include <math.h>

void find_abs_min_max(double a, double b, double c) {
    double max_num = a;
    double min_num = a;

    if (fabs(b) > fabs(max_num)) {
        max_num = b;
    }
    if (fabs(c) > fabs(max_num)) {
        max_num = c;
    }

    if (fabs(b) < fabs(min_num)) {
        min_num = b;
    }
    if (fabs(c) < fabs(min_num)) {
        min_num = c;
    }

    printf("The biggest: %g (|%g| = %g)\n", max_num, max_num, fabs(max_num));
    printf("The smallest: %g (|%g| = %g)\n", min_num, min_num, fabs(min_num));
}

int main() {
    double a, b, c;
    printf("Enter three real numbers: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    find_abs_min_max(a, b, c);

    return 0;
}
