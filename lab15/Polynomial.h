#pragma once
#include <iosfwd>

class Polynomial
{
    int n;
    double* coefficients;

public:
    explicit Polynomial(int size);
    Polynomial(int size, const double* values);
    Polynomial(const Polynomial& other);
    Polynomial& operator=(const Polynomial& other);
    ~Polynomial();

    void setCoefficients(const double* values);
    void setCoefficient(int index, double value);
    double getCoefficient(int index) const;
    int size() const { return n; }

    friend std::istream& operator>>(std::istream& in, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);
    friend bool writeBinary(const char* filename, const Polynomial& p);
    friend bool readBinary(const char* filename, Polynomial& p);
};
