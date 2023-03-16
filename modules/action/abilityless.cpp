#include "abilityless.hpp"
#include "../gamestate/gamestate.hpp"

using namespace std;

Abilityless :: Abilityless() : Action() {
    
}

Abilityless :: ~Abilityless() {

}

void Abilityless :: execute_action(GameState& game) {
    Player *curr = game.get_current_player();
    AbilityCard *card = curr->get_theAbilityCard();
    string ability = card->get_ability();
    
    if(!curr->getAbilityState()) throw new CommandException(3);

    if(ability == "ABILITYLESS")
    { // jika player memang punya kartu abilityless
        bool allUsed = true;
        for(int i = 0; i < game.num_of_players; i++)
        {
            if(game.thePlayers[i]->get_player_ID() != curr->get_player_ID())
            {
                if(!(game.thePlayers[i]->getAbilityState()) && (i+1) != curr->get_player_ID()) // belum semua player memakai abilitynya
                {
                    allUsed = false;
                }

            }
        }

        if(!allUsed)
        {   
            int x = 1;
            cout << "Pilih pemain yang kartu abilitynya ingin dimatikan: " << endl;
            for(int i = 1; i <= game.num_of_players; i++){
                if(game.theQueue->front() != i){
                   cout << x <<  ". <pemain_" << game.thePlayers[i-1]->get_player_ID() << ">" << endl; 
                   ++x;
                }
            }

            int the_input;
            cin >> the_input;
            //invalid input, throw
            if(!(the_input <= game.num_of_players && the_input <= game.num_of_players >= 1) || the_input == game.theQueue->front()){
                throw new IOexception(0);
            }
            if( !game.thePlayers[the_input-1]->getAbilityDisable())
                 game.thePlayers[the_input-1]->setAbilityDisable(true);
            else{
                 cout << "Kartu ability <pemain_" << game.thePlayers[the_input-1]->get_player_ID() <<"> telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia 🙁" << endl;
            }
           
            curr->setAbilityState(false);
            game.theQueue->dequeue();

            // Kartu ability <pemain_5> telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia 🙁
        
        }else
        {
            throw new CommandException(2);// throw semua orang sudah pake ability nya
        }
    }else
    {
        throw new CommandException(1);// throw kamu tidak punya ability ini
    }
}
