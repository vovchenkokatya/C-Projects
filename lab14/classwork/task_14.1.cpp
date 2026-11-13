//
// Created by Katya on 13.11.2026.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("input.txt");

    if (!fin) {
        cout << "Cannot open file" << endl;
        return 0;
    }

    double sum, x;
    char c;

    fin >> sum;

    while (fin >> c) {
        if (c == '=')
            break;

        fin >> x;

        if (c == '+')
            sum += x;
        else if (c == '-')
            sum -= x;
    }

    cout << "Result = " << sum << endl;

    fin.close();
    return 0;
}
