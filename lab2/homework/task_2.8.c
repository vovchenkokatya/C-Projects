//
// Created by Katya on 12.09.2026.
//
#include <stdio.h>
#include <math.h>

double calc_median(double a, double b, double c) {
    return 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
}
double calc_bisector(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return (2.0 * sqrt(b * c * p * (p - a))) / (b + c);
}
double calc_altitude(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    return (2.0 * S) / a;
}

int main(void) {
    double a, b, c;

    printf("Enter sides: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Error.\n");
        return 1;
    }
    if (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a)) {

        printf("\nM\n");
        printf("To a: %.2lf\n", calc_median(a, b, c));
        printf("To b: %.2lf\n", calc_median(b, a, c));
        printf("To c: %.2lf\n", calc_median(c, a, b));

        printf("\nB\n");
        printf("To a: %.2lf\n", calc_bisector(a, b, c));
        printf("To b: %.2lf\n", calc_bisector(b, a, c));
        printf("To c: %.2lf\n", calc_bisector(c, a, b));

        printf("\nH\n");
        printf("To a: %.2lf\n", calc_altitude(a, b, c));
        printf("To b: %.2lf\n", calc_altitude(b, a, c));
        printf("To c: %.2lf\n", calc_altitude(c, a, b));

    } else {
        printf("There is no triangle with these sides!\n");
    }
    return 0;
}