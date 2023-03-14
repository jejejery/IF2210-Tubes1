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
        cards.push_back(new GameCard(i, "Merah"));
        cards.push_back(new GameCard(i, "Kuning"));
        cards.push_back(new GameCard(i, "Biru"));
        cards.push_back(new GameCard(i, "Hijau"));
    }
}

Deck::Deck(int size)
{
    for (int i = 1; i <= 13; i++) {
        cards.push_back(new GameCard(i, "Merah"));
        cards.push_back(new GameCard(i, "Kuning"));
        cards.push_back(new GameCard(i, "Biru"));
        cards.push_back(new GameCard(i, "Hijau"));
    }
}

Deck::Deck(string filepath)
{
    ifstream infile(filepath);
    string line;
    while (getline(infile, line)) {
        string color = line.substr(0, line.find(","));     // contoh isi file test.txt: Merah, 1
        int number = stoi(line.substr(line.find(",")+1));  //                           Biru, 13
                                                           //                           dst ...
        GameCard* newCard = new GameCard(number, color);
        this->cards.push_back(newCard);
    }
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

void Deck::addCard(GameCard* gc){
    cards.push_back(gc);
}

int Deck::deckSize() const
{
    return this->cards.size();
}

void Deck::debug()
{
    for(int i = 0; i < this->deckSize(); i++) cout << *(this->cards[i]) << endl;
    cout << "Deck Size: " << this->deckSize() << endl;
}
