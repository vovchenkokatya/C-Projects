
#include "Rational.h"
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "n = ";
    if (!(cin >> n) || n < 1 || n > 100) {
        cerr << "Enter an integer from 1 to 100." << endl;
        return 1;
    }

    Rational a[100];

    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        if (!(cin >> a[i])) {
            cerr << "Invalid fraction. Enter two integers; denominator must be nonzero." << endl;
            return 1;
        }
    }

    Rational min = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] <= min)
            min = a[i];
    }

    cout << "Min: " << min << endl;

    Rational sum(0, 1);

    double eps = 0.01;
    int k = 1;

    while (true) {
        Rational t;
        t.setNom(1);
        t.setDen(k * k);

        if (k % 2 == 1)
            sum = sum + t;
        else
            sum = sum - t;

        if (1.0 / ((k + 1) * (k + 1)) < eps)
            break;

        k++;
    }

    double pi = acos(-1.0);

    cout << fixed << setprecision(6);
    cout << "Sum as fraction: " << sum << endl;
    cout << "Sum: " << sum.toDouble() << endl;
    cout << "pi^2 / 12: " << pi * pi / 12 << endl;
    cout << "Difference: "
         << fabs(sum.toDouble() - pi * pi / 12) << endl;

    return 0;
}
