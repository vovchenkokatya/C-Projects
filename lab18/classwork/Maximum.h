#pragma once
#include <cstring>
#include <stdexcept>

namespace lab18 {

template <class T>
T maximum(T a, T b) {
    return a < b ? b : a;
}

// C strings must be compared by their contents, not their addresses.
template <>
inline const char* maximum<const char*>(const char* a, const char* b) {
    if (a == nullptr || b == nullptr)
        throw std::invalid_argument("String cannot be null.");
    return std::strcmp(a, b) < 0 ? b : a;
}

template <>
inline char* maximum<char*>(char* a, char* b) {
    if (a == nullptr || b == nullptr)
        throw std::invalid_argument("String cannot be null.");
    return std::strcmp(a, b) < 0 ? b : a;
}

}
