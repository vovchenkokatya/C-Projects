#include <stdio.h>
#include <stdbool.h>
#include "test_rational.c"

typedef struct {
    int numerator;
    unsigned denominator;
} Rational;

void vyvod(const Rational x) {
    printf("\nR= %d / %u ", x.numerator, x.denominator);
}

int input(Rational* x) {
    printf("Input numerator and denominator:");
    int r1 = scanf("%d", &x->numerator);
    int r2 = scanf("%u", &x->denominator);
    if (r1 != 1 || r2 != 1) return -1;
    return 0;
}

bool equal(const Rational* a, const Rational* b) {
    return a->numerator * b->denominator == b->numerator * a->denominator;
}

unsigned gcd(unsigned a, unsigned b) {
    if (a == 0 || b == 0) return a + b;
    if (a > b) return gcd(b, a % b);
    else return gcd(a, b % a);
}

Rational reduce(const Rational x) {
    unsigned d;
    if (x.numerator >= 0) d = gcd(x.numerator, x.denominator);
    else d = gcd(-x.numerator, x.denominator);
    
    Rational z;
    z.numerator = (int)x.numerator / (int)d;
    z.denominator = x.denominator / d;
    return z;
}

void reduce_inplace(Rational* x) {
    unsigned d = x->numerator >= 0 ? gcd(x->numerator, x->denominator) : gcd(-x->numerator, x->denominator);
    x->numerator /= (int)d;
    x->denominator /= d;
}

Rational add(const Rational a, const Rational b) {
    Rational c;
    c.numerator = (int)(a.numerator * b.denominator) + (int)(b.numerator * a.denominator);
    c.denominator = a.denominator * b.denominator;
    reduce_inplace(&c);
    return c;
}

Rational mul(const Rational a, const Rational b) {
    Rational c;
    c.numerator = a.numerator * b.numerator;
    c.denominator = a.denominator * b.denominator;
    reduce_inplace(&c);
    return c;
}

int cmp(const Rational* a, const Rational* b) {
    int left = a->numerator * b->denominator;
    int right = b->numerator * a->denominator;
    
    if (left < right) return -1;
    if (left > right) return 1;
    return 0;
}