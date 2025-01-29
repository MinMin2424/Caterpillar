//
// Created by minat on 25.10.2024.
//

#include "Renderer.hpp"
#include "../model/Point.hpp"
#include "../model/Caterpillar.hpp"
#include "../model/GameField.hpp"
#include <iostream>
using namespace std;

void Renderer::drawField(const GameField &field, const Caterpillar &caterpillar) {

    int width = field.getWidth(); // Get the width of the game field
    int height = field.getHeight(); // Get the height of the game field
    Point cabbagePosition = field.getCabbage(); // Get the position of the cabbage

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Point position(x, y); // Create a Point for the current position

            if (position.isEqual(caterpillar.getHead())) {
                cout << 'O'; // Draw the head of the caterpillar

            } else {
                // Check if the point position is part of the caterpillar's body
                bool isInCaterpillar = false;
                for (const auto &caterpillar_part : caterpillar.getBody()) {
                    if (caterpillar_part.isEqual(position)) {
                        isInCaterpillar = true;
                        break;
                    }
                }
                if (isInCaterpillar) {
                    cout << 'o'; // Draw the body of the caterpillar
                } else if (position.isEqual((cabbagePosition))) {
                    cout << '*'; // Draw the cabbage
                } else {
                    cout << '.'; // Draw empty space
                }
            }
        }
        cout << endl;
    }
}
