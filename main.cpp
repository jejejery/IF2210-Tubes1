#include "modules/card/card.hpp"
#include "modules/card/gamecard/gamecard.hpp"
#include "modules/card/abilitycard/abilitycard.hpp"
#include "modules/card/combinationcard/combinationcard.hpp"


#include "modules/InventoryHolder/inventoryholder.hpp"
#include "modules/InventoryHolder/player/player.hpp"
#include "modules/InventoryHolder/TableCard/TableCard.hpp"

#include "modules/deck/deck.hpp"

#include "modules/myqueue/myqueue.hpp"

#include "modules/gamestate/gamestate.hpp"

//==========ACTION========
#include "modules/action/action.hpp"

#include "modules/action/abilityless.hpp"
#include "modules/action/double.hpp"
#include "modules/action/half.hpp"
#include "modules/action/next.hpp"
#include "modules/action/quarter.hpp"
#include "modules/action/quadruple.hpp"
#include "modules/action/reverse.hpp"
#include "modules/action/reRoll.hpp"
#include "modules/action/swapCard.hpp"
#include "modules/action/switch.hpp"


//theGame
#include "modules/the_game/TheGame.hpp"

//Exception
#include "modules/exception/exception.hpp"
#include "modules/exception/commandexception.hpp"
#include "modules/exception/IOexception.hpp"


#include <iostream>
using namespace std;

int main(){
    TheGame *game = new TheGame();
    game->start();
    return 0;
}