#include "deck.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

Deck::Deck() : deckSize(13)
{
    for (int i = 1; i <= deckSize; i++) {
        cards.push_back(new GameCard(i, "Red"));
        cards.push_back(new GameCard(i, "Yellow"));
        cards.push_back(new GameCard(i, "Blue"));
        cards.push_back(new GameCard(i, "Green"));
    }
}

Deck::Deck(int size) : deckSize(size)
{
    for (int i = 1; i <= deckSize; i++) {
        cards.push_back(new GameCard(i, "Red"));
        cards.push_back(new GameCard(i, "Yellow"));
        cards.push_back(new GameCard(i, "Blue"));
        cards.push_back(new GameCard(i, "Green"));
    }
}

Deck::~Deck(){}

void Deck::shuffleDeck()
{
    random_device rd;
    mt19937 gen(rd());
    shuffle(cards.begin(), cards.end(), gen);
}

GameCard Deck::drawCard(){
    GameCard *drawn = cards.back();
    cards.pop_back();
    return *drawn;
}
