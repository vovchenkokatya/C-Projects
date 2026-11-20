#ifndef LAB10_RATIONAL_H
#define LAB10_RATIONAL_H

#include <stdbool.h>

typedef struct {
    int numerator;
    unsigned denominator;
} Rational;

void vyvod(Rational x);
int input(Rational* x);
bool equal(const Rational* a, const Rational* b);
unsigned gcd(unsigned a, unsigned b);
Rational reduce(Rational x);
void reduce_inplace(Rational* x);

// Arithmetic returns {0, 0} and sets errno on an invalid or overflowing result.
Rational add(Rational a, Rational b);
Rational mul(Rational a, Rational b);
// Returns -1, 0 or 1 for valid fractions; INT_MIN for a zero denominator.
int cmp(const Rational* a, const Rational* b);

#endif
