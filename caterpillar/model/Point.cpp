//
// Created by minat on 25.10.2024.
//

#include "Point.hpp"
using namespace std;

// Constructor
Point::Point(int x, int y): x(x), y(y) {}

// Checks if this point is equal to another point by comparing x and y values
bool Point::isEqual(const Point &other) const {
    return x == other.x && y == other.y;
}

// Checks if this point is not equal to another point by negating the isEqual result
bool Point::isNotEqual(const Point &other) const {
    return !isEqual(other);
}

// Moves the point
void Point::move(int dx, int dy) {
    x += dx;
    y += dy;
}
