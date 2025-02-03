#include <iostream>

#include "help/Help.hpp"
#include "model/GameLoop.hpp"
using namespace std;


int main(int argc, char *argv[]) {

    int width = 40;
    int height = 20;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--help") {
            Help::printHelp();
            return 0;
        }
        if (arg == "-w" && i + 1 < argc) {
            width = atoi(argv[++i]);
        } else if (arg == "-h" && i + 1 < argc) {
            height = atoi(argv[++i]);
        } else {
            cerr << "Invalid argument: " << arg << endl;
            return 1;
        }
    }
    GameLoop::gameLoop(width, height);
    return 0;
}
