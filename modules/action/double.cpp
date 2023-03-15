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
{   //[(game.get_theQueue)->front()-1]
    cout << "<p" << (game.get_current_player()) -> get_player_ID() <<"> melakukan DOUBLE! Poin hadiah naik dari " << game.get_reward() << " menjadi " << game.get_reward()*2 << endl;
    game.set_reward(game.get_reward()*2);
    game.theQueue->dequeue();
}

// int Double::cln(){
//     return 1;
// }