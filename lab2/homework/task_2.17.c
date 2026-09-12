//
// Created by Katya on 12.09.2026.
//
#include <stdio.h>
#include <math.h>

double my_arctg(double x) {
    return atan(x);
}
double my_arctg_derivative(double x) {
    return 1.0 / (1.0 + x * x);
}

int main(void) {
    double x;
    printf("Enter x: ");
    if (scanf("%lf", &x) == 1) {
        printf("f(x)  = arctg(%lf) = %lf\n", x, my_arctg(x));
        printf("f'(x) = %lf\n", my_arctg_derivative(x));
    } else {
        printf("Error input.\n");
    }
    return 0;
}