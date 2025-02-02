cmake_minimum_required(VERSION 3.28)
project(caterpillar)

set(CMAKE_CXX_STANDARD 20)

add_executable(runGame main.cpp
        model/Point.cpp
        model/Point.hpp
        model/Caterpillar.cpp
        model/Caterpillar.hpp
        model/GameField.cpp
        model/GameField.hpp
        model/GameLoop.cpp
        model/GameLoop.hpp
        render/Renderer.cpp
        render/Renderer.hpp
        inputHandler/InputHandler.cpp
        inputHandler/InputHandler.hpp
        inputHandler/InputHandler_Linux.cpp
        inputHandler/InputHandler_Linux.hpp
        help/Help.cpp
        help/Help.hpp
)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(runTests
        tests/PointTest.cpp model/Point.hpp model/Point.cpp
        tests/CaterpillarTest.cpp model/Caterpillar.hpp model/Caterpillar.cpp
        tests/GameFieldTest.cpp model/GameField.hpp model/GameField.cpp
)

target_link_libraries(runTests GTest::GTest GTest::Main pthread)

add_test(NAME PointTest COMMAND runTests --gtest_filter=PointTest*)
add_test(NAME CaterpillarTest COMMAND runTests --gtest_filter=CaterpillarTest*)
add_test(NAME GameFieldTest COMMAND runTests --gtest_filter=GameFieldTest*)
