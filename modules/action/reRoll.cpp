#include "reRoll.hpp"
#include "../gamestate/gamestate.hpp"


ReRoll::ReRoll() {
  // EMPTY
}

ReRoll::~ReRoll() {
  // EMPTY
}

void ReRoll::execute_action(GameState& gameState) {
   // remove 2 cards from player's deck
  Card* card1 = gameState.thePlayers[gameState.round]->removeCard();
  Card* card2 = gameState.thePlayers[gameState.round]->removeCard();

   // draw 2 new cards from main deck
  gameState.thePlayers[gameState.round]->addCard(gameState.theDeck->drawCard());
  gameState.thePlayers[gameState.round]->addCard(gameState.theDeck->drawCard());

   // return 2 cards to main deck
  gameState.theDeck->addCard(card1);
  gameState.theDeck->addCard(card2);
}
