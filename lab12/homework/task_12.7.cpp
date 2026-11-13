//
// Created by Katya on 13.11.2026.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ifstream fin("input.txt");

    if (!fin) {
        cout << "Cannot open input.txt" << endl;
        return 0;
    }

    int n = 0;
    double x;

    while (fin >> x) {
        n++;
        fin >> ws;
        if (fin.peek() == ';')
            fin.get();
        else if (fin.peek() != EOF) {
            cout << "Incorrect input file" << endl;
            return 0;
        }
    }

    fin.clear();
    fin.seekg(0);

    double* a = new double[n];

    for (int i = 0; i < n; i++) {
        fin >> a[i];
        fin >> ws;
        if (fin.peek() == ';')
            fin.get();
    }

    fin.close();

    ofstream fout("output.txt");

    if (!fout) {
        cout << "Cannot open output.txt" << endl;
        delete[] a;
        return 0;
    }

    fout << scientific << setprecision(6);

    for (int i = 0; i < n; i++) {
        if (a[i] >= -1 && a[i] <= 1)
            fout << asin(a[i]) << endl;
    }

    fout.close();
    delete[] a;

    return 0;
}
