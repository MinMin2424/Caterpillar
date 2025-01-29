//
// Created by minat on 25.10.2024.
//

#include "Caterpillar.hpp"
#include <iostream>
#include <vector>
using namespace std;

// Constructor
Caterpillar::Caterpillar(int startX, int startY, Direction initial_direction) :
    length(1),
    direction(initial_direction),
    score(0)
{body.emplace_back(startX, startY);}

// Method to move caterpillar
void Caterpillar::move(int dx, int dy) {
    Point newHead = body.front();
    newHead.move(dx, dy);
    body.insert(body.begin(), newHead);
    body.pop_back();
}

// Method to set the direction of caterpillar
void Caterpillar::setDirection(Direction new_direction) {
    direction = new_direction;
}

// Method to grow the caterpillar
void Caterpillar::grow() {
    body.emplace_back(body.back());
    length++;
    score++;
}

// Get the position of the caterpillar's head
Point Caterpillar::getHead() const {
    return body.front();
}

// Get the body of the caterpillar
const vector<Point>& Caterpillar::getBody() const {
    return body;
}

// Check for collisions
bool Caterpillar::checkCollision(int fieldWidth, int fieldHeight) const {
    const Point& head = getHead();
    int borderWidth = fieldWidth - 1;
    int borderHeight = fieldHeight - 1;
    // Check if the head has collided with the borders
    if (head.x < 0 || head.y < 0 || head.x > borderWidth || head.y > borderHeight) return true;
    // Check if it collided with itself
    for (auto i : body) {
        if (head.isEqual(i)) {
            return true;
        }
    }
    return false;
}

// Get the score
int Caterpillar::getScore() const {
    return score;
}
