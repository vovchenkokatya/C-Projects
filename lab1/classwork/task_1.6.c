//
// Created by Katya on 08.09.2026.
//
#include <stdio.h>
int main() {
    double C, F;
    printf("Enter C: ");
    scanf("%lf", &C);
    F = (9.0 * C) / 5.0 + 32.0;
    printf("F=%g\n", F);
}