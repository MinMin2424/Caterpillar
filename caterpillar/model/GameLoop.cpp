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
 * This method continuously checks for user input and updates the caterpillar's state.
 *
 * @param input_handler The object responsible for handling input from the user.
 * @param caterpillar The caterpillar object that gets updated based on the input.
 * @param gameRunning A reference to the game's running state (bool).
 */
void GameLoop::inputThread(InputHandler_Linux &input_handler, Caterpillar &caterpillar, bool &gameRunning) {
    while (gameRunning) {
        input_handler.handleInput(caterpillar);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

/**
 * This method repeatedly renders the game field and updates the display,
 * showing the caterpillar and other game elements.
 *
 * @param renderer The object responsible for rendering the game.
 * @param game_field The game field containing the layout of the game.
 * @param caterpillar The caterpillar object that is being drawn.
 * @param gameRunning A reference to the game's running state (bool).
 */
void GameLoop::renderThread(Renderer &renderer, GameField &game_field, Caterpillar &caterpillar, bool &gameRunning) {
    while (gameRunning) {
        renderGameLoop(game_field, caterpillar, renderer);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

/**
 * This method checks if the appropriate amount of time has passed between moves
 * and updates the caterpillar's position, handles collisions,
 * and updates the score based on what the caterpillar eats.
 *
 * @param game_field The game field containing the layout od the game.
 * @param caterpillar The caterpillar object whose position is updated.
 * @param gameRunning A reference to the game's running state (bool).
 * @param tickDurationMs The time interval (in milliseconds) between each game logic update.
 */
void GameLoop::gameLogicThread(GameField &game_field, Caterpillar &caterpillar, bool &gameRunning, int &tickDurationMs) {
    auto last_move_time = chrono::steady_clock::now();
    while (gameRunning) {
        auto current_time = chrono::steady_clock::now();
        auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(current_time - last_move_time);
        if (elapsed_time.count() >= tickDurationMs) {
            moveCaterpillar(game_field, caterpillar, gameRunning);
            last_move_time = current_time;
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

/**
 * The main game loop that starts the threads and controls the flow of the game.
 * This method initializes the game objects and starts the input, render, and game logic threads.
 */
void GameLoop::gameLoop() {
    Caterpillar caterpillar(5, 5, UP);
    GameField game_field(40, 20, caterpillar);
    Renderer renderer;
    InputHandler_Linux input_handler;
    bool gameRunning = true;
    int tickDurationMs = 500;

    system("clear");

    thread input_thread(inputThread, ref(input_handler), ref(caterpillar), ref(gameRunning));
    thread render_thread(renderThread, ref(renderer), ref(game_field), ref(caterpillar), ref(gameRunning));
    thread game_logic_thread(gameLogicThread, ref(game_field), ref(caterpillar), ref(gameRunning), ref(tickDurationMs));

    input_thread.join();
    render_thread.join();
    game_logic_thread.join();
}

/**
 * This method calculates the new position of the caterpillar
 * based on its direction and updates its position.
 *
 * @param game_field The game field where the caterpillar moves.
 * @param caterpillar The caterpillar object that is being moved.
 * @param gameRunning A reference to the game's running state (bool).
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
 * This method updates the console with the current score, lives, game instructions,
 * and then draws the game field.
 *
 * @param game_field The game field to be rendered.
 * @param caterpillar The caterpillar object to be drawn.
 * @param renderer The renderer object responsible for drawing the game.
 */
void GameLoop::renderGameLoop(GameField &game_field, Caterpillar &caterpillar, Renderer &renderer) {

    cout << "\033[H";
    cout << "Score: " << caterpillar.getScore() << "; Lives ❤️ : " << caterpillar.getLives() << endl;
    cout << "Collect cabbage 🥬 for 1 point!!!" << endl;
    cout << "Collect strawberry 🍓 for 2 points!!!" << endl;
    renderer.drawField(game_field, caterpillar);

}