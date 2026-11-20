#include "Polynomial.h"
#include "../common/Rational.h"
#include <iostream>
#include <exception>

using namespace std;
using namespace lab19;

template <class T>
bool run(const char* type) {
    cout << endl << type << " coefficients" << endl;
    cout << "First polynomial: degree, then coefficients from a0 to an: ";
    Polynomial<T> a, b;
    if (!(cin >> a)) return false;
    cout << "Second polynomial: degree, then coefficients from a0 to an: ";
    if (!(cin >> b)) return false;
    T x(0);
    cout << "Point x: ";
    if (!(cin >> x)) return false;

    cout << "A = " << a << endl;
    cout << "B = " << b << endl;
    cout << "A + B = " << a + b << endl;
    cout << "A * B = " << a * b << endl;
    cout << "A(x) = " << a.value(x) << endl;
    cout << "B(x) = " << b.value(x) << endl;
    return true;
}

int main() {
    cout << "For fractions, enter numerator and denominator separated by a space." << endl;
    try {
        if (!run<int>("Integer") || !run<double>("Real") || !run<Rational>("Rational")) {
            cerr << "Invalid polynomial or evaluation point." << endl;
            return 1;
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
