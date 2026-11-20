#include "Rectangle.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

// The default rectangle represents an empty intersection.
Rectangle::Rectangle() : x(-1), y(-1), width(-1), height(-1) {}
Rectangle::Rectangle(double left, double top, double w, double h)
    : x(left), y(top), width(w), height(h) {
    if (!isfinite(x) || !isfinite(y) || !isfinite(w) || !isfinite(h)
        || w <= 0 || h <= 0 || !isfinite(x + w) || !isfinite(y - h))
        throw invalid_argument("Coordinates must be finite and side lengths positive.");
}
double Rectangle::getWidth() const { return width; }
double Rectangle::getHeight() const { return height; }
bool Rectangle::isEmpty() const { return width < 0; }
double Rectangle::area() const { return isEmpty() ? 0 : width * height; }
double Rectangle::perimeter() const { return isEmpty() ? 0 : 2 * (width + height); }

Rectangle Rectangle::intersection(const Rectangle& other) const {
    if (isEmpty() || other.isEmpty()) return Rectangle();
    // Cartesian coordinates: the bottom side has coordinate y - height.
    double left = max(x, other.x);
    double right = min(x + width, other.x + other.width);
    double top = min(y, other.y);
    double bottom = max(y - height, other.y - other.height);
    if (left > right || bottom > top) return Rectangle();
    // A shared edge or vertex is also a nonempty intersection.
    Rectangle result;
    result.x = left;
    result.y = top;
    result.width = right - left;
    result.height = top - bottom;
    return result;
}
void Rectangle::input() {
    cout << "Enter left x, top y, width and height: ";
    cin >> *this;
}
void Rectangle::output() const { cout << *this << endl; }
istream& operator>>(istream& in, Rectangle& r) {
    double x, y, w, h;
    if (in >> x >> y >> w >> h) {
        try { r = Rectangle(x, y, w, h); }
        catch (const invalid_argument&) { in.setstate(ios::failbit); }
    }
    return in;
}
ostream& operator<<(ostream& out, const Rectangle& r) {
    return out << "(" << r.x << ", " << r.y << ", "
               << r.width << ", " << r.height << ")";
}
