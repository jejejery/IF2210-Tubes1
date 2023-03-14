#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "../inventoryholder.hpp"

#include <iostream>
#include <vector>

using namespace std;

class Player : public InventoryHolder {
    private:
    uint16_t player_ID;
    AbilityCard* theAbilityCard;
    bool AbilityState;
    uint64_t the_score;
    string action_name;
    

    
    
    public:
    Player(); //default ctor
    Player(uint16_t); //default parameter ctor
    Player(const Player&); //cctor
    ~Player(); //dtor

    //GETTER, SETTER
    int get_num_of_cards() const override;

    uint8_t get_player_ID() const;
    AbilityCard* get_theAbilityCard();
    bool getAbilityState();
    uint64_t get_the_score();
    string get_action_name();
    GameCard* get_ith_card(int);

    
    void setAbilityState(bool);
    void setAbility(AbilityCard*);
    void setScore(uint64_t);
    void set_action_name(string);

    //Edit card numb
    void set_player_card(int,GameCard*);
    void add_card(GameCard*);
    void empty_cards();

    //debug
    void debug();


} ;

#endif