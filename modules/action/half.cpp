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
   cout << "<p" << ( game.get_current_player()  ) -> get_player_ID() <<"> melakukan HALF! Poin hadiah turun dari " << game.get_reward() << " menjadi " << game.get_reward()/2 << endl;
   game.set_reward(game.get_reward() / 2);
   game.theQueue->dequeue();

}