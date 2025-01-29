//
// Created by minat on 25.10.2024.
//

#include "GameLoop.hpp"
#include "Caterpillar.hpp"
#include "GameField.hpp"

#include <iostream>
#include <thread>
#include <unistd.h>
#include "../inputHandler/InputHandler.hpp"
#include "../render/Renderer.hpp"
using namespace std;

void gameLoop() {
    GameField game_field(40, 10);
    Caterpillar caterpillar(5, 5, UP);
    Renderer renderer;

    cout << "START GAME!" << endl;

    while (true) {

        cout << "Score: " << caterpillar.getScore() << endl;
        renderer.drawField(game_field, caterpillar);

        InputHandler::handleInput(caterpillar);

        int dx = 0, dy = 0;
        switch (caterpillar.getDirection()) {
            case UP: dy = -1; break;
            case DOWN: dy = 1; break;
            case LEFT: dx = -1; break;
            case RIGHT: dx = 1; break;
        }
        caterpillar.move(dx, dy);

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
        // usleep(200000);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}
