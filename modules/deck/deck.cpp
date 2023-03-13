#include "deck.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
using namespace std;

Deck::Deck() 
{
    for (int i = 1; i <= 13; i++) {
        cards.push_back(new GameCard(i, "Red"));
        cards.push_back(new GameCard(i, "Yellow"));
        cards.push_back(new GameCard(i, "Blue"));
        cards.push_back(new GameCard(i, "Green"));
    }
}

Deck::Deck(int size)
{
    for (int i = 1; i <= 13; i++) {
        cards.push_back(new GameCard(i, "Red"));
        cards.push_back(new GameCard(i, "Yellow"));
        cards.push_back(new GameCard(i, "Blue"));
        cards.push_back(new GameCard(i, "Green"));
    }
}

Deck::Deck(string filepath)
{
    ifstream myfile(filepath);
    string line;
    Deck* newDeck;
    int countLine = 0;
    // try {
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                stringstream ss(line);
                int number;
                string color;
                ss >> number >> color;

                GameCard* newCard = new GameCard(number, color);
                newDeck->cards[countLine] = newCard;
                countLine++;
            }
            myfile.close();
        } else {
            // throw fileError;
        }
    // }
    // catch (exception) {
    //     // error handling
    // }
}

Deck::~Deck()
{
    for(int i = 0; i < cards.size(); i++) delete cards[i];
}

void Deck::shuffleDeck()
{
    srand(time(0));

    // Inisiasi LCG
    int a = 11, c = 8, k = 52;
    int x = rand() % k;

    // LCG untuk bilangan antara 0 - 51
    for (int i = 0; i < k; i++) {
        x = (a * x + c) % k;
        swap(this->cards[i],this->cards[x]);
    }
    
}

GameCard* Deck::drawCard()
{
    GameCard* drawn = cards.front();
    cards.erase(cards.begin());
    return drawn;
}

int Deck::deckSize() const
{
    return this->cards.size();
}

void Deck::debug()
{
    for(int i = 0; i < this->deckSize(); i++) cout << *(this->cards[i]) << endl;
}
