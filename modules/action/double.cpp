#include "double.hpp"
#include "../gamestate/gamestate.hpp"
#include <iostream>

using namespace std;

Double :: Double() : Action()
{

}

Double :: ~Double()
{

}

void Double :: execute_action(GameState& game)
{
    uint64_t newReward = game.get_reward() * 2;
    game.set_reward(newReward);
}