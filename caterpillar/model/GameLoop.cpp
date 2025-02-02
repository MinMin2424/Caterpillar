//
// Created by minat on 25.10.2024.
//

#include "GameLoop.hpp"
#include "Caterpillar.hpp"
#include "GameField.hpp"

#include <iostream>
#include <thread>
#include <ncurses.h>

#include "../inputHandler/InputHandler.hpp"
#include "../inputHandler/InputHandler_Linux.hpp"
#include "../render/Renderer.hpp"
using namespace std;

/**
 * The main game loop function that handles the game logic and rendering.
 *
 * This function repeatedly calls the rendering and input handling functions, moves the caterpillar,
 * checks for collisions, and updates the game field during each game tick.
 */
void GameLoop::gameLoop() {

    Caterpillar caterpillar(5, 5, UP);
    GameField game_field(40, 10, caterpillar);
    Renderer renderer;
    InputHandler_Linux input_handler;
    bool gameRunning = true;

    const int tick_duration_ms = 500;
    auto last_move_time = chrono::steady_clock::now();

    system("clear");

    while (gameRunning) {

        renderGameLoop(game_field, caterpillar, renderer);

        // InputHandler::handleInput(caterpillar);
        input_handler.handleInput(caterpillar);

        auto current_time = chrono::steady_clock::now();
        auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(current_time - last_move_time);

        if (elapsed_time.count() >= tick_duration_ms) {
            moveCaterpillar(game_field, caterpillar, gameRunning);
            last_move_time = current_time;
        }
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

/**
 * Method to move the caterpillar based on its direction and check for collisions or food consumption.
 *
 * @param game_field The game field object, used to check for cabbage and strawberry positions,
 * and place new food items.
 * @param caterpillar The caterpillar object, which moves and grows depending on the food eaten.
 * @param gameRunning A reference to a boolean flag indicating if the game is still running.
 */
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
        caterpillar.loseLife();
        if (caterpillar.getLives() <= 0) {
            cout << "Game over!" << endl;
            gameRunning = false;
        }
    }

    if (game_field.isCabbageEaten(caterpillar.getHead())) {
        caterpillar.grow(CABBAGE);
        game_field.placeCabbage(caterpillar);

    } else if (game_field.isStrawberryEaten(caterpillar.getHead())) {
        caterpillar.grow(STRAWBERRY);
        game_field.placeStrawberry(caterpillar);
    }

}

/**
 * Method to render the game field, displaying the score and lives,and drawing the game state.
 *
 * @param game_field The game field object, used for rendering the game objects.
 * @param caterpillar The caterpillar object, used for rendering the caterpillar.
 * @param renderer The renderer object, which is used to draw the game state on screen.
 */
void GameLoop::renderGameLoop(GameField &game_field, Caterpillar &caterpillar, Renderer &renderer) {

    cout << "\033[H";
    cout << "Score: " << caterpillar.getScore() << "; Lives ♥ : " << caterpillar.getLives() << endl;
    cout << "Collect cabbage for 1 point!!!" << endl;
    cout << "Collect strawberry for 2 points!!!" << endl;
    renderer.drawField(game_field, caterpillar);

}