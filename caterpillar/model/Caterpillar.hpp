//
// Created by minat on 25.10.2024.
//

#ifndef CATERPILLAR_H
#define CATERPILLAR_H
#include <vector>
using namespace std;

#include "Point.hpp"

enum Direction { UP, DOWN, LEFT, RIGHT };

class Caterpillar {

private:
    vector<Point> body;
    int length;
    Direction direction;
    int score;

public:
    Caterpillar(int startX, int startY, Direction initial_direction);
    void move(int dx, int dy);
    void setDirection(Direction new_direction);
    Direction getDirection() const;
    void grow();
    [[nodiscard]] Point getHead() const;
    [[nodiscard]] const vector<Point>& getBody() const;
    [[nodiscard]] bool checkCollision(int fieldWidth, int fieldHeight) const;
    [[nodiscard]] int getScore() const;
};

#endif //CATERPILLAR_H
