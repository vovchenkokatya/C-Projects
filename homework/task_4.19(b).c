//
// Created by Katya on 29.09.2026.
//
#include <stdio.h>

int main(){
    unsigned n;
    printf("Enter a value for n (n > 2): ");
    scanf("%u", &n);

    if (n <= 2) {
        printf("Error: n must be greater than 2.\n");
        return 1;
    }

    double p = 1.0;
    for (unsigned i = 2; i <= n; i++) {
        p *= (1.0 - 1.0 / (i * i));
    }

    printf("Result p = %lf\n", p);
    return 0;
}