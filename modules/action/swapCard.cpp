#include "swapCard.hpp"
#include "../gamestate/gamestate.hpp"
#include <iostream>

using namespace std;

SwapCard :: SwapCard() : Action() {

}

SwapCard :: ~SwapCard() {

}

void SwapCard :: execute_action(GameState& game) {
    Player* pl = (game.get_current_player());
    AbilityCard* ab = pl->get_theAbilityCard();
    if(ab->get_ability() != "SWAPCARD") throw new CommandException(1);
    if(!pl->getAbilityState()) throw new CommandException(3);
    if(pl->getAbilityDisable()) throw new CommandException(4);
    

    //Algoritma Swap
    cout << "<p" << game.theQueue->front() << "> melakukan SWAPCARD." << endl;
    cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
    int x = 1;
    for(int i = 1; i <= game.num_of_players; i++){
                if(game.theQueue->front() != i){
                   cout << x <<  ". <pemain_" << game.thePlayers[i-1]->get_player_ID() << ">" << endl; 
                   ++x;
                }
        }
    int player_1;
    cin >> player_1;
    if(player_1 < 1 || player_1 > 7 || player_1 == game.theQueue->front()) throw new IOexception(0);

    cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar:" << endl;
    int y = 1;
    for(int i = 1; i <= game.num_of_players; i++){
                if(game.theQueue->front() != i && i!= player_1){
                   cout << y <<  ". <pemain_" << game.thePlayers[i-1]->get_player_ID() << ">" << endl; 
                   ++y;
                }
        }
    int player_2;
    cin >> player_2;
    if(player_2 < 1 || player_2 > 7 || player_2 == game.theQueue->front() || player_2 == player_1) throw new IOexception(0);

    int card_1,card_2;
    cout << "Silakan pilih kartu kanan/kiri pemain_" << player_1 << ":" << endl;
    cout << "1. Kanan\n2. Kiri" << endl;
    cin >> card_1;
    if(card_1 < 1 || card_1 > 2) throw new IOexception(0);

    card_1--;
    cout << "Silakan pilih kartu kanan/kiri pemain_" << player_2 << ":" << endl;
    cout << "1. Kanan\n2. Kiri" << endl;
    cin >> card_2;
    if(card_2 < 1 || card_2 > 2) throw new IOexception(0);

    card_2--;

    GameCard* temp;

    temp = game.thePlayers[player_1-1]->get_ith_card(card_1);
    game.thePlayers[player_1-1]->set_player_card(card_1, game.thePlayers[player_2-1]->get_ith_card(card_2));
    game.thePlayers[player_2-1]->set_player_card(card_2,temp);
    
    pl->setAbilityState(false);
    game.theQueue->dequeue();

}