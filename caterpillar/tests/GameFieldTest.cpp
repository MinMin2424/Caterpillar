//
// Created by minmin on 11/20/24.
//

#include <gtest/gtest.h>

#include "../model/Caterpillar.hpp"
#include "../model/GameField.hpp"

class GameFieldTest : public ::testing::Test {
protected:
    Caterpillar caterpillar{0,0,UP};
    GameField game_field{10,8, caterpillar};
};

TEST_F(GameFieldTest, Initialization) {
    EXPECT_EQ(game_field.getWidth(), 10);
    EXPECT_EQ(game_field.getHeight(), 8);
}

TEST_F(GameFieldTest, PlaceCabbage) {
    Point cabbage = game_field.getCabbage();
    for (const Point& part : caterpillar.getBody()) {
        EXPECT_FALSE(cabbage.isEqual(part));
    }
}

TEST_F(GameFieldTest, PlaceStrawberry) {
    Point strawberry = game_field.getStrawberry();
    for (const Point& part : caterpillar.getBody()) {
        EXPECT_FALSE(strawberry.isEqual(part));
    }
}

TEST_F(GameFieldTest, CabbageAndStrawberryNotOverlapping) {
    EXPECT_FALSE(game_field.getCabbage().isEqual(game_field.getStrawberry()));
}

TEST_F(GameFieldTest, CabbageEaten) {
    Point cabbage = game_field.getCabbage();
    caterpillar.move(cabbage.x - caterpillar.getHead().x, cabbage.y - caterpillar.getHead().y);
    EXPECT_TRUE(game_field.isCabbageEaten(caterpillar.getHead()));
}

TEST_F(GameFieldTest, StraweberryEaten) {
    Point strawberry = game_field.getStrawberry();
    caterpillar.move(strawberry.x - caterpillar.getHead().x, strawberry.y - caterpillar.getHead().y);
    EXPECT_TRUE(game_field.isStrawberryEaten(caterpillar.getHead()));
}

TEST_F(GameFieldTest, CabbageNotEaten) {
    Point cabbage = game_field.getCabbage();
    EXPECT_FALSE(game_field.isCabbageEaten(Point(cabbage.x + 1, cabbage.y + 1)));
}

TEST_F(GameFieldTest, StrawberryNotEten) {
    Point strawberry = game_field.getStrawberry();
    EXPECT_FALSE(game_field.isStrawberryEaten(Point(strawberry.x + 1, strawberry.y + 1)));
}

TEST_F(GameFieldTest, FoodPlacementWithinBounds) {
    Point cabbage = game_field.getCabbage();
    Point strawberry = game_field.getStrawberry();

    EXPECT_GE(cabbage.x, 0);
    EXPECT_LT(cabbage.x, game_field.getWidth());
    EXPECT_GE(cabbage.y, 0);
    EXPECT_LT(cabbage.y, game_field.getHeight());

    EXPECT_GE(strawberry.x, 0);
    EXPECT_LT(strawberry.x, game_field.getWidth());
    EXPECT_GE(strawberry.y, 0);
    EXPECT_LT(strawberry.y, game_field.getHeight());
}