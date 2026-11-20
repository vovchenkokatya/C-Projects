#include "Addition.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 1 && argc != 4) {
        cerr << "Usage: task_19_13 [first.txt second.txt result.txt]" << endl;
        return 1;
    }
    const char* first = argc == 4 ? argv[1] : "first.txt";
    const char* second = argc == 4 ? argv[2] : "second.txt";
    const char* output = argc == 4 ? argv[3] : "result.txt";
    ifstream finA(first), finB(second);
    if (!finA || !finB) {
        cerr << "Cannot open input files." << endl;
        return 1;
    }

    vector<Number> a, b;
    if (!readNumbers(finA, a) || !readNumbers(finB, b)) {
        cerr << "Invalid input file. Use number base, or one base: \"number\" per line." << endl;
        return 1;
    }
    if (a.size() != b.size()) {
        cerr << "Input files must contain the same number of records." << endl;
        return 1;
    }

    int base;
    cout << "Result base (at least 2): ";
    string line;
    if (!getline(cin >> ws, line)) {
        cerr << "Invalid result base." << endl;
        return 1;
    }
    istringstream baseInput(line);
    if (!(baseInput >> base) || base < 2) {
        cerr << "Invalid result base." << endl;
        return 1;
    }
    baseInput >> ws;
    if (!baseInput.eof()) {
        cerr << "Invalid result base." << endl;
        return 1;
    }

    ofstream fout(output);
    if (!fout) {
        cerr << "Cannot open output file." << endl;
        return 1;
    }
    for (size_t i = 0; i < a.size(); i++) {
        vector<int> result = addition(a[i].digits, a[i].base, b[i].digits, b[i].base, base);
        if (result.empty()) {
            cerr << "Invalid number in record " << i + 1 << '.' << endl;
            return 1;
        }
        writeNumber(fout, result, base);
        fout << '\n';
        cout << "Sum " << i + 1 << " = ";
        writeNumber(cout, result, base);
        cout << endl;
    }
    fout.close();
    if (!fout) {
        cerr << "Cannot write result file." << endl;
        return 1;
    }
    cout << "Results written to " << output << endl;
    return 0;
}
