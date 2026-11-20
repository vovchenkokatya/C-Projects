#include "Maximum.h"
#include "../common/Rational.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    cout << "Enter two integers: ";
    if (!(cin >> a >> b)) return 1;
    cout << "Maximum: " << lab18::maximum(a, b) << endl;

    double x, y;
    cout << "Enter two real numbers: ";
    if (!(cin >> x >> y)) return 1;
    cout << "Maximum: " << lab18::maximum(x, y) << endl;

    string first, second;
    cout << "Enter two words: ";
    if (!(cin >> first >> second)) return 1;
    cout << "Maximum (lexicographic): " << lab18::maximum(first, second) << endl;
    cout << "C strings (apple, pear): " << lab18::maximum("apple", "pear") << endl;

    lab18::Rational r1, r2;
    cout << "Enter two fractions as numerator denominator pairs: ";
    if (!(cin >> r1 >> r2)) {
        cerr << "Invalid fraction: denominator must be nonzero." << endl;
        return 1;
    }
    // Rational::operator< lets the same function work with fractions.
    cout << "Maximum fraction: " << lab18::maximum(r1, r2) << endl;
    return 0;
}
