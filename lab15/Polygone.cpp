#include "Polygone.h"

#include <iostream>
#include <string>

using namespace std;

void Polygone::input() {
    points.clear();
    n = 0;
    string answer;

    while (true) {
        cout << "Enter a vertex? (yes/no): ";
        if (!(cin >> answer) || answer == "no" || answer == "No" || answer == "ні" || answer == "Ні") {
            break;
        }

        if (answer == "yes" || answer == "Yes" || answer == "так" || answer == "Так") {
            Point p = Point::input();
            if (!cin) {
                cout << "Invalid coordinates." << endl;
                return;
            }

            points.push_back(p);
            n++;
        } else {
            cout << "Please answer yes or no." << endl;
        }
    }
}

double Polygone::perimeter() const {
    if (n < 3) {
        return 0;
    }

    double sum = 0;
    for (int i = 1; i < n; i++) {
        sum += Point::length(points[i - 1], points[i]);
    }
    sum += Point::length(points[n - 1], points[0]);

    return sum;
}
