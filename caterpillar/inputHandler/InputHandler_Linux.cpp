//
// Created by minat on 13.11.2024.
//

#include "InputHandler_Linux.hpp"
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <termios.h>
using namespace std;


/**
 * This method reads a single character input from the user without waiting for Enter.
 * It configures the terminal to disable canonical mode and echoing,
 * so the input is received immediately without needing to press Enter,
 * and the character is not echoed to the screen.
 *
 * @return char The character entered by the user.
 */
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

/**
 * Processes the user's input to update the caterpillar's movement direction.
 * The direction is determined based on the character entered ('w', 'a', 's', 'd').
 * If the user inputs 'q', the program exists.
 * Invalid input results in an error message.
 *
 * @param caterpillar The caterpillar whose direction will be updated based on input.
 */

void InputHandler_Linux::handleInput(Caterpillar &caterpillar) {

    char input = getInput();

    if (input == '\0') {
        cout << "Input is empty" << endl;
    }

    switch (input) {
        case 'w': // UP
            caterpillar.setDirection(UP);
            break;
        case 's': // DOWN
            caterpillar.setDirection(DOWN);
            break;
        case 'a': // LEFT
            caterpillar.setDirection(LEFT);
            break;
        case 'd': // RIGHT
            caterpillar.setDirection(RIGHT);
            break;
        case 'q':
            cout << "Quit" << endl;
            exit(0);
    }

}

