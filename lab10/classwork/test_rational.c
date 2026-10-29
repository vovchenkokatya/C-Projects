//
// Created by Katya on 12.10.2026.
//
#include <stdio.h>
#include "task_10.4.c"

int test_rational() {
    Rational x, y, z;
    input(&x);
    vyvod(x);
    input(&y);
    vyvod(y);

    z = add(x, y);
    printf("sum=");
    vyvod(z);

    Rational z1 = mul(x, y);
    printf("\nmultiplication:");
    vyvod(reduce(z1));
    printf("\n comparison sum vs mult z>z1==%d\n", cmp(&z, &z1));

    Rational mas[5];
    Rational res = { 0, 1 };

    for (int i = 0; i < 5; ++i) {
        printf("\ninput rational:");
        input(&mas[i]);
    }

    return 0;
}

int main() {
    test_rational();
    return 0;
}