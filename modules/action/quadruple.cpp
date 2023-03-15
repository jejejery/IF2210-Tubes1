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
    cout << "<p" << (game.get_current_player()) -> get_player_ID() <<"> melakukan QUADRUPLE! Poin hadiah naik dari " << game.get_reward() << " menjadi " << game.get_reward()*4 << endl;
    game.set_reward(game.get_reward()*4);
    game.theQueue->dequeue();
    game.theTableCards->addCard(game.theDeck->drawCard());
}