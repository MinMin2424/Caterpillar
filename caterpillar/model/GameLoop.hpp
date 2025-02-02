//
// Created by minat on 25.10.2024.
//

#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "Caterpillar.hpp"
#include "GameField.hpp"
#include "../render/Renderer.hpp"
#include <atomic>

#include "../inputHandler/InputHandler_Linux.hpp"

void gameLoop();

class GameLoop {
private:
    static void moveCaterpillar(GameField &game_field, Caterpillar &caterpillar, bool &gameRunning);
    static void renderGameLoop(GameField &game_field, Caterpillar &caterpillar, Renderer &renderer);
    static void inputThread(InputHandler_Linux &input_handler, Caterpillar &caterpillar, bool &gameRunning);
    static void renderThread(Renderer &renderer, GameField &game_field, Caterpillar &caterpillar, bool &gameRunning);
    static void gameLogicThread(GameField &game_field, Caterpillar &caterpillar, bool &gameRunning, int &tickDurationMs);
public:
    static void gameLoop();
};


#endif //GAMELOOP_H
