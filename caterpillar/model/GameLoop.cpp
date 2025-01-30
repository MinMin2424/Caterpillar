//
// Created by minat on 25.10.2024.
//

#include "GameLoop.hpp"
#include "Caterpillar.hpp"
#include "GameField.hpp"

#include <iostream>
#include <thread>

#include "../inputHandler/InputHandler.hpp"
#include "../inputHandler/InputHandler_Linux.hpp"
#include "../render/Renderer.hpp"
using namespace std;

// The main game loop function that handles the game logic and rendering
void GameLoop::gameLoop() {

    Caterpillar caterpillar(5, 5, UP);
    GameField game_field(40, 10, caterpillar);
    Renderer renderer;

    bool gameRunning = true;

    // cout << "START GAME!" << endl;

    // const int tick_duration_ms = 500;
    // auto last_move_time = chrono::steady_clock::now();

    while (gameRunning) {

        renderGameLoop(game_field, caterpillar, renderer);

        // this_thread::sleep_for(std::chrono::milliseconds(100));

        // InputHandler::handleInput(caterpillar);
        InputHandler_Linux::handleInput(caterpillar);

        // auto current_time = chrono::steady_clock::now();
        // auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(current_time - last_move_time);
        //
        // if (elapsed_time.count() >= tick_duration_ms) {
        //     moveCaterpillar(game_field, caterpillar, gameRunning);
        //     last_move_time = current_time;
        // }

        moveCaterpillar(game_field, caterpillar, gameRunning);

        // this_thread::sleep_for(chrono::milliseconds(500));

    }

}

void GameLoop::moveCaterpillar(GameField &game_field, Caterpillar &caterpillar, bool &gameRunning) {

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
        gameRunning = false;
    }

    if (game_field.isCabbageEaten(caterpillar.getHead())) {
        caterpillar.grow();
        cout << "Caterpillar grow" << endl;
        game_field.placeCabbage(caterpillar);
    }

}

void GameLoop::renderGameLoop(GameField &game_field, Caterpillar &caterpillar, Renderer &renderer) {

    system("clear");
    cout << "Score: " << caterpillar.getScore() << endl;
    renderer.drawField(game_field, caterpillar);

}