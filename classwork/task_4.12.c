//
// Created by Katya on 29.09.2026.
//
#include <stdio.h>

unsigned long long subfactorial(unsigned n) {
    unsigned long long result = 1; // !0 = 1
    for (unsigned i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            result = result * i + 1; // парний крок: додаємо 1
        } else {
            result = result * i - 1; // непарний крок: віднімаємо 1
        }
    }
    return result;
}

int main() {
    unsigned n;
    printf("Enter a value for n (n < 25): ");
    scanf("%u", &n);

    printf("!%u = %llu\n", n, subfactorial(n));
}