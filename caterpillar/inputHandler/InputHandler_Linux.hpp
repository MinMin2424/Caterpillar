//
// Created by minat on 13.11.2024.
//

#ifndef INPUTHANDLER_LINUX_HPP
#define INPUTHANDLER_LINUX_HPP
#include "../model/Caterpillar.hpp"


class InputHandler_Linux {
public:
    static char getInput();
    static void handleInput(Caterpillar& caterpillar);
};



#endif //INPUTHANDLER_LINUX_HPP
