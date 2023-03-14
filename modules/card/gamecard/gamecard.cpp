#include "gamecard.hpp"
#include <iostream>
#include <string>

using namespace std;
/*
==========================GAME CARD==========================
*/

//Constructor
GameCard::GameCard() : Card(){
    this->card_identity.first = 0;
    this->card_identity.second = "";
}
GameCard::GameCard(int num, string col) : Card(){
    this->card_identity.first = num;
    this->card_identity.second = col;
}

// destructor
GameCard::~GameCard(){
    // cout << "GameCard " << this->get_color() << this->get_number() << " deleted" << endl;
}
// getter
int GameCard::get_number() const{
    return this->card_identity.first;
};
string GameCard::get_color() const{
    return this->card_identity.second;
}
// setter
void GameCard::set_number(int n){
    this->card_identity.first = n;
}
void GameCard::set_color(string c){
    this->card_identity.second = c;
}

ostream& operator<<(ostream& os,const GameCard& gc) {
    os << gc.get_number() << ' ' << gc.get_color(); 
    return os; 
}

bool GameCard::operator>(const GameCard& gc){
    return this->card_weight() > gc.card_weight();
}

bool GameCard::operator<(const GameCard& gc){
    return this->card_weight() < gc.card_weight();
}

bool GameCard::operator==(const GameCard& gc){
    return this->card_weight() == gc.card_weight();
}

float GameCard::card_weight() const{
    if(this->get_color() == "Hijau") return (float)this->get_number()/10;
    else if(this->get_color() == "Biru") return (float)this->get_number()/10 + 0.03;
    else if(this->get_color() == "Kuning") return (float)this->get_number()/10 + 0.06;
    else if(this->get_color() == "Merah") return (float)this->get_number()/10 + 0.09;
    else return -1;
}

int GameCard::value() const{
    return 0xBEEF;
}