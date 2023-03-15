#include "player.hpp"

#include <iostream>
#include <vector>

using namespace std;

Player::Player():InventoryHolder(2){
    this->player_ID = 0;
    this->theAbilityCard = new AbilityCard();
    this->AbilityState = false;
    this->the_score = 0;
    this->action_name = "NONE";
} //default ctor

Player::Player(uint16_t ID):InventoryHolder(2){
    this->player_ID = ID;
    this->theAbilityCard = new AbilityCard();
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
    delete  this->theAbilityCard;
}; //dtor

//GETTER, SETTER
uint8_t Player::get_player_ID() const{
    return this->player_ID;
};

int Player::get_num_of_cards() const {
    return this->num_of_cards;
}
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

GameCard* Player::get_ith_card(int i){
    return this->cardbuffer[i];
}
void Player::setAbilityState(bool b){
    this->AbilityState = b;
};
void Player::setAbility(AbilityCard* ac){
    this->theAbilityCard = ac;
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

//Assignment
bool Player::operator>(const Player& p){
    return this->the_score > p.the_score;
}
bool Player::operator<(const Player& p){
    return this->the_score < p.the_score;
}
bool Player::operator==(const Player& p){
    return this->the_score == p.the_score;
}

    
void Player::operator+(GameCard* gc){
    add_card(gc);
}

GameCard* Player::operator-(){
    GameCard* gc = this->cardbuffer.front();
    this->cardbuffer.erase(this->cardbuffer.begin());
    return gc;
};

void Player::add_card(GameCard* gc){
    // cout << *gc << endl;
    this->cardbuffer.push_back(gc);
}

void Player::empty_cards()
{
    this->cardbuffer.resize(0);
}
void Player::debug(){
    cout << "ID Player: " << this->player_ID << endl;
    cout << "Ukuran Buffer: " << this->cardbuffer.size() << endl;
    cout << "Kartu Pertama: " << *(this->cardbuffer[0]) << endl;
    cout << "Kartu Kedua: " << *(this->cardbuffer[1]) << endl;
    cout << "Ability Card: " << *(this->theAbilityCard) << endl;
    cout << "Skor Player: " << this->the_score << endl;
    cout << "Aksi: " << this->action_name << endl;
}