//
// Created by Katya on 08.09.2026.
//
#include <stdio.h>

int main() {
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);
    int y = x * x;
    int res = y * x;
    res *= res;
    printf("Value: %d\n", res);
}