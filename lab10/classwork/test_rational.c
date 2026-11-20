//
// Created by Katya on 12.10.2026.
//
#include <stdio.h>
#include "rational.h"

int test_rational(void) {
    Rational x, y;
    if (input(&x) != 0 || input(&y) != 0) {
        printf("Invalid fraction: enter an integer numerator and a positive denominator.\n");
        return 1;
    }

    Rational reduced_x = reduce(x);
    Rational reduced_y = reduce(y);
    printf("Reduced x: ");
    vyvod(reduced_x);
    printf("\nReduced y: ");
    vyvod(reduced_y);

    Rational sum = add(x, y);
    Rational product = mul(x, y);
    if (sum.denominator == 0 || product.denominator == 0) {
        printf("\nArithmetic result is too large for Rational.\n");
        return 1;
    }
    printf("\nSum: ");
    vyvod(sum);
    printf("\nProduct: ");
    vyvod(product);
    printf("\nComparison x vs y: %d\n", cmp(&x, &y));
    printf("Equal: %s\n", equal(&x, &y) ? "yes" : "no");
    return 0;
}

int main(void) {
    return test_rational();
}
