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
    if(game.get_reward() != 1){
        cout << "<p" << (game.get_current_player()) -> get_player_ID() <<"> melakukan DOUBLE! Poin hadiah naik dari " << game.get_reward() << " menjadi " << (game.get_reward() << 1) << endl;
        game.set_reward(game.get_reward()*2);
    }
    else{
        cout << "<p" << (game.get_current_player()) -> get_player_ID() <<"> melakukan DOUBLE! Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah.. Giliran dilanjut!"  << endl;
    }
    
    game.theQueue->dequeue();
}

// int Double::cln(){
//     return 1;
// }