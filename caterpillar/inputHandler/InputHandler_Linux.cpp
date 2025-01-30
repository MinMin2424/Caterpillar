//
// Created by minat on 13.11.2024.
//

#include "InputHandler_Linux.hpp"

#include <iostream>
#include <unistd.h>
#include <termios.h>
using namespace std;


char InputHandler_Linux::getInput() {
    struct termios oldt, newt;
    char c;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

void InputHandler_Linux::handleInput(Caterpillar &caterpillar) {

    switch (getInput()) {
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
        default:
            cout << "Invalid Input" << endl;
        break;
    }

}
