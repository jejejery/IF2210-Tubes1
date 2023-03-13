#include "card.hpp"
#include <cstdlib>
#include <random>
#include <iterator>
#include <algorithm>
using namespace std;

/*
==========================CARD==========================
*/
Card::Card(){};
Card::~Card(){
    // cout << "Card deleted" << endl;
};
int Card::value() const{return 0xDEAD;}

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


/*
==========================ABILITY CARD==========================
*/

// constructor
AbilityCard::AbilityCard():Card(){
    this->ability = "NONE";
}
AbilityCard::AbilityCard(string ab):Card(){
    this->ability = ab;
}
// destructor
AbilityCard::~AbilityCard(){
    // cout << "AbilityCard deleted" << endl;
}
// getter
string AbilityCard::get_ability(){
    return this->ability;
}
// setter
void AbilityCard::set_ability(string ab){
    this->ability = ab;
}
//SPEK TUBES
int AbilityCard::value() const{
    return 0xCAFE;
}
//debug
ostream& operator<<(ostream& os, AbilityCard& ab){
    os << ab.get_ability(); 
    return os; 
}

/*
=======================COMBINATION CARD========================
*/

void CombinationCard::setValue(int val) {
    this->value = val;
}

void CombinationCard::setType(string t) {
    this->type = t;
}

int CombinationCard::getHighestCombination() {

}

double CombinationCard::getHighestCombiType() {

}

CombinationCard CombinationCard::compare() {
    
}

// --------------[ Implementation of Deck ]--------------

// --------------[ Implementation of AbilityCard ]--------------
// AbilityCard::AbilityCard(){
//     vector<string> abilities = {"Re-roll", "Quadruple", "Quarter", "Reverse Direction", "Swap Card", "Switch", "Abilityless"};
//     this->setAbilities(abilities);
// }

// AbilityCard::AbilityCard(vector<string> abilities)
// {
//     this->setAbilities(abilities);
// }

// AbilityCard::~AbilityCard(){}

// string AbilityCard::getAbility()
// {
//     string drawn = abilities.back();
//     abilities.pop_back();
//     return drawn;
// }

// void AbilityCard::setAbilities(vector<string> abilities)
// {
//     for (int i = 0; i < abilities.size(); i++){
//         this->abilities.push_back(abilities[i]);
//     }
// }

// void AbilityCard::shuffleAbilities()
// {
//     random_device rd;
//     mt19937 gen(rd());
//     shuffle(abilities.begin(), abilities.end(), gen);
// }










