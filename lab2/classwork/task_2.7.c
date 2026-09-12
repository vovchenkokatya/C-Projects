//
// Created by Katya on 12.09.2026.
//
#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    printf("Enter cordinates: ");

    if (scanf("%lf %lf", &a, &b) == 2) {
        a = fabs(a);
        b = fabs(b);
        double area = M_PI * a * b;
        printf("Area is: %lf\n", area);
    } else {
        printf("Error.\n");
    }
    return 0;
}