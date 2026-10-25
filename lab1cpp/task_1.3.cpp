//
// Created by Katya on 19.10.2026.
//
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << setw(8) << i;
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        double x = sqrt(i);

        if (x == (int)x) {
            cout << setw(8) << (int)x;
        }
        else {
            cout << setw(8) << fixed
                 << setprecision(2) << x;
        }
    }

    cout << endl;
    return 0;
}