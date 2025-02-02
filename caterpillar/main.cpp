#include <iostream>

#include "help/Help.hpp"
#include "model/GameLoop.hpp"
using namespace std;


int main(int argc, char *argv[]) {
    if (argc > 1) {
        string arg = argv[1];
        if (arg == "--help") {
            Help::printHelp();
            return 0;
        }
    }
    GameLoop::gameLoop();
    return 0;
}
