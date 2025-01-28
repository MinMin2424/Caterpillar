//
// Created by minat on 25.10.2024.
//

#ifndef POINT_H
#define POINT_H

class Point {

public:
    int x;
    int y;

    explicit Point(int x = 0, int y = 0);
    [[nodiscard]] bool isEqual(const Point &other) const;
    [[nodiscard]] bool isNotEqual(const Point &other) const;
    void move(int dx, int dy);

};

#endif //POINT_H

