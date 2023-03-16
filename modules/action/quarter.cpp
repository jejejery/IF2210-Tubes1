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
    Player* currentPlayer = game.get_current_player();
    AbilityCard* ab = currentPlayer->get_theAbilityCard();
    if(ab->get_ability() != "QUARTER") throw new CommandException(1);
    if(!currentPlayer->getAbilityState()) throw new CommandException(3);
    if(currentPlayer->getAbilityDisable()) throw new CommandException(4);
   
    

    if(game.get_reward() >= 4){
        cout << "<p" << ( game.get_current_player()  ) -> get_player_ID() <<"> melakukan QUARTER! Poin hadiah turun dari " << game.get_reward() << " menjadi " << (game.get_reward() >> 2) << endl;
        game.set_reward(game.get_reward() >> 2);
    }
    else{
        cout << "<p" << (game.get_current_player()) -> get_player_ID() <<"> melakukan QUARTER! Sayangnya poin hadiah sudah bernilai 1 atau 2. Poin hadiah tidak berubah.. Giliran dilanjut!"  << endl;
   }

    currentPlayer->setAbilityState(false);
    game.theQueue->dequeue();
}
