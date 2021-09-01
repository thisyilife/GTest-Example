#include "Dice.h"

Dice::Dice(int face) : max(face),
                       rng(rd()),
                       dice(std::uniform_int_distribution<>(1, max))
{
    rng.seed(::time(NULL));
}


int Dice::roll()
{
    return dice(rng);
}