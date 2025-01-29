//
// Created by minat on 25.10.2024.
//

#ifndef RENDERER_H
#define RENDERER_H
#include "../model/GameField.hpp"
#include "../model/Caterpillar.hpp"

class Renderer {
public:
    void drawField(const GameField& field, const Caterpillar& caterpillar);
};

#endif //RENDERER_H
