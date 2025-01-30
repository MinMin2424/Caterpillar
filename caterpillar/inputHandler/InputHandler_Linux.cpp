//
// Created by minat on 13.11.2024.
//

#include "InputHandler_Linux.hpp"
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <termios.h>
using namespace std;


char InputHandler_Linux::getInput() {
    struct termios oldt, newt;
    char c = '\0';

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

    c = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, flags);
    return c;
}

void InputHandler_Linux::handleInput(Caterpillar &caterpillar) {

    char input = getInput();

    if (input == '\0') {
        cout << "Input is empty" << endl;
    }

    switch (input) {
        case 'w': // UP
            caterpillar.setDirection(UP);
        cout << "Moving UP" << endl;
        break;
        case 's': // DOWN
            caterpillar.setDirection(DOWN);
        cout << "Moving DOWN" << endl;
        break;
        case 'a': // LEFT
            caterpillar.setDirection(LEFT);
        cout << "Moving LEFT" << endl;
        break;
        case 'd': // RIGHT
            caterpillar.setDirection(RIGHT);
        cout << "Moving RIGHT" << endl;
        break;
        case 'q':
            cout << "Quit" << endl;
        exit(0);
    }

}

