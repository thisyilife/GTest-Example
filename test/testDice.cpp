#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "../Dice.h"

class DiceTest : public ::testing::Test
{
protected:
    Dice *m_dice;
    const int nRoll = 1000;

    DiceTest() {}

    virtual ~DiceTest() {}

    virtual void SetUp()
    {
        m_dice = new Dice(6);
    }

    virtual void TearDown()
    {
        delete m_dice;
    }
};

TEST_F(DiceTest, nFace)
{
    EXPECT_EQ(m_dice->getFace(), 6);
}

TEST_F(DiceTest, lesserOrEqThanFace)
{
    EXPECT_LE(m_dice->roll(), m_dice->getFace());
}

TEST_F(DiceTest, greatherOrEqThanOne)
{
    EXPECT_GE(m_dice->roll(), 1);
}

// To test randomness, I use the 95% prediction interval. For example, with n = 1000,
// we can expect a face to be in a interval of [i_1:i_2] (Computation detail in function).
// If it's not the case, we can assert, at a 95% rate, that the dice isn't uniformly distributed
TEST_F(DiceTest, uniformityTest)
{
    std::vector<int> rollResult;

    // Every face should appear 1/n of the time
    for (int i = 0; i < nRoll; i++)
    {
        rollResult.push_back(m_dice->roll());
    }

    const double p = 1.0 / m_dice->getFace();
    const double lesserBound = p - 1.96 * std::sqrt((1 - p) * p / nRoll);
    const double upperBound = p + 1.96 * std::sqrt((1 - p) * p / nRoll);

    for (int i = 1; i <= m_dice->getFace(); i++)
    {
        const int count = std::count(rollResult.begin(), rollResult.end(), i);
        EXPECT_LT(lesserBound * nRoll, count);
        EXPECT_GT(upperBound * nRoll, count);
    }

    // Another way to test randomness (and the good way) is to Mock the randomness.
    // Using a prediction interval of 95% does not provide a reliable test. 
}

// Test with parameter, derived from DiceTest and WithParamInterface<T>
class ParamDiceTest : public DiceTest,
                      public testing::WithParamInterface<int>
{
};

// Must be placed at global or namespace scope, not at function scope : https://google.github.io/googletest/advanced.html
// Dummy values only to provide an example
INSTANTIATE_TEST_SUITE_P(ParametrizationExample, ParamDiceTest, testing::Values(8, 10, 12));

TEST_P(ParamDiceTest, ParametrizedTestExample)
{
    EXPECT_GT(this->GetParam(), m_dice->getFace());
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}