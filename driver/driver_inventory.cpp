// #include "../modules/card/card.hpp"
#include "../modules/card/card.cpp"
// #include "../modules/card/gamecard/gamecard.hpp"
#include "../modules/card/gamecard/gamecard.cpp"
// #include "../modules/card/abilitycard/abilitycard.hpp"
#include "../modules/card/abilitycard/abilitycard.cpp"
// #include "../modules/card/combinationcard/combinationcard.hpp"
// #include "../modules/card/combinationcard/combinationcard.cpp"

#include "../modules/InventoryHolder/inventoryholder.cpp"
// #include "../modules/InventoryHolder/player/player.hpp"
#include "../modules/InventoryHolder/player/player.cpp"
// #include "../modules/InventoryHolder/TableCard/TableCard.hpp"
#include "../modules/InventoryHolder/TableCard/TableCard.cpp"

#include "../modules/deck/deck.cpp"

#include <iostream>
using namespace std;

int main(){
    // InventoryHolder iv1(2);
    Deck *theDeck = new Deck();
    Player *p1 = new Player(10);
    AbilityCard *ab1 = new AbilityCard("Quater");
    p1->setAbility(ab1);
    Player *p2 = new Player(11);
    p1->add_card(new GameCard());
    p1->add_card(new GameCard());
    p2->add_card(new GameCard());
    p2->add_card(new GameCard());
    p1->debug();
    p2->debug();
    cout << "ISI DEK SEBELUM SWAP: \n\n";
    theDeck->debug();
    cout << endl;

    cout << "ISI DEK SETELAH SWAPPING: \n\n";
    theDeck->shuffleDeck();
    theDeck->shuffleDeck();
    theDeck->shuffleDeck();
    theDeck->debug();

    GameCard* g1;
    cout << "Ukuran sekarang: " << theDeck->deckSize() << endl;
    g1 = theDeck->drawCard();
    GameCard *g2 = theDeck->drawCard();
    

    TableCard *t1 = new TableCard();
    t1->debug();
    t1->addCard(theDeck->drawCard());

    cout << "Ukuran sekarang: " << theDeck->deckSize() << endl;
    cout << "Kartu yang baru keluar: " << *g1 << ' ' << *g2 << endl;
    
    t1->debug();
    delete p1;
    delete p2;
    delete theDeck;

    return 0;
}