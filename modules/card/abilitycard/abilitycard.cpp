#include "abilitycard.hpp"

#include <iostream>
#include <string>

using namespace std;

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