// #include "../modules/card/card.hpp"
#include "../modules/card/card.cpp"
// #include "../modules/card/gamecard/gamecard.hpp"
#include "../modules/card/gamecard/gamecard.cpp"
// #include "../modules/card/abilitycard/abilitycard.hpp"
#include "../modules/card/abilitycard/abilitycard.cpp"
// #include "../modules/card/combinationcard/combinationcard.hpp"
// #include "../modules/card/combinationcard/combinationcard.cpp"


// #include "../modules/InventoryHolder/inventoryholder.hpp"
#include "../modules/InventoryHolder/inventoryholder.cpp"
// #include "../modules/InventoryHolder/player/player.hpp"
#include "../modules/InventoryHolder/player/player.cpp"
// #include "../modules/InventoryHolder/TableCard/TableCard.hpp"
#include "../modules/InventoryHolder/TableCard/TableCard.cpp"


// #include "../modules/deck/deck.hpp"
#include "../modules/deck/deck.cpp"

// #include "../modules/myqueue/myqueue.hpp"

// #include "../modules/gamestate/gamestate.hpp"
#include "../modules/gamestate/gamestate.cpp"

#include <iostream>
using namespace std;

int main(){
    GameState* gs = new GameState();
    gs->debug();
    gs->reset_permainan();
    gs->debug();
    return 0;
}