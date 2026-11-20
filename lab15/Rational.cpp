#include "Rational.h"
#include <limits>
#include <stdexcept>

using namespace std;

long long Rational::gcd_rational(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void Rational::reduce(long long n, long long m) {
    if (m == 0)
        throw invalid_argument("Denominator cannot be zero.");
    long long d = gcd_rational(n, m);
    n /= d;
    m /= d;
    if (m < 0) {
        n = -n;
        m = -m;
    }
    if (n < numeric_limits<int>::min() || n > numeric_limits<int>::max()
        || m > numeric_limits<int>::max())
        throw overflow_error("Rational number is too large.");
    nom = static_cast<int>(n);
    den = static_cast<int>(m);
}

Rational::Rational(int n, int m) { reduce(n, m); }
void Rational::input() {
    cout << "Input numerator and denominator: ";
    cin >> *this;
}
void Rational::output() const { cout << *this << endl; }
double Rational::toDouble() const { return static_cast<double>(nom) / den; }
void Rational::setNom(int n) { reduce(n, den); }
void Rational::setDen(int m) { reduce(nom, m); }

Rational Rational::add(const Rational& x) const {
    Rational r;
    r.reduce(static_cast<long long>(nom) * x.den + static_cast<long long>(x.nom) * den,
             static_cast<long long>(den) * x.den);
    return r;
}
Rational Rational::sub(const Rational& x) const {
    Rational r;
    r.reduce(static_cast<long long>(nom) * x.den - static_cast<long long>(x.nom) * den,
             static_cast<long long>(den) * x.den);
    return r;
}
Rational Rational::mul(const Rational& x) const {
    Rational r;
    r.reduce(static_cast<long long>(nom) * x.nom, static_cast<long long>(den) * x.den);
    return r;
}
Rational Rational::div(const Rational& x) const {
    if (x.nom == 0) throw domain_error("Division by zero.");
    Rational r;
    r.reduce(static_cast<long long>(nom) * x.den, static_cast<long long>(den) * x.nom);
    return r;
}
bool Rational::operator==(const Rational& x) const {
    return nom == x.nom && den == x.den;
}
bool Rational::operator<(const Rational& x) const {
    return static_cast<long long>(nom) * x.den < static_cast<long long>(x.nom) * den;
}
ostream& operator<<(ostream& out, const Rational& x) {
    return out << x.nom << "/" << x.den;
}
istream& operator>>(istream& in, Rational& x) {
    int n, m;
    if (in >> n >> m) {
        try { x.reduce(n, m); }
        catch (const exception&) { in.setstate(ios::failbit); }
    }
    return in;
}
