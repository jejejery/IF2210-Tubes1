#include "combinationcard.hpp"
using namespace std;

vector<int> CombinationCard::existingNumber {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0};

CombinationCard::CombinationCard(){}

CombinationCard::CombinationCard(const vector<GameCard*>& playerCards, const vector<GameCard*>& tableCards)
{
    // totalcards = playerCards + tableCards
    this->totalCards.insert(totalCards.end(), playerCards.begin(), playerCards.end());
    this->totalCards.insert(totalCards.end(), tableCards.begin(), tableCards.end());

    size_t length = this->totalCards.size(); // harusnya 7 sih

    for (size_t i = 0; i < length; i++){
        existingNumber[this->totalCards[i]->get_number()-1]++;  // misal di totalcard = {1, 2, 3, 3, 4, 13, 11}
    }                                                           // di existingNumber = {1, 1, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1}

}

CombinationCard::~CombinationCard() 
{
    // delete[] existingNumber;
}

void CombinationCard::setValue(int val) {}

void CombinationCard::setType(string t) {}


float CombinationCard::searchElement(pair<int, char> card) 
{
    return searchElement(card.first, card.second);
}

float CombinationCard::searchElement(int num, char col){}

vector<GameCard*> CombinationCard::getTotalCards()
{
    return this->totalCards;
}

bool CombinationCard::compareNumber(GameCard* gc1, GameCard* gc2){
    return gc1->get_number() > gc2->get_number();
}

bool CombinationCard::compareColor(GameCard* gc1, GameCard* gc2){
    return gc1->get_color() < gc2->get_color();
}

// sorting in descending order
void CombinationCard::sortByNumber(){
    sort(this->totalCards.begin(), this->totalCards.end(), compareNumber);
}

void CombinationCard::sortByNumber(int begin, int size){
    sort(this->totalCards.begin() + begin, this->totalCards.begin() + begin + size, compareNumber);
}

// sorting in descending order by card_weight
void CombinationCard::sortByColor(){
    sort(this->totalCards.begin(), this->totalCards.end(), compareColor);
}

pair<string, int> CombinationCard::getLongestColor()
{
    string color;
    int counter = 0;
    int length = 0;
    this->sortByColor();

    for (int i = 1; i < this->totalCards.size(); i++){
        if (this->totalCards[i]->get_color() == this->totalCards[i-1]->get_color()){
            counter++;
        } else{
            counter = 0;
        }

        if (counter > length){
            color = this->totalCards[i]->get_color();
            length = counter;
        }
    }
    length++;
    return make_pair(color, length);
}

pair<int, int> CombinationCard::getLongestStraight()
{
    int counter = 0;
    int length = 0;
    int bottomValue = 0;
    this->sortByNumber();
    for (int i = 1; i < this->totalCards.size(); i++){
        if (this->totalCards[i]->get_number() == (this->totalCards[i-1]->get_number()-1)){
            counter++;
        } else if (this->totalCards[i]->get_number() == (this->totalCards[i-1]->get_number())){
            continue;
        } else{
            counter = 0;
        }

        if (counter > length){
            length = counter;
            bottomValue = this->totalCards[i]->get_number();
        }
    }

    return make_pair(bottomValue, bottomValue+length); // misal straight 3, 4, 5, 6, 7, then bottomValue = 3, topvalue(bottom+length) = 7
}