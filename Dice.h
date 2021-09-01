#include <iostream>
#include <ctime>
#include <random>

class Dice
{
public:
    Dice(int face);

    virtual int roll();

    inline int getFace()
    {
        return max;
    }

private:
    int max{0};
    std::random_device rd;
    std::mt19937 rng;
    std::uniform_int_distribution<int> dice;
};
