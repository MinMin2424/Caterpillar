//
// Created by minat on 03.11.2024.
//

#include "InputHandler.hpp"

#include <iostream>
using namespace std;

/**
 * Prompts the user to enter a direction and returns the entered character.
 *
 * @return char The character entered by th user for direction input.
 */
char InputHandler::getInput() {
    char ch;
    cout << "Please enter direction: ";
    cin >> ch;
    return ch;
}

/**
 * Processes the user's input to update the caterpillar's movement direction.
 * The direction is determined based on the character entered ('w', 'a', 's', 'd').
 * If the user inputs 'q', the program exists.
 * Invalid input results in an error message.
 *
 * @param caterpillar The caterpillar whose direction will be updated based on input.
 */
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
            throw runtime_error("Quit command received");
            exit(0);
        default:
            cout << "Invalid Input" << endl;
            break;
    }

}

