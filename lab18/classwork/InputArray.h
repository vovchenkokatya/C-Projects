#pragma once
#include "Stack.h"
#include <istream>
#include <memory>
#include <stdexcept>

namespace lab18 {

// The caller owns the returned array and must call delete[]. Zero is not stored.
inline std::size_t inputArray(int*& result, std::istream& in) {
    Stack<int> values;
    int value;
    while (true) {
        if (!(in >> value)) throw std::runtime_error("Expected an integer and a terminating zero.");
        if (value == 0) break;
        values.push(value);
    }
    std::size_t n = values.size();
    std::unique_ptr<int[]> array(n == 0 ? nullptr : new int[n]);
    // Restore input order when taking values out of the stack.
    for (std::size_t i = n; i > 0; --i) array[i - 1] = values.pop();
    result = array.release();
    return n;
}

}
