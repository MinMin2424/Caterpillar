#include <iostream>
#include "model/Point.hpp"
using namespace std;


int main() {
    Point p1(9, 1);
    Point p2(9, 1);
    Point p3(2,4);

    if (p1.isEqual(p2)) {
        cout << "p1 and p2 are equal." << endl;
    } else {
        cout << "p1 and p2 are not equal." << endl;
    }

    if (p2.isNotEqual(p3)) {
        cout << "p2 and p3 are not equal." << endl;
    }

    p3.move(1, 1);
    cout << "After moving, p3 has coordinates: (" << p3.x << ", " << p3.y << ")" << endl;
}

