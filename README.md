# GTest-Example
Basic example of Google test with VSCode. In this repository, I implemented a simple Dice using c++ uniform distribution. I added some basic test to provide an example of how to use some Google Test function with VSCode. 

To test this code sample with VSCode, be sure to clone https://github.com/google/googletest first.
The project tree should look like this :
```
└─project/
    ├─ googletest/
    ├─ test/
    ├─ CMakeLists.txt
    ├─ Dice.h
    ├─ Dice.cpp
    └─ DiceGame.cpp
```

Only basic CMake and usage is provided at the moment, but is enough to setup GoogleTest.
You should be able to compile and run the code with VSCode.

More testing cases and Mock function will be provided soon.
