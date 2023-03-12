#include "card.hpp"
#include <iostream>
using namespace std;


/*
==========================CARD==========================
*/

Card::Card(){};
Card::~Card(){};
int Card::value() const{return 0xDEAD;}



/*
==========================GAME CARD==========================
*/

//Constructor
GameCard::GameCard(int num, string col) : Card(),number(num),color(col){}

// destructor
GameCard::~GameCard(){}
// getter
int GameCard::get_number() const{
    return this->number;
};
string GameCard::get_color() const{
    return this->color;
}
// setter
void GameCard::set_number(int n){
    this->number = n;
}
void GameCard::set_color(string c){
    this->color = c;
}

ostream& operator<<(ostream& os,const GameCard& gc) {
          os << gc.get_number() << ' ' << gc.get_color(); 
          return os; 
    }

int GameCard::value() const{
    return 0xBEEF;
}


/*
==========================ABILITY CARD==========================
*/

// constructor

AbilityCard::AbilityCard(string ab):Card(),ability(ab){}
// destructor
AbilityCard::~AbilityCard(){}
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