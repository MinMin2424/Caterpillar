//
// Created by minmin on 11/19/24.
//

#include <gtest/gtest.h>
#include "../model/Caterpillar.hpp"
#include "../model/Point.hpp"

class CaterpillarTest : public ::testing::Test {
protected:
    Caterpillar caterpillar;
    CaterpillarTest() : caterpillar(5,5,RIGHT) {}
    void SetUp() override {
        caterpillar = Caterpillar(5,5,RIGHT);
    }
};

TEST_F(CaterpillarTest, InitialValue) {
    EXPECT_EQ(caterpillar.getHead().x, 5);
    EXPECT_EQ(caterpillar.getHead().y, 5);
    EXPECT_EQ(caterpillar.getDirection(), RIGHT);
    EXPECT_EQ(caterpillar.getScore(), 0);
    EXPECT_EQ(caterpillar.getLives(), 5);
    EXPECT_EQ(caterpillar.getBody().size(), 1);
}

TEST_F(CaterpillarTest, MoveLeft) {
    caterpillar.setDirection(LEFT);
    caterpillar.move(-1, 0);
    EXPECT_EQ(caterpillar.getHead().x, 4);
    EXPECT_EQ(caterpillar.getHead().y, 5);
    EXPECT_EQ(caterpillar.getBody().size(), 1);
}

TEST_F(CaterpillarTest, MoveRight) {
    caterpillar.move(1, 0);
    EXPECT_EQ(caterpillar.getHead().x, 6);
    EXPECT_EQ(caterpillar.getHead().y, 5);
    EXPECT_EQ(caterpillar.getBody().size(), 1);
}

TEST_F(CaterpillarTest, MoveUp) {
    caterpillar.setDirection(UP);
    caterpillar.move(0, -1);
    EXPECT_EQ(caterpillar.getHead().x, 5);
    EXPECT_EQ(caterpillar.getHead().y, 4);
    EXPECT_EQ(caterpillar.getBody().size(), 1);
}

TEST_F(CaterpillarTest, MoveDown) {
    caterpillar.setDirection(DOWN);
    caterpillar.move(0, 1);
    EXPECT_EQ(caterpillar.getHead().x, 5);
    EXPECT_EQ(caterpillar.getHead().y, 6);
    EXPECT_EQ(caterpillar.getBody().size(), 1);
}

TEST_F(CaterpillarTest, ChangeDiretion) {
    caterpillar.setDirection(UP);
    EXPECT_EQ(caterpillar.getDirection(), UP);
    caterpillar.setDirection(LEFT);
    EXPECT_EQ(caterpillar.getDirection(), LEFT);
}

TEST_F(CaterpillarTest, GrowCabbage) {
    caterpillar.grow(CABBAGE);
    EXPECT_EQ(caterpillar.getScore(), 1);
    EXPECT_EQ(caterpillar.getLives(), 5);
    EXPECT_EQ(caterpillar.getBody().size(), 2);
}

TEST_F(CaterpillarTest, GrowStrawberry) {
    caterpillar.grow(STRAWBERRY);
    EXPECT_EQ(caterpillar.getScore(), 2);
    EXPECT_EQ(caterpillar.getLives(), 5);
    EXPECT_EQ(caterpillar.getBody().size(), 2);
}

TEST_F(CaterpillarTest, CollisionWithBorder) {
    bool collision = caterpillar.checkCollision(10,10);
    EXPECT_FALSE(collision);

    caterpillar.move(5, 0);
    collision = caterpillar.checkCollision(10,10);
    EXPECT_TRUE(collision);
}

TEST_F(CaterpillarTest, CollisionWithSelf) {
    caterpillar.grow(CABBAGE);
    caterpillar.grow(STRAWBERRY);
    caterpillar.grow(CABBAGE);
    caterpillar.grow(STRAWBERRY);
    caterpillar.move(1, 0);
    caterpillar.move(0, -1);
    caterpillar.move(-1, 0);
    caterpillar.move(0, 1);
    bool collision = caterpillar.checkCollision(10,10);
    EXPECT_TRUE(collision);
}

TEST_F(CaterpillarTest, LoseFifeOnCollision) {
    caterpillar.move(5, 0);
    if (caterpillar.checkCollision(10,10)) {
        caterpillar.loseLife();
    }
    EXPECT_EQ(caterpillar.getLives(), 4);
}

TEST_F(CaterpillarTest, InvalidDirectionChange) {
    caterpillar.setDirection(UP);
    caterpillar.setDirection(DOWN);
    EXPECT_EQ(caterpillar.getDirection(), UP);
}