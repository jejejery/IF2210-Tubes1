// #include "../modules/card/card.hpp"
#include "../modules/card/card.cpp"
// #include "../modules/card/gamecard/gamecard.hpp"
#include "../modules/card/gamecard/gamecard.cpp"
// #include "../modules/card/abilitycard/abilitycard.hpp"
#include "../modules/card/abilitycard/abilitycard.cpp"
// #include "../modules/card/combinationcard/combinationcard.hpp"
#include "../modules/card/combinationcard/combinationcard.cpp"


// #include "../modules/InventoryHolder/inventoryholder.hpp"
#include "../modules/InventoryHolder/inventoryholder.cpp"
// #include "../modules/InventoryHolder/player/player.hpp"
#include "../modules/InventoryHolder/player/player.cpp"
// #include "../modules/InventoryHolder/TableCard/TableCard.hpp"
#include "../modules/InventoryHolder/TableCard/TableCard.cpp"


// #include "../modules/deck/deck.hpp"
#include "../modules/deck/deck.cpp"

// #include "../modules/myqueue/myqueue.hpp"

#include "../modules/gamestate/gamestate.hpp"
#include "../modules/gamestate/gamestate.cpp"

//==========ACTION========
#include "../modules/action/action.hpp"

#include "../modules/action/abilityless.hpp"
#include "../modules/action/double.hpp"
#include "../modules/action/half.hpp"
#include "../modules/action/next.hpp"
#include "../modules/action/quarter.hpp"
#include "../modules/action/quadruple.hpp"
#include "../modules/action/reverse.hpp"
#include "../modules/action/reRoll.hpp"
#include "../modules/action/swapCard.hpp"
#include "../modules/action/switch.hpp"

#include "../modules/action/abilityless.cpp"
#include "../modules/action/double.cpp"
#include "../modules/action/half.cpp"
#include "../modules/action/next.cpp"
#include "../modules/action/quarter.cpp"
#include "../modules/action/quadruple.cpp"
#include "../modules/action/reverse.cpp"
#include "../modules/action/reRoll.cpp"
#include "../modules/action/swapCard.cpp"
#include "../modules/action/switch.cpp"

//theGame
#include "../modules/the_game/TheGame.hpp"
#include "../modules/the_game/TheGame.cpp"

//Exception
#include "../modules/exception/exception.hpp"
#include "../modules/exception/exception.cpp"
#include "../modules/exception/commandexception.hpp"
#include "../modules/exception/commandexception.cpp"
#include "../modules/exception/IOexception.hpp"
#include "../modules/exception/IOexception.cpp"



#include <iostream>
using namespace std;

int main(){
    TheGame *game = new TheGame();
    game->start();
    return 0;
}