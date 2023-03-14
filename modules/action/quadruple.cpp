#include "quadruple.hpp"
#include "../gamestate/gamestate.hpp"
#include <iostream>

using namespace std;

Quadruple :: Quadruple() : Action()
{

}

Quadruple :: ~Quadruple()
{

}

void Quadruple :: execute_action(GameState& game)
{
    uint64_t newReward = game.get_reward() * 4;
    game.set_reward(newReward);
}