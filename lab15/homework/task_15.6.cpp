#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    Rectangle a, b;
    cout << "First rectangle" << endl;
    a.input();
    if (!cin) {
        cerr << "Invalid rectangle: enter finite coordinates and positive side lengths." << endl;
        return 1;
    }
    cout << "Second rectangle" << endl;
    b.input();
    if (!cin) {
        cerr << "Invalid rectangle: enter finite coordinates and positive side lengths." << endl;
        return 1;
    }
    cout << "A = " << a << endl;
    cout << "Width: " << a.getWidth() << ", height: " << a.getHeight() << endl;
    cout << "Area: " << a.area() << ", perimeter: " << a.perimeter() << endl;
    cout << "B = " << b << endl;
    cout << "Width: " << b.getWidth() << ", height: " << b.getHeight() << endl;
    cout << "Area: " << b.area() << ", perimeter: " << b.perimeter() << endl;
    Rectangle common = a.intersection(b);
    cout << "Intersection: " << common << endl;
    if (common.isEmpty()) cout << "The intersection is empty." << endl;
    else cout << "Intersection area: " << common.area() << endl;
    return 0;
}
