#include "next.hpp"
#include "../gamestate/gamestate.hpp"
#include <iostream>

using namespace std;

Next :: Next() : Action() {

}

Next :: ~Next() {

}

void Next :: execute_action(GameState& game) {
    cout << "Player " << (game.theQueue)->front() << " tidak melakukan apa-apa" << endl;
    cout << "Giliran dilanjut ke pemain selanjutnya." << endl;
    game.theQueue->dequeue();

}