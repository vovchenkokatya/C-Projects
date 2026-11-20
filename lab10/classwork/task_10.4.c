#include "rational.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>

static unsigned long long magnitude(int n) {
    return n < 0 ? (unsigned long long)(-(long long)n) : (unsigned long long)n;
}

static unsigned long long gcd_wide(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

// Use magnitudes to avoid signed overflow before reducing the result.
static Rational make_rational(unsigned long long n, bool negative, unsigned long long d) {
    if (d == 0) {
        errno = EDOM;
        return (Rational){0, 0};
    }
    unsigned long long divisor = gcd_wide(n, d);
    n /= divisor;
    d /= divisor;
    unsigned long long limit = (unsigned long long)INT_MAX + (negative ? 1u : 0u);
    if (n > limit || d > UINT_MAX) {
        errno = ERANGE;
        return (Rational){0, 0};
    }
    int numerator;
    if (negative && n == (unsigned long long)INT_MAX + 1)
        numerator = INT_MIN;
    else
        numerator = negative ? -(int)n : (int)n;
    return (Rational){numerator, (unsigned)d};
}

void vyvod(Rational x) {
    printf("%d / %u", x.numerator, x.denominator);
}

int input(Rational* x) {
    long long numerator, denominator;
    printf("Input numerator and denominator: ");
    if (scanf("%lld%lld", &numerator, &denominator) != 2
        || numerator < INT_MIN || numerator > INT_MAX
        || denominator <= 0 || (unsigned long long)denominator > UINT_MAX)
        return -1;
    *x = (Rational){(int)numerator, (unsigned)denominator};
    return 0;
}

bool equal(const Rational* a, const Rational* b) {
    return a->denominator != 0 && b->denominator != 0 && cmp(a, b) == 0;
}

unsigned gcd(unsigned a, unsigned b) {
    return (unsigned)gcd_wide(a, b);
}

Rational reduce(Rational x) {
    return make_rational(magnitude(x.numerator), x.numerator < 0, x.denominator);
}

void reduce_inplace(Rational* x) {
    *x = reduce(*x);
}

Rational add(Rational a, Rational b) {
    if (a.denominator == 0 || b.denominator == 0) {
        errno = EDOM;
        return (Rational){0, 0};
    }
    unsigned long long left = magnitude(a.numerator) * b.denominator;
    unsigned long long right = magnitude(b.numerator) * a.denominator;
    unsigned long long numerator;
    bool negative;
    if ((a.numerator < 0) == (b.numerator < 0)) {
        numerator = left + right;
        negative = a.numerator < 0;
    } else if (left >= right) {
        numerator = left - right;
        negative = a.numerator < 0;
    } else {
        numerator = right - left;
        negative = b.numerator < 0;
    }
    return make_rational(numerator, negative,
                         (unsigned long long)a.denominator * b.denominator);
}

Rational mul(Rational a, Rational b) {
    return make_rational(magnitude(a.numerator) * magnitude(b.numerator),
                         (a.numerator < 0) != (b.numerator < 0),
                         (unsigned long long)a.denominator * b.denominator);
}

int cmp(const Rational* a, const Rational* b) {
    if (a->denominator == 0 || b->denominator == 0) {
        errno = EDOM;
        return INT_MIN;
    }
    long long left = (long long)a->numerator * b->denominator;
    long long right = (long long)b->numerator * a->denominator;
    return (left > right) - (left < right);
}
