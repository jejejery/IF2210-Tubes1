#include "player.hpp"

#include <iostream>
#include <vector>

using namespace std;

Player::Player():InventoryHolder(2){
    this->player_ID = 0;
    this->AbilityState = false;
    this->the_score = 0;
    this->action_name = "NONE";
} //default ctor

Player::Player(uint16_t ID):InventoryHolder(2){
    this->player_ID = ID;
    this->AbilityState = false;
    this->the_score = 0;
    this->action_name = "NONE";
};

Player::Player(const Player& p){
    this->player_ID = p.player_ID;
    this->theAbilityCard = p.theAbilityCard;
    this->AbilityState = p.AbilityState;
    this->the_score = p.the_score;
    this->action_name = p.action_name;
}; //cctor
Player::~Player(){
    delete [] this->theAbilityCard;
}; //dtor

//GETTER, SETTER
uint8_t Player::get_player_ID(){
    return this->player_ID;
};

uint8_t Player::get_num_of_cards(){
    return this->num_of_cards;
};
AbilityCard* Player::get_theAbilityCard(){
    return this->theAbilityCard;
};

bool Player::getAbilityState(){
    return this->AbilityState;
};
uint64_t Player::get_the_score(){
    return this->the_score;
};
string Player::get_action_name(){
    return this->action_name;
};

void Player::setAbilityState(bool b){
    this->AbilityState = b;
};
void Player::setAbility(AbilityCard ac){
    this->theAbilityCard = &ac;
};
void Player::setScore(uint64_t sc){
    this->the_score = sc;
};
void Player::set_action_name(string an){
    this->action_name = an;
};

void Player::set_player_card(int i,GameCard* gc){
    this->cardbuffer[i] = gc;
}

void Player::debug(){
    cout << "ID Player: " << this->player_ID << endl;
    cout << "Kartu Pertama: " << *(this->cardbuffer[0]) << endl;
    cout << "Kartu Kedua: " << *(this->cardbuffer[1]) << endl;
    // cout << "Ability Card: " << *(this->theAbilityCard) << endl;
    cout << "Aksi: " << this->action_name << endl;
}