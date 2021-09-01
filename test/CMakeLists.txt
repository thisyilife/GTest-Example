cmake_minimum_required(VERSION 3.0.0) 

include_directories(${PROJECT_SOURCE_DIR}/googletest/include)

add_executable(DiceTest testDice.cpp)
target_link_libraries(DiceTest PRIVATE gtest DiceGame)