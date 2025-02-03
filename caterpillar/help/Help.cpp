//
// Created by minat on 22.11.2024.
//

#include <iostream>
#include "Help.hpp"
using namespace std;

void Help::printHelp() {
    cout << "Welcome to the Caterpillar game 🐛 !" << endl;
    cout << "Instructions for playing the game:" << endl;
    cout << "1. Use the WASD keys to control the caterpillar:" << endl;
    cout << "    - W: Move up" << endl;
    cout << "    - A: Move left" << endl;
    cout << "    - S: Move down" << endl;
    cout << "    - D: Move right" << endl;
    cout << "2. Eat cabbage 🥬 to score 1 point!" << endl;
    cout << "3. Eat strawberry 🍓 to score 2 points!" << endl;
    cout << "4. Avoid hitting the walls 🧱 or your own body!" << endl;
    cout << "5. Don't touch bomb 💣!" << endl;
    cout << "6. You have 5 ❤️ lives. If you lose all your lives, the game is over!" << endl;
    cout << "7. Press 'Q' to quit the game anytime!" << endl;
    cout << "For more information, visit the game documentation." << endl;
}