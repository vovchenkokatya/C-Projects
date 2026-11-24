//
// Created by Katya on 20.09.2026.
//
#include <stdio.h>

void solve_product_a(int a, int b, int c) {
    int product = a * b * c;
    printf("Product (int): %d\n", product);
}

void solve_product_b(long long a, long long b, long long c) {
    long long product = a * b * c;
    printf("Product (long long): %lld\n", product);
}

int main() {
    long long a, b, c;

    printf("Enter three integers separated by commas: ");
    scanf("%lld,%lld,%lld", &a, &b, &c);

    solve_product_a((int)a, (int)b, (int)c);

    solve_product_b(a, b, c);
    return 0;
}