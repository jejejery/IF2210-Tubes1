#include "switch.hpp"
#include "../gamestate/gamestate.hpp"
#include <iostream>

using namespace std;

Switch :: Switch() {

}

Switch :: ~Switch() {

}

void Switch :: execute_action(GameState& game) {
    Player* pl = (game.get_current_player());
    AbilityCard* ab = pl->get_theAbilityCard();
    if(ab->get_ability() != "SWITCH") throw new CommandException(1);
    if(pl->getAbilityDisable()) throw new CommandException(4);

    cout << "<p" << game.theQueue->front() << "> melakukan SWITCH." << endl;
    cout << "Kartumu sekarang adalah:" << endl;
    cout << "(" << *(pl->get_ith_card(0)) << ") && (" << *(pl->get_ith_card(1)) << ")\n";
    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
    int x = 1;
    for(int i = 1; i <= game.num_of_players; i++){
                if(game.theQueue->front() != i){
                   cout << x <<  ". <pemain_" << game.thePlayers[i-1]->get_player_ID() << ">" << endl; 
                   ++x;
                }
        }

    int switch_player;
    cin >> switch_player;
    if(switch_player < 1 || switch_player > 7 || switch_player == game.theQueue->front()) throw new IOexception(0);

    GameCard* temp;

    temp = game.thePlayers[game.theQueue->front()-1]->get_ith_card(0);
    game.thePlayers[game.theQueue->front()-1]->set_player_card(0, game.thePlayers[switch_player-1]->get_ith_card(0));
    game.thePlayers[switch_player-1]->set_player_card(0,temp);
    
    //Swap Kartu kedua
    temp = game.thePlayers[game.theQueue->front()-1]->get_ith_card(1);
    game.thePlayers[game.theQueue->front()-1]->set_player_card(1, game.thePlayers[switch_player-1]->get_ith_card(1));
    game.thePlayers[switch_player-1]->set_player_card(1,temp);

    cout << "Kedua kartu <pemain_" << switch_player << "> telah ditukar dengan <pemain_"<<game.theQueue->front() << ">!" << endl;
    cout << "Kartumu sekarang adalah:" << endl;
    cout << "(" << *(pl->get_ith_card(0)) << ") && (" << *(pl->get_ith_card(1)) << ")\n";
    
    pl->setAbilityState(false);
    game.theQueue->dequeue();

}