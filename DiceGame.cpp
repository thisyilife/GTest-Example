#include <iostream>
#include "Dice.h"

int main()
{
    Dice d(6);
    Dice d2(20);
    std::cout << "Roll a 6 faces dice : " << d.roll() << std::endl;
    std::cout << "Roll a 20 faces dice : " << d2.roll() << std::endl;

    return 0;
}