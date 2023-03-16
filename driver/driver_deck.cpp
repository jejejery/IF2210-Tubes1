// #include "../modules/card/card.hpp"
#include "../modules/card/card.cpp"
// #include "../modules/card/abilitycard/abilitycard.hpp"
#include "../modules/card/abilitycard/abilitycard.cpp"
// #include "../modules/card/gamecard/gamecard.hpp"
#include "../modules/card/gamecard/gamecard.cpp"
// #include "../modules/deck/deck.hpp"
#include "../modules/deck/deck.cpp"
#include <iostream>
using namespace std;


int main(){
    Deck* newDeck = new Deck("test.txt");
    for (int i = 0; i < newDeck->getCards().size(); i++){
        cout << newDeck->getCards()[i]->get_color() << " ";
        cout << newDeck->getCards()[i]->get_number() << endl;
    }
    
    return 0;
}