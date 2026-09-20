//
// Created by Katya on 14.09.2026.
//
#include <stdio.h>
#include <float.h>
int main() {
    double a = DBL_MAX;
    printf("The maximum value of double is: %e\n", a);

    do {
        a /= 2.0;
        printf("Current value of a: %e\n", a);
    } while (1 != 1 + a);
    printf("The smallest value of a such that a != 1 + a is: %e\n", a);
    printf("Real machine zero is %e\n", DBL_EPSILON);
}