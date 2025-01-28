//
// Created by minat on 25.10.2024.
//

#include "GameLoop.hpp"
#include "Caterpillar.hpp"
#include "GameField.hpp"

#include <iostream>
#include <unistd.h>
using namespace std;

void gameLoop() {
    GameField game_field(20, 20);
    Caterpillar caterpillar(10, 10, UP);

    while (true) {

        if (caterpillar.checkCollision(game_field.getWidth(), game_field.getHeight())) {
            cout << "Caterpillar collision" << endl;
            cout << "Game over!" << endl;
            break;
        }

        if (game_field.isCabbageEaten(caterpillar.getHead())) {
            caterpillar.grow();
            cout << "Caterpillar grow" << endl;
            game_field.placeCabbage();
        }
        usleep(200000);
    }
}
