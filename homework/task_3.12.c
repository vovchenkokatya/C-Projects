//
// Created by Katya on 20.09.2026.
//
#include <stdio.h>

void check_triangle(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0 ||
        a + b <= c || a + c <= b || b + c <= a) {
        printf("Triangle with sides %g, %g, %g does NOT exist.\n", a, b, c);
        return;
        }

    printf("Triangle exists. ");

    double max_side = a;
    double side1 = b;
    double side2 = c;

    if (b > max_side) {
        max_side = b;
        side1 = a;
        side2 = c;
    }
    if (c > max_side) {
        max_side = c;
        side1 = a;
        side2 = b;
    }

    double max_sq = max_side * max_side;
    double sum_sq = side1 * side1 + side2 * side2;
    double eps = 1e-9;

    if (max_sq > sum_sq + eps) {
        printf("It is obtuse.\n");
    } else if (max_sq < sum_sq - eps) {
        printf("It is acute.\n");
    } else {
        printf("It is right.\n");
    }
}

int main() {
    double a, b, c;
    printf("Enter sides a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        return 1;
    }

    check_triangle(a, b, c);

    return 0;
}