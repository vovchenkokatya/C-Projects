//
// Created by Katya on 12.09.2026.
//
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double p, S;

    printf("Enter a: ");
    if (scanf("%lf", &a) != 1) return 1;

    printf("Enter b: ");
    if (scanf("%lf", &b) != 1) return 1;

    printf("Enter c: ");
    if (scanf("%lf", &c) != 1) return 1;

    if (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a)) {
        p = (a + b + c) / 2.0;
        S = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("S: %.2lf\n", S);
    } else {
        printf("Error!\n");
    }
    return 0;
}