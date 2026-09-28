//
// Created by Katya on 21.09.2026.
//
#include <stdio.h>

unsigned long long fibonacci(int n) {
    unsigned long long f0, f1, f;
    f0 = 1UL;
    f1 = 1UL;

    for (int k = 2; k <= n; k++) {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
    }
    return f;
}

int main() {
    int n;
    printf("Enter a number n: ");
    if (scanf("%d", &n) != 1) {
        printf("Wrong input.");
        return -1;
    }
    unsigned long long f = fibonacci(n);
    printf("F(%d) = %llu\n", n, f);
}