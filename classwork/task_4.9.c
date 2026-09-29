//
// Created by Katya on 14.09.2026.
//
#include <stdio.h>
#include <math.h>

int main(){
    unsigned long long n, power_r=1;
    printf("Enter a value for n: ");
    scanf("%llu", &n);
    int r = 0;

    while (power_r <= n) {
        power_r *= 2; // power_r = 2^r
        r++;
        printf("power_r = %llu, r = %d\n", power_r, r);
    }

    printf("2^%d > %llu\n", r, n);
    printf("Result: %llu\n", power_r);
}