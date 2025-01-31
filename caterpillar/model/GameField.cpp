//
// Created by minat on 25.10.2024.
//

#include "GameField.hpp"
#include <random>

#include "Caterpillar.hpp"
using namespace std;

// Constructor
GameField::GameField(int width, int height, Caterpillar &caterpillar) :
    width(width), height(height),
    random(random_device{} ()),
    distributionX(0, width - 1),
    distributionY(0, height - 1)
{
    placeCabbage(caterpillar);
}

// Place cabbage at a random position
void GameField::placeCabbage(Caterpillar &caterpillar) {
    bool isPositionValid;
    do {
        cabbage.x = distributionX(random);
        cabbage.y = distributionY(random);

        isPositionValid = true;
        for (const Point& part: caterpillar.getBody()) {
            if (cabbage.isEqual(part) || cabbage.isEqual(getStrawberry())) {
                isPositionValid = false;
                break;
            }
        }

    } while (!isPositionValid);

}

void GameField::placeStrawberry(Caterpillar &caterpillar) {
    bool isPositionValid;
    do {
        strawberry.x = distributionX(random);
        strawberry.y = distributionY(random);

        isPositionValid = true;
        for (const Point& part: caterpillar.getBody()) {
            if (strawberry.isEqual(part) || strawberry.isEqual(getCabbage())) {
                isPositionValid = false;
                break;
            }
        }

    } while (!isPositionValid);
}

// Returns the position of the cabbage
Point GameField::getCabbage() const {
    return cabbage;
}

Point GameField::getStrawberry() const {
    return strawberry;
}

// Checks if the cabbage has been eaten by caterpillar
bool GameField::isCabbageEaten(const Point &caterpillarHead) const {
    return caterpillarHead.isEqual(cabbage);
}

bool GameField::isStrawberryEaten(const Point &caterpillarHead) const {
    return caterpillarHead.isEqual(strawberry);
}

// Gets width
int GameField::getWidth() const {
    return width;
}

// Gets height
int GameField::getHeight() const {
    return height;
}
