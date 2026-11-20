#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Number of customers: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid number of customers." << endl;
        return 1;
    }

    queue<double> times;
    cout << "Service times in minutes: ";
    for (int i = 0; i < n; i++) {
        double t;
        if (!(cin >> t) || !isfinite(t) || t < 0) {
            cerr << "Service time must be finite and nonnegative." << endl;
            return 1;
        }
        times.push(t);
    }

    long double finish = 0, longest = -1;
    double shortest = times.front();
    int fastestCustomer = 1, longestCustomer = 1;

    for (int i = 0; !times.empty(); i++) {
        double service = times.front();
        times.pop();
        // Customer i + 1 arrives at minute i. Include service in c_i.
        long double start = max(finish, static_cast<long double>(i));
        finish = start + service;
        long double total = finish - i;
        cout << "c[" << i + 1 << "] = " << total
             << ", waiting before service = " << start - i << endl;

        if (service < shortest) {
            shortest = service;
            fastestCustomer = i + 1;
        }
        if (total > longest) {
            longest = total;
            longestCustomer = i + 1;
        }
    }

    cout << "Shortest service: customer " << fastestCustomer << endl;
    cout << "Longest time in queue (including service): customer "
         << longestCustomer << endl;
    return 0;
}
