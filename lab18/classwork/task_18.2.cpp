#include "InputArray.h"
#include <exception>
#include <iostream>
#include <memory>
#include <stack>

using namespace std;

namespace lab18 {

template <class T>
void printAndCheck(Stack<T> custom, stack<T> standard) {
    cout << "Custom stack (LIFO): ";
    stack<T> standardCopy(standard);
    while (!custom.empty()) {
        if (standard.empty() || custom.top() != standard.top())
            throw logic_error("Stack results do not match.");
        cout << custom.pop() << " ";
        standard.pop();
    }
    if (!standard.empty()) throw logic_error("Stack sizes do not match.");
    cout << "\nSTL stack (LIFO): ";
    while (!standardCopy.empty()) {
        cout << standardCopy.top() << " ";
        standardCopy.pop();
    }
    cout << "\nResults match." << endl;
}

}

int main() {
    try {
        int* array = nullptr;
        cout << "Enter integers, ending with 0: ";
        size_t n = lab18::inputArray(array, cin);
        unique_ptr<int[]> owner(array);
        cout << "Number of elements: " << n << "\nArray: ";
        lab18::Stack<int> custom;
        stack<int> standard;
        for (size_t i = 0; i < n; ++i) {
            cout << array[i] << " ";
            custom.push(array[i]);
            standard.push(array[i]);
        }
        cout << endl;
        lab18::printAndCheck(custom, standard);

        lab18::Stack<double> realCustom;
        stack<double> realStandard;
        cout << "Enter real numbers, ending with 0: ";
        double value;
        while (true) {
            if (!(cin >> value)) throw runtime_error("Expected a real number and a terminating zero.");
            if (value == 0) break;
            realCustom.push(value);
            realStandard.push(value);
        }
        lab18::printAndCheck(realCustom, realStandard);
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
