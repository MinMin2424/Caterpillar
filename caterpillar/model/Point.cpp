//
// Created by minat on 25.10.2024.
//

#include "Point.hpp"
using namespace std;

/**
 * Constructor that initializes a point with specified x and y coordinates.
 *
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 */
Point::Point(int x, int y): x(x), y(y) {}

/**
 * Method to check if this point is equal to another point by comparing x and y values.
 *
 * @param other The other point to compare with this point.
 * @return true if the x and y values of the points are equal, otherwise false.
 */
bool Point::isEqual(const Point &other) const {
    return x == other.x && y == other.y;
}

/**
 * Method to check if this point is not equal to another point by comparing x and y values.
 *
 * @param other The other point to compare with this point.
 * @return true if the points are not equal, otherwise false.
 */
bool Point::isNotEqual(const Point &other) const {
    return !isEqual(other);
}

/**
 * Method to move the point by a specified amount in the x and y directions.
 *
 * @param dx The change in the x-coordinate.
 * @param dy The change in the y-coordinate.
 */
void Point::move(int dx, int dy) {
    x += dx;
    y += dy;
}


