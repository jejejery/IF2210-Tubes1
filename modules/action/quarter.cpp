#include "quarter.hpp"
#include "../gamestate/gamestate.hpp"
#include <iostream>

using namespace std;

Quarter :: Quarter() : Action() {

}

Quarter :: ~Quarter() {

}

void Quarter :: execute_action(GameState& game) 
{
    uint64_t newReward = game.get_reward() / 4;
    if(newReward >= 1)
    {
        game.set_reward(newReward);
    }else
    {
        game.set_reward(1);
    }   
}
