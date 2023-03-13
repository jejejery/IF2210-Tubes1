#ifndef DECK_HPP_
#define DECK_HPP_

#include "../card/card.hpp"
#include <iostream>
#include <random>
using namespace std;

class Deck{
    public:
        // default constructor
        Deck();

        // user-defined constructor
        Deck(int);

        // destructor
        ~Deck();

        // method
        void shuffleDeck();

        GameCard drawCard();

    private:
        const int deckSize;
        vector<GameCard*> cards;
};

#endif