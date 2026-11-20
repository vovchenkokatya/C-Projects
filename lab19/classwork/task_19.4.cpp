#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cout << "Number of rows and columns (1..99): ";
    if (!(cin >> n >> m) || n <= 0 || n >= 100 || m <= 0 || m >= 100) {
        cerr << "Invalid matrix dimensions." << endl;
        return 1;
    }

    vector<list<double>> matrix(n);
    cout << "Enter matrix:" << endl;
    for (list<double>& row : matrix) {
        for (int j = 0; j < m; j++) {
            double x;
            if (!(cin >> x) || !isfinite(x)) {
                cerr << "Invalid matrix element." << endl;
                return 1;
            }
            row.push_back(x);
        }
    }

    stable_sort(matrix.begin(), matrix.end(),
        [](const list<double>& a, const list<double>& b) {
            return *max_element(a.begin(), a.end()) > *max_element(b.begin(), b.end());
        });

    cout << "Rows sorted by decreasing maximum:" << endl;
    for (const list<double>& row : matrix) {
        for (double x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}
