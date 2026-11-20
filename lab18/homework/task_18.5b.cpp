#include "Array.h"
#include <exception>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

namespace lab18 {

template <class T>
int sortExample() {
    int n;
    cout << "Number of elements: ";
    if (!(cin >> n) || n < 0) {
        cerr << "Enter a nonnegative integer." << endl;
        return 1;
    }
    Array<T> a(n);
    unique_ptr<T[]> external(n == 0 ? nullptr : new T[n]);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        if (!(cin >> a[i])) {
            cerr << "Invalid element." << endl;
            return 1;
        }
        external[i] = a[i];
    }
    a.shakerSort();
    Array<T>::shakerSort(external.get(), n);
    cout << "Member sort: ";
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << "\nStatic sort: ";
    for (int i = 0; i < n; ++i) cout << external[i] << " ";
    cout << endl;
    return 0;
}

}

int main() {
    int type;
    cout << "Element type (1 - int, 2 - double, 3 - string): ";
    if (!(cin >> type)) return 1;
    try {
        if (type == 1) return lab18::sortExample<int>();
        if (type == 2) return lab18::sortExample<double>();
        if (type == 3) return lab18::sortExample<string>();
        cerr << "Unknown element type." << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return 1;
}
