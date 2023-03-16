
#ifndef _GAMESTATE_HPP_
#define _GAMESTATE_HPP_

#include "../deck/deck.hpp"
#include "../card/card.hpp"
#include "../card/abilitycard/abilitycard.hpp"
#include "../card/gamecard/gamecard.hpp"
#include "../InventoryHolder/player/player.hpp"
#include "../InventoryHolder/TableCard/TableCard.hpp"
#include "../card/combinationcard/combinationcard.hpp"

#include "../myqueue/myqueue.hpp"




// #include "../card/abilitycard/abilitycard.hpp"


//Forward Declaration
class Action;
class Next;
class Half;
class Double;
class Abilityless;
class Quadruple;
class Quarter;
class ReRoll;
class Reverse;
class SwapCard;
class Switch;

//GameState
class GameState{
    private:
    int permainan_ke;
    int round;
    uint64_t reward;

    Deck* theDeck;
    myQueue<int>* theQueue;
    vector<Player*> thePlayers;
    vector<AbilityCard*> theAbilities;
    vector<CombinationCard*> theCombination;
    TableCard* theTableCards;
    vector<int> futureQueue; //Saat terjadi reverse, future queue diupdate
    bool isReverse;
    
    //Konstanta, aturan game
    const uint64_t maxScore = (uint64_t(1) << 32);
    const uint16_t num_of_players = 7;
    //friend class
    friend class Action;
    friend class Double;
    friend class Half;
    friend class Next;
    friend class Abilityless;
    friend class Quadruple;
    friend class Quarter;
    friend class ReRoll;
    friend class Reverse;
    friend class SwapCard;
    friend class Switch;

    public:
    GameState(); //ctor
    GameState(string);
    ~GameState(); //dtor

    //SETTER GETTER

    //==============GETTER=============
    int get_permainan_ke() const;
    int get_round() const;
    uint64_t get_reward() const;

    Deck* get_theDeck() const;
    myQueue<int>* get_theQueue() const;
    vector<Player*> get_thePlayers() const;
    vector<CombinationCard*> get_theCombination() const;
    TableCard* get_theTableCards() const;
    Player* get_current_player() const;
    //CombinationCard *theCombination() const;

    //==============SETTER=============
    void set_permainan_ke(int);
    void set_round(int);
    void set_reward(uint64_t);
    
    void set_theDeck(Deck*);
    void set_theQueue(myQueue<int>*);
    void set_thePlayers(vector<Player*>);
    
    void set_theTableCards(TableCard*);



    //==============Method==========
    void next_round(); 
    void next_permainan(); //Reset permainan dilakukan saat selesai ronde 6 
    void restore_deck();
    void restore_queue();

    void share_ability_cards();

    void calculate_winner();
    void decide_combo();

    bool isEndgame() const;
    void theEnd();
    void debug();

};


#endif