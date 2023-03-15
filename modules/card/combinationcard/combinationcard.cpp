#include "combinationcard.hpp"
using namespace std;

CombinationCard::CombinationCard(){}

CombinationCard::CombinationCard(const vector<GameCard*>& playerCards, const vector<GameCard*>& tableCards)
{
    // totalcards = playerCards + tableCards
    this->totalCards.insert(totalCards.end(), playerCards.begin(), playerCards.end());
    this->totalCards.insert(totalCards.end(), tableCards.begin(), tableCards.end());
}

CombinationCard::~CombinationCard() 
{
    delete[] existingNumber;
}

void CombinationCard::setValue(int val) 
{

}

void CombinationCard::setType(string t) 
{

}

float CombinationCard::searchElement(pair<int, char> card) 
{
    return searchElement(card.first, card.second);
}


pair<int, int> CombinationCard::findLongestColor()
{
    int index = -1;
    int counter = 0;
    int length = 0;
    size_t size = this->totalCards.size();

    sortByColor();

    for (size_t i = 1; i < size; i++){
        if (this->totalCards[i]->get_color() == this->totalCards[i-1]->get_color()){
            counter++;
        } else{
            counter = 0;
        }

        if (counter > length){
            length = counter;
            index = i-length;
        }
    }
    length++;

    // index tuh letak pertama kali di vector total kartu yg warnanya terbanyak
    // length banyak warna kartunya yg terbanyak itu
    return pair<int, int>(index, length);
}


pair<int, int> CombinationCard::findLongestStraight()
{
    int index = -1;
    int counter = 0;
    int length = 0;
    size_t size = this->totalCards.size();

    sortByNumber();

    for (size_t i = 1; i < size; i++){
        if (this->totalCards[i]->get_number() == (this->totalCards[i-1]->get_number()-1)){
            counter++;
        } else{
            counter = 0;
        }

        if (counter > length){
            length = counter;
            index = i-length;
        }
    }
    length++;

    // index tuh letak pertama kali di vector total kartu yg berurutan
    // length panjang kartunya yg berurutan itu
    return pair<int, int>(index, length);
}

pair<int, int> CombinationCard::findLongestPair() 
{
    int index = -1;
    int counter = 0;
    int length = 0;
    size_t size = this->totalCards.size();

    sortByNumber();

    for (size_t i = 1; i < size; i++){
        if (this->totalCards[i]->get_number() == this->totalCards[i-1]->get_number()){
            counter++;
        } else{
            counter = 0;
        }

        if (counter > length){
            length = counter;
            index = i-length;
        }
    }
    length++;

    // index tuh letak pertama kali di vector total kartu yg angkanya terbanyak
    // length banyak angka kartunya sama yg terbanyak itu
    return pair<int, int>(index, length);
}
void CombinationCard::arrNumbers(){
    size_t length = this->totalCards.size(); // harusnya 7 sih
    int existingNumber[13] = {0}; // initialize with 0

    for (size_t i = 0; i < length; i++){
        existingNumber[this->totalCards[i]->get_number()-1]++;  // misal di totalcard = {1, 2, 3, 3, 4, 13, 11}
    }                                                           // di existingNumber = {1, 1, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1}
}

int* CombinationCard::getExistingNumber(){
    return this->existingNumber;
}