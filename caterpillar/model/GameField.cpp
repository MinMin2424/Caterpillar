//
// Created by minat on 25.10.2024.
//

#include "GameField.hpp"
#include <random>

#include "Caterpillar.hpp"
using namespace std;

/**
 * Constructor to initialize the game field with the specified width, height, and caterpillar.
 * Initializes random number generation and places the cabbage and strawberry on the field
 * on a random position.
 *
 * @param width The width of the game field.
 * @param height The height of the game field.
 * @param caterpillar A reference to the caterpillar object that is placed on the game field.
 */
GameField::GameField(int width, int height, Caterpillar &caterpillar) :
    width(width), height(height),
    random(random_device{} ()),
    distributionX(0, width - 1),
    distributionY(0, height - 1)
{
    placeCabbage(caterpillar);
    placeStrawberry(caterpillar);
}

/**
 * Method to place a cabbage at a random position on the game field.
 * The cabbage will be placed at a position that is not occupied by the caterpillar or the strawberry.
 *
 * @param caterpillar The reference to the caterpillar object,
 * used to check if the cabbage position is valid.
 */
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

/**
 * Method to place a strawberry at a random position on the game field.
 * The strawberry will be placed at a position that is not occupied by the caterpillar or the cabbage.
 *
 * @param caterpillar The reference to the caterpillar object,
 * used to check if the strawberry position is valid.
 */
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

/**
 *  Method to return the position of the cabbage on the game field.
 *
 * @return Point The position of the cabbage.
 */
Point GameField::getCabbage() const {
    return cabbage;
}

/**
 *  Method to return the position of the strawberry on the game field.
 *
 * @return Point The position of the strawberry.
 */
Point GameField::getStrawberry() const {
    return strawberry;
}

/**
 * Method to check if the cabbage has been eaten by the caterpillar.
 * The cabbage is considered eaten of the head of the caterpillar is at the same position as the cabbage.
 *
 * @param caterpillarHead The current position of the caterpillar's head.
 * @return bool Returns true if the caterpillar's head is at the same position as the cabbage.
 */
bool GameField::isCabbageEaten(const Point &caterpillarHead) const {
    return caterpillarHead.isEqual(cabbage);
}

/**
 * Method to check if the strawberry has been eaten by the caterpillar.
 * The strawberry is considered eaten of the head of the caterpillar is at the same position as the strawberry.
 *
 * @param caterpillarHead The current position of the caterpillar's head.
 * @return bool Returns true if the caterpillar's head is at the same position as the strawberry.
 */
bool GameField::isStrawberryEaten(const Point &caterpillarHead) const {
    return caterpillarHead.isEqual(strawberry);
}

/**
 * Method to get the width of the game field.
 *
 * @return int The width of the game field.
 */
int GameField::getWidth() const {
    return width;
}

/**
 * Method to get the height of the game field.
 *
 * @return int The height of the game field.
 */
int GameField::getHeight() const {
    return height;
}
