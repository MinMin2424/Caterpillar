//
// Created by minat on 03.11.2024.
//

#include "InputHandler.hpp"

#include <iostream>
using namespace std;

// Method to get a single character input from the user
char InputHandler::getInput() {
    char ch;
    cout << "Please enter direction: ";
    cin >> ch;
    return ch;
}

// Method to handle user input and update the caterpillar's direction
void InputHandler::handleInput(Caterpillar &caterpillar) {

    switch (getInput()) {
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
        default:
            cout << "Invalid Input" << endl;
        break;
    }
}
