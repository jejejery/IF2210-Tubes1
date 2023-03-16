#include "reRoll.hpp"
#include "../gamestate/gamestate.hpp"
#include "../exception/exception.hpp"
#include "../exception/commandexception.hpp"


ReRoll::ReRoll() {
  // EMPTY
}

ReRoll::~ReRoll() {
  // EMPTY
}

void ReRoll::execute_action(GameState& gameState) {
   // remove 2 cards from player's deck
  Player* currentPlayer = gameState.get_current_player();
  AbilityCard* ab = currentPlayer->get_theAbilityCard();
  if(ab->get_ability() != "RE-ROLL") throw new CommandException(1);
  if(!currentPlayer->getAbilityState()) throw new CommandException(3);
  if(currentPlayer->getAbilityDisable()) throw new CommandException(4);

   // return 2 cards to main deck
  gameState.theDeck->addCard(-(*currentPlayer));
  gameState.theDeck->addCard(-(*currentPlayer));
  gameState.theDeck->shuffleDeck();

  //Gain New Card
  currentPlayer->add_card(gameState.theDeck->drawCard());
  currentPlayer->add_card(gameState.theDeck->drawCard());
  cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
  cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;
  cout << "1. " << *(currentPlayer->get_ith_card(0)) << endl;
  cout << "2. " << *(currentPlayer->get_ith_card(1)) << endl;

  currentPlayer->setAbilityState(false);
  gameState.theQueue->dequeue();
}

