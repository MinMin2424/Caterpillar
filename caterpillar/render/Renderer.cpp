//
// Created by minat on 25.10.2024.
//

#include "Renderer.hpp"
#include "../model/Point.hpp"
#include "../model/Caterpillar.hpp"
#include "../model/GameField.hpp"
#include <iostream>
using namespace std;

#define ANSI_COLOR_RESET "\x1B[0m"
#define ANSI_FOREGROUND(color) "\x1B[38;5;" #color "m"
#define ANSI_BACKGROUND(color) "\x1B[48;5;" #color "m"
#define ANSI_BOLD "\x1B[1m"

#define HEAD_BODY_BG ANSI_BACKGROUND(193)
#define STRAWBERRY_BG ANSI_BACKGROUND(193)
#define CABBAGE_BG ANSI_BACKGROUND(193)
#define BOMB_BG ANSI_BACKGROUND(193)
#define EMPTY_FG ANSI_FOREGROUND(16)
#define EMPTY_BG ANSI_BACKGROUND(193)

/**
 * Method to render the game field by printing its content to the console.
 *
 * @param field The game field that contains the positions of the cabbage, strawberry, and boundaries.
 * @param caterpillar The caterpillar whose head and body positions will be drawn.
 */
void Renderer::drawField(const GameField &field, const Caterpillar &caterpillar) {

    int width = field.getWidth();
    int height = field.getHeight();
    Point cabbagePosition = field.getCabbage();
    Point strawberryPosition = field.getStrawberry();
    Point bombPosition = field.getBomb();

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Point position(x, y);

            if (position.isEqual(caterpillar.getHead())) {
                cout << HEAD_BODY_BG << "🟢" << ANSI_COLOR_RESET;
            }
            else if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                cout << EMPTY_BG << "🧱" << ANSI_COLOR_RESET;

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
                    cout << HEAD_BODY_BG << "🟡" << ANSI_COLOR_RESET;

                } else if (position.isEqual((cabbagePosition))) {
                    cout << CABBAGE_BG << "🥬" << ANSI_COLOR_RESET;

                } else if (position.isEqual(strawberryPosition)) {
                    cout << STRAWBERRY_BG << "🍓" << ANSI_COLOR_RESET;

                } else if (position.isEqual(bombPosition)) {
                    cout << BOMB_BG << "💣" << ANSI_COLOR_RESET;

                } else {
                    cout << EMPTY_BG << EMPTY_FG << ANSI_BOLD << " ." << ANSI_COLOR_RESET;

                }
            }
        }
        cout << endl;
    }
}

