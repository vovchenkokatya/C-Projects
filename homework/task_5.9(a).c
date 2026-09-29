//
// Created by Katya on 29.09.2026.
//
#include <stdio.h>

int main() {
    unsigned n;
    printf("Enter a value for n: ");
    scanf("%u", &n);

    double v_minus_2 = 1.0;  
    double v_minus_1 = 0.3;
    double v_curr;

    if (n == 0) {
        printf("v_0 = %lf\n", v_minus_2);
        return 0;
    } else if (n == 1) {
        printf("v_1 = %lf\n", v_minus_1);
        return 0;
    }

    for (unsigned i = 2; i <= n; i++) {
        v_curr = (i + 2) * v_minus_2;
        v_minus_2 = v_minus_1;
        v_minus_1 = v_curr;
    }

    printf("v_%u = %lf\n", n, v_curr);
    return 0;
}