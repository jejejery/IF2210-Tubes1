#define GAMESTATE_HPP_
#ifdef GAMESTATE_HPP_

#include "../deck/deck.hpp"
#include "../card/card.hpp"
#include "../InventoryHolder/player/player.hpp"
#include "../InventoryHolder/TableCard/TableCard.hpp"
#include "../action/action.hpp"

#include "../myqueue/myqueue.hpp"

// #include "../card/gamecard/gamecard.hpp"
// #include "../card/combinationcard/combinationcard.hpp"
// #include "../card/abilitycard/abilitycard.hpp"

class GameState{
    private:
    int permainan_ke;
    int round;
    int reward;

    Deck theDeck;
    myQueue<int> theQueue;
    vector<Player*> thePlayers;
    //CombinationCard theCombination;



    public:
    GameState(); //ctor
    ~GameState(); //dtor

    friend class Action;




};

/*
Atribut:
+ int permainan_ke
+ int round
+ int reward

+ deck gamecard(array of gamecard)
+ queue of player turn
+ array of player
+ Combo
+ table card
+ friend class action



*/

#endif