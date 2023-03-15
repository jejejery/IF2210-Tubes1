#include "abilityless.hpp"
#include "../gamestate/gamestate.hpp"

using namespace std;

Abilityless :: Abilityless() : Action() {
    
}

Abilityless :: ~Abilityless() {

}

void Abilityless :: execute_action(GameState& game) {
    Player* curr = game.get_current_player();
    
    // kasus 1
    if curr.
} 
