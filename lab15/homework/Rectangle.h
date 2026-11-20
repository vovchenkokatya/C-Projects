#pragma once
#include <iosfwd>

class Rectangle
{
    double x, y, width, height;

public:
    Rectangle();
    Rectangle(double left, double top, double w, double h);
    double getWidth() const;
    double getHeight() const;
    double area() const;
    double perimeter() const;
    bool isEmpty() const;
    Rectangle intersection(const Rectangle& other) const;
    void input();
    void output() const;

    friend std::istream& operator>>(std::istream& in, Rectangle& r);
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);
};
