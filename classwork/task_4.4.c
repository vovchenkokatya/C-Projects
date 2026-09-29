//
// Created by Katya on 14.09.2026.
//
#include <stdio.h>

double exp_tailor(double x, unsigned n){
    double sum = 0;
    double term = x;
    for (unsigned i = 1; i < n; i++) {
        term *= x / i * (i + 1);
        sum += term;
    }
    return sum;
}

int main(){
    double x, y;
    unsigned n;
    printf("Enter a value for x: ");
    scanf("%lf", &x);
    printf("Enter a value for n: ");
    scanf("%u", &n);

    y=exp_tailor(x, n);
    printf("exp_tailor(%lf, %u) = %lf\n", x, n, y);
}