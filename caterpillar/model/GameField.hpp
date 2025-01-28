//
// Created by minat on 25.10.2024.
//

#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "Point.hpp"
#include <random>
using namespace std;

class GameField {

private:
    int width, height;
    Point cabbage;
    mt19937 random;
    uniform_int_distribution<int> distributionX;
    uniform_int_distribution<int> distributionY;

public:
    GameField(int width, int height);
    void placeCabbage();
    [[nodiscard]] Point getCabbage() const;
    [[nodiscard]] bool isCabbageEaten(const Point& caterpillarHead) const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;

};

#endif //GAMEFIELD_H

