//
// Created by minmin on 11/19/24.
//

#include <gtest/gtest.h>
#include "../model/Point.hpp"

TEST(PointTest, ConstrutorTest) {
    Point p(2,4);
    Point expected(2,4);
    EXPECT_TRUE(p.isEqual(expected));
}

TEST(PointTest, IsEqualTest) {
    Point p1(2,4);
    Point p2(2,4);
    Point p3(1,10);
    EXPECT_TRUE(p1.isEqual(p2));
    EXPECT_FALSE(p1.isEqual(p3));
}

TEST(PointTest, IsNotEqualTest) {
    Point p1(2,4);
    Point p2(2,4);
    Point p3(1,10);
    EXPECT_FALSE(p1.isNotEqual(p2));
    EXPECT_TRUE(p1.isNotEqual(p3));
}

TEST(PointTest, MoveTest) {
    Point p(2,4);
    Point expected1(5, 2);
    Point expected2(0, 9);

    p.move(3, -2);
    EXPECT_TRUE(p.isEqual(expected1));
    p.move(-5, 7);
    EXPECT_TRUE(p.isEqual(expected2));
}