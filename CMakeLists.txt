cmake_minimum_required(VERSION 3.0.0) 
project(DiceGame VERSION 0.1.0)

enable_testing()

add_subdirectory(googletest)
add_library(DiceGame Dice.cpp)
add_subdirectory(test)
include_directories(googletest/include)

add_executable(main DiceGame.cpp)
target_link_libraries(main DiceGame)
