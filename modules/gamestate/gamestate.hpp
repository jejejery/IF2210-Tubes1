#define GAMESTATE_HPP_
#ifdef GAMESTATE_HPP_

#include "../deck/deck.hpp"
#include "../card/card.hpp"
#include "../card/abilitycard/abilitycard.hpp"
#include "../card/gamecard/gamecard.hpp"
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
    uint64_t reward;

    Deck* theDeck;
    myQueue<int>* theQueue;
    vector<Player*> thePlayers;
    //CombinationCard *theCombination;
    TableCard* theTableCards;
    
    //friend class
    // friend class Action;
    // friend class Double;
    // friend class Half;
    // friend class Next;
    // friend class Abilityless;
    // friend class Quadruple;
    // friend class Quarter;
    // friend class ReRoll;
    // friend class Reverse;
    // friend class SwapCard;
    // friend class Switch;

    public:
    GameState(); //ctor
    ~GameState(); //dtor

    //SETTER GETTER

    //==============SETTER=============
    int get_permainan_ke() const;
    int get_round() const;
    uint64_t get_reward() const;

    Deck* get_theDeck() const;
    myQueue<int>* get_theQueue() const;
    vector<Player*> get_thePlayers() const;
    //CombinationCard *theCombination;
    TableCard* get_theTableCards() const;
    
    //==============GETTER=============
    void set_permainan_ke(int);
    void set_round(int);
    void set_reward(uint64_t);
    
    void set_theDeck(Deck*);
    void set_theQueue(myQueue<int>*);
    void set_thePlayers(vector<Player*>);
    //CombinationCard *theCombination;
    void set_theTableCards(TableCard*);



    //==============Method==========
    void reset_permainan(); //Reset permainan dilakukan saat selesai ronde 6 
    void restore_deck();
    void share_cards();

    void calculate_winner();
    void run_game();

    void debug();


};


#endif