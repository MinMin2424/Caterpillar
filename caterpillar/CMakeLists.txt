cmake_minimum_required(VERSION 3.28)
project(caterpillar)

set(CMAKE_CXX_STANDARD 20)

add_executable(caterpillar main.cpp
        model/Caterpillar.cpp
        model/Caterpillar.hpp
        model/GameField.cpp
        model/GameField.hpp
        model/GameLoop.cpp
        model/GameLoop.hpp
        model/Point.cpp
        model/Point.hpp
        render/Renderer.cpp
        render/Renderer.hpp
        inputHandler/InputHandler.cpp
        inputHandler/InputHandler.hpp
        inputHandler/InputHandler_Linux.cpp
        inputHandler/InputHandler_Linux.hpp)
