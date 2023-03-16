#ifndef DECK_HPP_
#define DECK_HPP_

#include "../card/gamecard/gamecard.hpp"
#include <iostream>
#include <random>
using namespace std;

class Deck{
    public:
        // default constructor
        Deck();

        // user-defined constructor
        Deck(int);
        Deck(string);

        // destructor
        ~Deck();

        // method
        void shuffleDeck();

        //Getter,setter
        int deckSize() const;

        GameCard* drawCard();
        vector<GameCard*> getCards();

        void addCard(GameCard*);
        void debug();

    private:
        vector<GameCard*> cards;
};

#endif