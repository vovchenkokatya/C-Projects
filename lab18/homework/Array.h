#pragma once
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <utility>

namespace lab18 {

template <class T>
class Array
{
    int n;
    std::unique_ptr<T[]> values;

public:
    explicit Array(int size = 0) : n(size) {
        if (n < 0) throw std::invalid_argument("Array size cannot be negative.");
        if (n > 0) values.reset(new T[n]());
    }

    Array(const T* data, int size) : Array(size) {
        if (n > 0 && data == nullptr) throw std::invalid_argument("Array cannot be null.");
        if (n > 0) std::copy(data, data + n, values.get());
    }

    Array(const Array& other) : Array(other.values.get(), other.n) {}

    Array& operator=(const Array& other) {
        if (this != &other) {
            Array copy(other);
            std::swap(n, copy.n);
            values.swap(copy.values);
        }
        return *this;
    }

    int size() const { return n; }

    T& operator[](int index) {
        if (index < 0 || index >= n) throw std::out_of_range("Invalid array index.");
        return values[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= n) throw std::out_of_range("Invalid array index.");
        return values[index];
    }

    void shakerSort() { shakerSort(values.get(), n); }

    // Both forms sort in place; the static form works with an external array.
    static void shakerSort(T* data, int size) {
        if (size < 0) throw std::invalid_argument("Array size cannot be negative.");
        if (size > 0 && data == nullptr) throw std::invalid_argument("Array cannot be null.");
        int left = 0, right = size - 1;
        while (left < right) {
            bool swapped = false;
            for (int i = left; i < right; ++i) {
                if (data[i + 1] < data[i]) {
                    std::swap(data[i], data[i + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
            --right;
            swapped = false;
            for (int i = right; i > left; --i) {
                if (data[i] < data[i - 1]) {
                    std::swap(data[i], data[i - 1]);
                    swapped = true;
                }
            }
            ++left;
            if (!swapped) break;
        }
    }
};

}
