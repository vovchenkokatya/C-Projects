#pragma once
#include <iostream>

namespace lab18 {

class Rational
{
    int nom, den;
    static long long gcd_rational(long long a, long long b);
    void reduce(long long n, long long m);

public:
    Rational() : nom(1), den(1) {}
    Rational(int n, int m);
    void input();
    void output() const;
    double toDouble() const;
    void setNom(int n);
    void setDen(int m);

    Rational add(const Rational& x) const;
    Rational sub(const Rational& x) const;
    Rational mul(const Rational& x) const;
    Rational div(const Rational& x) const;
    Rational operator+(const Rational& x) const { return add(x); }
    Rational operator-(const Rational& x) const { return sub(x); }
    Rational operator*(const Rational& x) const { return mul(x); }
    Rational operator/(const Rational& x) const { return div(x); }

    bool operator==(const Rational& x) const;
    bool operator!=(const Rational& x) const { return !(*this == x); }
    bool operator<(const Rational& x) const;
    bool operator>(const Rational& x) const { return x < *this; }
    bool operator<=(const Rational& x) const { return !(x < *this); }
    bool operator>=(const Rational& x) const { return !(*this < x); }

    friend std::ostream& operator<<(std::ostream& out, const Rational& x);
    friend std::istream& operator>>(std::istream& in, Rational& x);
};

}
