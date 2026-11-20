#include "Polynomial.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <istream>
#include <ostream>
#include <stdexcept>

using namespace std;

Polynomial::Polynomial(int size) : n(size), coefficients(nullptr) {
    if (n <= 0) throw invalid_argument("Number of coefficients must be positive.");
    coefficients = new double[n]();
}
Polynomial::Polynomial(int size, const double* values) : Polynomial(size) {
    setCoefficients(values);
}
Polynomial::Polynomial(const Polynomial& other) : Polynomial(other.n, other.coefficients) {}
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        double* copy = new double[other.n];
        std::copy(other.coefficients, other.coefficients + other.n, copy);
        delete[] coefficients;
        coefficients = copy;
        n = other.n;
    }
    return *this;
}
Polynomial::~Polynomial() { delete[] coefficients; }

void Polynomial::setCoefficients(const double* values) {
    if (values == nullptr) throw invalid_argument("Coefficient array cannot be null.");
    for (int i = 0; i < n; i++)
        if (!isfinite(values[i])) throw invalid_argument("Coefficients must be finite.");
    copy(values, values + n, coefficients);
}
void Polynomial::setCoefficient(int index, double value) {
    if (index < 0 || index >= n) throw out_of_range("Invalid coefficient index.");
    if (!isfinite(value)) throw invalid_argument("Coefficient must be finite.");
    coefficients[index] = value;
}
double Polynomial::getCoefficient(int index) const {
    if (index < 0 || index >= n) throw out_of_range("Invalid coefficient index.");
    return coefficients[index];
}

istream& operator>>(istream& in, Polynomial& p) {
    Polynomial value(p.n);
    for (int i = 0; i < p.n; i++) {
        if (!(in >> value.coefficients[i])) return in;
        if (!isfinite(value.coefficients[i])) {
            in.setstate(ios::failbit);
            return in;
        }
    }
    p = value;
    return in;
}
ostream& operator<<(ostream& out, const Polynomial& p) {
    bool first = true;
    // coefficients[i] is the coefficient of x^i.
    for (int i = p.n - 1; i >= 0; i--) {
        double value = p.coefficients[i];
        if (value == 0) continue;
        if (!first) out << (value < 0 ? " - " : " + ");
        else if (value < 0) out << "-";
        double magnitude = fabs(value);
        if (i == 0 || magnitude != 1) out << magnitude;
        if (i > 0) {
            if (magnitude != 1) out << "*";
            out << "x";
            if (i > 1) out << "^" << i;
        }
        first = false;
    }
    if (first) out << "0";
    return out;
}
bool writeBinary(const char* filename, const Polynomial& p) {
    ofstream file(filename, ios::binary);
    if (!file) return false;
    file.write(reinterpret_cast<const char*>(&p.n), sizeof(p.n));
    file.write(reinterpret_cast<const char*>(p.coefficients), sizeof(double) * p.n);
    file.close();
    return !file.fail();
}
bool readBinary(const char* filename, Polynomial& p) {
    ifstream file(filename, ios::binary | ios::ate);
    if (!file) return false;
    streamoff bytes = file.tellg();
    file.seekg(0);
    int size;
    if (!file.read(reinterpret_cast<char*>(&size), sizeof(size)) || size <= 0) return false;
    if (bytes != static_cast<streamoff>(sizeof(size))
                 + static_cast<streamoff>(sizeof(double)) * size) return false;
    Polynomial value(size);
    if (!file.read(reinterpret_cast<char*>(value.coefficients), sizeof(double) * size)) return false;
    for (int i = 0; i < size; i++)
        if (!isfinite(value.coefficients[i])) return false;
    p = value;
    return true;
}
