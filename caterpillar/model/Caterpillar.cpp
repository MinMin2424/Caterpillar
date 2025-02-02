//
// Created by minat on 25.10.2024.
//

#include "Caterpillar.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Constructor: Initializes the caterpillar's starting position, and other attributes.
 * The caterpillar starts with a length of 1, a score of 0, and 5 lives.
 * The body vector is initialized with the starting position.
 *
 * @param startX The x-coordinate of the starting position of the caterpillar.
 * @param startY The y-coordinate of the starting position of the caterpillar.
 * @param initial_direction The initial direction of the caterpillar. (UP, DOWN, LEFT, RIGHT).
 */
Caterpillar::Caterpillar(int startX, int startY, Direction initial_direction) :
    length(1),
    direction(initial_direction),
    score(0),
    lives(5)
{body.emplace_back(startX, startY);}

/**
 * Method to move the caterpillar by the specified deltas.
 *
 * @param dx The change in the x-coordinate.
 * @param dy The change in the y-coordinate.
 */
void Caterpillar::move(int dx, int dy) {
    Point newHead = body.front();
    newHead.move(dx, dy);
    body.insert(body.begin(), newHead);
    if (length < body.size()) {
        body.pop_back();
    }
}

/**
 * Method to set the caterpillar's direction (UP, DOWN, LEFT, RIGHT).
 * It ensures that the caterpillar cannot reverse direction.
 *
 * @param new_direction The new direction to set for the caterpillar.
 */
void Caterpillar::setDirection(Direction new_direction) {

    if ((new_direction == UP && direction == DOWN) ||
        (new_direction == DOWN && direction == UP) ||
        (new_direction == LEFT && direction == RIGHT) ||
        (new_direction == RIGHT && direction == LEFT)) {
        return ;
    }
    direction = new_direction;

}

/**
 * Method to return the current direction of the caterpillar.
 *
 * @return Direction The current direction of the caterpillar.
 */
Direction Caterpillar::getDirection() const {
    return direction;
}

/**
 * Method to grow the caterpillar after eating food.
 * The caterpillar's length increases and the body is extended by adding a new segment at the end.
 * The score increases based on the type of food eaten (CABBAGE or STRAWBERRY).
 *
 * @param food The type of food the caterpillar eats.
 */
void Caterpillar::grow(Food food) {
    switch (food) {
        case CABBAGE:
            score += 1;
            length++;
            break;
        case STRAWBERRY:
            score += 2;
            length = length + 2;
            break;
    }
    body.emplace_back(body.back());
}

/**
 * Method to get the position of the caterpillar's head.
 *
 * @return Point The position of the caterpillar's head. (the first point in the body)
 */
Point Caterpillar::getHead() const {
    return body.front();
}

/**
 * Method to get the entire body of the caterpillar.
 *
 * @return const vector <Point>& A reference to the vector represents the body of the caterpillar.
 */
const vector<Point>& Caterpillar::getBody() const {
    return body;
}

/**
 * Method to check if the caterpillar has collided with the borders or itself.
 *
 * @param fieldWidth The width of the field.
 * @param fieldHeight The height of the field.
 * @return bool Returns true if there is a collision.
 */
bool Caterpillar::checkCollision(int fieldWidth, int fieldHeight) const {
    const Point& head = getHead();
    int borderWidth = fieldWidth - 1;
    int borderHeight = fieldHeight - 1;

    // Check if the head has collided with the borders
    if (head.x <= 0 || head.y <= 0 || head.x >= borderWidth -1 || head.y >= borderHeight-1) {
        cout << "Collision with border!💥" << endl;
        return true;
    }

    // Check if it collided with itself
    for (size_t i = 1; i < body.size(); i++) {
        if (head.isEqual(body[i])) {
            cout << "Colission with self!" << endl;
            return true;
        }
    }
    return false;
}

/**
 * Method to get the current score of the caterpillar.
 *
 * @return int The current score of the caterpillar.
 */
int Caterpillar::getScore() const {
    return score;
}

/**
 * Reduces the caterpillar's lives by 1 if it collides with something.
 */
void Caterpillar::loseLife() {
    if (lives > 0) {
        lives--;
    }
}

/**
 * Method to get the current number of lives the caterpillar has.
 *
 * @return int The current number of lives of the caterpillar.
 */
int Caterpillar::getLives() const {
    return lives;
}
