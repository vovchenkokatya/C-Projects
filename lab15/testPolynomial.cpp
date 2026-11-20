#include "Polynomial.h"
#include <exception>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Number of coefficients: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Enter a positive integer." << endl;
        return 1;
    }
    try {
        Polynomial p(n);
        cout << "Enter coefficients a[0] ... a[" << n - 1 << "] (ascending powers): ";
        if (!(cin >> p)) {
            cerr << "Invalid coefficients." << endl;
            return 1;
        }
        cout << "P(x) = " << p << endl;
        Polynomial copy(p);
        Polynomial assigned(1);
        assigned = p;
        cout << "Copy: " << copy << endl;
        cout << "Assigned polynomial: " << assigned << endl;

        int index;
        double value;
        cout << "Enter coefficient index (0-based) and its new value: ";
        if (!(cin >> index >> value)) return 1;
        p.setCoefficient(index, value);
        cout << "Updated P(x) = " << p << endl;
        cout << "Unchanged copy: " << copy << endl;

        string filename;
        cout << "Binary filename: ";
        if (!(cin >> filename)) return 1;
        if (!writeBinary(filename.c_str(), p)) {
            cerr << "Cannot write the binary file." << endl;
            return 1;
        }
        Polynomial restored(1);
        if (!readBinary(filename.c_str(), restored)) {
            cerr << "Cannot read the binary file." << endl;
            return 1;
        }
        cout << "Read from file: " << restored << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
