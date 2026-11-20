#pragma once
#include <algorithm>
#include <ostream>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace lab18 {

template <class T>
class Mediana
{
    std::vector<T> elements;

public:
    Mediana() {}

    Mediana(const T* values, int n) {
        if (n < 0 || n > 100) throw std::invalid_argument("Size must be from 0 to 100.");
        if (n > 0 && values == nullptr) throw std::invalid_argument("Array cannot be null.");
        for (int i = 0; i < n; ++i) push(values[i]);
    }

    int size() const { return static_cast<int>(elements.size()); }

    void push(const T& value) {
        if (size() == 100) throw std::overflow_error("Mediana can contain at most 100 elements.");
        elements.insert(std::lower_bound(elements.begin(), elements.end(), value), value);
    }

    // n is a 1-based position in ascending sorted order.
    T pop(int n) {
        if (n < 1 || n > size()) throw std::out_of_range("Invalid element number.");
        T result = elements[n - 1];
        elements.erase(elements.begin() + n - 1);
        return result;
    }

    typedef typename std::conditional<std::is_arithmetic<T>::value, long double, T>::type MedianType;

    MedianType mediana() const {
        if (elements.empty()) throw std::underflow_error("Mediana is empty.");
        return medianValue(typename std::is_arithmetic<T>::type());
    }

    friend std::ostream& operator<<(std::ostream& out, const Mediana& value) {
        for (int i = 0; i < value.size(); ++i) {
            if (i > 0) out << " ";
            out << value.elements[i];
        }
        return out;
    }

private:
    long double medianValue(std::true_type) const {
        int middle = size() / 2;
        if (size() % 2 == 1) return static_cast<long double>(elements[middle]);
        return static_cast<long double>(elements[middle - 1]) / 2
             + static_cast<long double>(elements[middle]) / 2;
    }

    // For types supporting only comparison, return the lower central element.
    T medianValue(std::false_type) const {
        return elements[(size() - 1) / 2];
    }
};

}
