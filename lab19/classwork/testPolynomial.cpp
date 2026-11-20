#include "Polynomial.h"
#include "../common/Rational.h"
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;
using namespace lab19;

int failures = 0;

void check(bool condition, const char* name) {
    if (!condition) {
        cerr << "Failed: " << name << endl;
        failures++;
    }
}

int main() {
    Polynomial<int> a(list<int>{1, 2, 3});
    Polynomial<int> b(list<int>{-1, 1});
    check(a.value(2) == 17, "integer evaluation");
    check((a + b).value(2) == 18, "different degrees, addition");
    check((a * b).value(2) == 17, "different degrees, multiplication");
    check((a * a).value(3) == 1156, "self multiplication");

    Polynomial<int> zero;
    check(zero.value(7) == 0, "default polynomial is zero");
    check((a * zero).value(3) == 0, "multiplication by zero");
    check((a + zero).value(3) == 34, "addition of zero");
    check(Polynomial<int>(list<int>{}).value(5) == 0, "empty coefficient list");
    Polynomial<int> cancellation(list<int>{-1, -2, -3});
    ostringstream text;
    text << a + cancellation;
    check(text.str() == "(0)", "normalization after cancellation");
    text.str("");
    text << Polynomial<int>(list<int>{5, 0, 0});
    check(text.str() == "(5)", "trailing zero coefficients");

    Polynomial<double> realA(list<double>{0.5, 1.5});
    Polynomial<double> realB(list<double>{-0.25, 0.5, 2.0});
    check(abs(realA.value(0.5) - 1.25) < 1e-12, "real evaluation");
    check(abs((realA + realB).value(0.5) - 1.75) < 1e-12, "real addition");
    check(abs((realA * realB).value(0.5) - 0.625) < 1e-12, "real multiplication");

    Polynomial<Rational> r1(list<Rational>{Rational(1, 2), Rational(1, 3)});
    Polynomial<Rational> r2(list<Rational>{Rational(1, 4), Rational(-1, 3)});
    Rational x(3, 2);
    check(r1.value(x) == Rational(1), "rational evaluation");
    check((r1 + r2).value(x) == Rational(3, 4), "rational addition");
    check((r1 * r2).value(x) == Rational(-1, 4), "rational multiplication");
    check((r1 * Polynomial<Rational>()).value(x) == Rational(0), "rational zero identity");

    istringstream input("2 1 2 3");
    Polynomial<int> parsed;
    check(static_cast<bool>(input >> parsed) && parsed.value(2) == 17, "polynomial input");
    istringstream invalid("-1");
    check(!(invalid >> parsed) && parsed.value(2) == 17, "negative degree preserves value");
    istringstream incomplete("2 8 9");
    check(!(incomplete >> parsed) && parsed.value(2) == 17, "incomplete coefficient list");
    istringstream fractionInput("1 1 2 1 3");
    Polynomial<Rational> parsedFraction;
    check(static_cast<bool>(fractionInput >> parsedFraction)
          && parsedFraction.value(x) == Rational(1), "rational input");
    istringstream invalidFraction("0 1 0");
    check(!(invalidFraction >> parsedFraction)
          && parsedFraction.value(x) == Rational(1), "zero denominator rejected");

    if (failures == 0) cout << "All polynomial tests passed." << endl;
    return failures == 0 ? 0 : 1;
}
