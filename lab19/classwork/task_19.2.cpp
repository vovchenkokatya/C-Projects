#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool inputVector(vector<double>& v, int d) {
    if (d <= 0) return false;
    v.resize(d);
    for (int i = 0; i < d; i++) {
        if (!(cin >> v[i]) || !isfinite(v[i])) return false;
    }
    return true;
}

long double norm(const vector<double>& v) {
    long double result = 0;
    for (double x : v) result = hypot(result, static_cast<long double>(x));
    return result;
}

int main() {
    int n, d;
    cout << "Number of vectors and dimension: ";
    if (!(cin >> n >> d) || n <= 0 || d <= 0) {
        cerr << "Number and dimension must be positive." << endl;
        return 1;
    }

    long double sum = 0;
    vector<double> v;
    for (int i = 0; i < n; i++) {
        cout << "Vector " << i + 1 << ": ";
        if (!inputVector(v, d)) {
            cerr << "Invalid vector coordinates." << endl;
            return 1;
        }
        sum += norm(v);
    }
    cout << "Sum of norms = " << sum << endl;
    return 0;
}
