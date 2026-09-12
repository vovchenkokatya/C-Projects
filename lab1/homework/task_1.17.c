//
// Created by Katya on 08.09.2026.
//
#include <stdio.h>
#include <math.h>
int main() {
    double x;

    printf("Enter a real number: ");
    scanf("%lf", &x);

    printf("%25.4f\n", pow(x, 8));
}