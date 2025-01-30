//
// Created by minat on 25.10.2024.
//

#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "Caterpillar.hpp"
#include "GameField.hpp"
#include "../render/Renderer.hpp"
#include <atomic>

void gameLoop();

class GameLoop {
private:
    static void moveCaterpillar(GameField &game_field, Caterpillar &caterpillar, bool &gameRunning);
    static void renderGameLoop(GameField &game_field, Caterpillar &caterpillar, Renderer &renderer);
public:
    static void gameLoop();
};


#endif //GAMELOOP_H
