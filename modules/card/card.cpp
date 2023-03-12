#include "card.hpp"
#include <cstdlib>
#include <random>
#include <iterator>
#include <algorithm>
using namespace std;


// --------------[ Implementation of GameCard ]--------------
GameCard::GameCard(){}

GameCard::GameCard(int number, string color)
{
    this->number = number;
    this->color = color;
}

GameCard::~GameCard(){}

int GameCard::getNumber()
{
    return this->number;
}

string GameCard::getColor()
{
    return this->color;
}

void GameCard::setNumber(int number)
{
    this->number = number;
}

void GameCard::setColor(string color)
{
    this->color = color;
}

// --------------[ Implementation of Deck ]--------------
Deck::Deck() : deckSize(13)
{
    for (int i = 1; i <= deckSize; i++) {
        cards.push_back(GameCard(i, "Red"));
        cards.push_back(GameCard(i, "Yellow"));
        cards.push_back(GameCard(i, "Blue"));
        cards.push_back(GameCard(i, "Green"));
    }
}

Deck::Deck(int size) : deckSize(size)
{
    for (int i = 1; i <= deckSize; i++) {
        cards.push_back(GameCard(i, "Red"));
        cards.push_back(GameCard(i, "Yellow"));
        cards.push_back(GameCard(i, "Blue"));
        cards.push_back(GameCard(i, "Green"));
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
    GameCard drawn = cards.back();
    cards.pop_back();
    return drawn;
}

// --------------[ Implementation of AbilityCard ]--------------
AbilityCard::AbilityCard(){
    vector<string> abilities = {"Re-roll", "Quadruple", "Quarter", "Reverse Direction", "Swap Card", "Switch", "Abilityless"};
    this->setAbilities(abilities);
}

AbilityCard::AbilityCard(vector<string> abilities)
{
    this->setAbilities(abilities);
}

AbilityCard::~AbilityCard(){}

string AbilityCard::getAbility()
{
    string drawn = abilities.back();
    abilities.pop_back();
    return drawn;
}

void AbilityCard::setAbilities(vector<string> abilities)
{
    for (int i = 0; i < abilities.size(); i++){
        this->abilities.push_back(abilities[i]);
    }
}

void AbilityCard::shuffleAbilities()
{
    random_device rd;
    mt19937 gen(rd());
    shuffle(abilities.begin(), abilities.end(), gen);
}
