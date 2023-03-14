#include "half.hpp"
#include "../gamestate/gamestate.hpp"

using namespace std;

Half :: Half() : Action()
{

}

Half :: ~Half()
{

}

void Half :: execute_action(GameState& game)
{   
    uint64_t newReward = game.get_reward() / 2;
    if(newReward >= 1)
    {
        game.set_reward(newReward);
    }else
    {
        game.set_reward(1);
    }

}