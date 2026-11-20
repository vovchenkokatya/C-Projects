#include "Mediana.h"
#include <exception>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    try {
        int n;
        cout << "Number of elements (0..100): ";
        if (!(cin >> n) || n < 0 || n > 100) {
            cerr << "Size must be from 0 to 100." << endl;
            return 1;
        }
        vector<double> values(n);
        cout << "Enter the elements: ";
        for (int i = 0; i < n; ++i)
            if (!(cin >> values[i])) return 1;
        lab18::Mediana<double> numbers(values.data(), n);
        string words[] = {"pear", "apple", "banana"};
        lab18::Mediana<string> wordExample(words, 3);
        cout << "String example: " << wordExample << "\nString median: " << wordExample.mediana() << endl;
        cout << "Sorted elements: " << numbers << endl;
        while (true) {
            int command;
            cout << "1 - push, 2 - pop by sorted number (1-based), 3 - median, 4 - print, 0 - exit: ";
            if (!(cin >> command)) return 1;
            if (command == 0) break;
            try {
                if (command == 1) {
                    double value;
                    cout << "Value: ";
                    if (!(cin >> value)) return 1;
                    numbers.push(value);
                } else if (command == 2) {
                    int index;
                    cout << "Element number: ";
                    if (!(cin >> index)) return 1;
                    double removed = numbers.pop(index);
                    cout << "Removed: " << removed << endl;
                } else if (command == 3) {
                    long double median = numbers.mediana();
                    cout << "Median: " << median << endl;
                } else if (command == 4) {
                    cout << "Elements (" << numbers.size() << "): " << numbers << endl;
                } else {
                    cout << "Unknown command." << endl;
                }
            } catch (const exception& e) {
                cout << e.what() << endl;
            }
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
