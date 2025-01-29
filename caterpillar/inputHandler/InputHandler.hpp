//
// Created by minat on 03.11.2024.
//

#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP
#include "../model/Caterpillar.hpp"


class InputHandler {
public:
    static char getInput();
    static void handleInput(Caterpillar& caterpillar);
};



#endif //INPUTHANDLER_HPP
