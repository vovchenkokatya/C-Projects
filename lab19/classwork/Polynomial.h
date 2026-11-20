#pragma once
#include <list>
#include <iostream>

namespace lab19 {

// Coefficients are stored in order: a0, a1, ..., an.
template <class T>
class Polynomial {
    std::list<T> coefficients;

    void normalize() {
        while (coefficients.size() > 1 && coefficients.back() == T(0))
            coefficients.pop_back();
    }

public:
    Polynomial() : coefficients(1, T(0)) {}

    explicit Polynomial(const std::list<T>& values) : coefficients(values) {
        if (coefficients.empty()) coefficients.push_back(T(0));
        normalize();
    }

    T value(const T& x) const {
        T result(0);
        for (auto i = coefficients.rbegin(); i != coefficients.rend(); ++i)
            result = result * x + *i;
        return result;
    }

    Polynomial operator+(const Polynomial& other) const {
        std::list<T> result;
        auto a = coefficients.begin();
        auto b = other.coefficients.begin();
        while (a != coefficients.end() || b != other.coefficients.end()) {
            T sum(0);
            if (a != coefficients.end()) sum = sum + *a++;
            if (b != other.coefficients.end()) sum = sum + *b++;
            result.push_back(sum);
        }
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        std::list<T> result(coefficients.size() + other.coefficients.size() - 1, T(0));
        auto start = result.begin();
        for (const T& a : coefficients) {
            auto position = start;
            for (const T& b : other.coefficients) {
                *position = *position + a * b;
                ++position;
            }
            ++start;
        }
        return Polynomial(result);
    }

    // Input: nonnegative degree, followed by degree + 1 coefficients.
    friend std::istream& operator>>(std::istream& in, Polynomial& p) {
        int degree;
        if (!(in >> degree)) return in;
        if (degree < 0) {
            in.setstate(std::ios::failbit);
            return in;
        }
        std::list<T> values;
        for (long long i = 0; i <= degree; i++) {
            T x(0);
            if (!(in >> x)) return in;
            values.push_back(x);
        }
        Polynomial temporary(values);
        p.coefficients.swap(temporary.coefficients);
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
        std::size_t power = 0;
        for (const T& a : p.coefficients) {
            if (power > 0) out << " + ";
            out << "(" << a << ")";
            if (power > 0) out << "*x^" << power;
            ++power;
        }
        return out;
    }
};

}
