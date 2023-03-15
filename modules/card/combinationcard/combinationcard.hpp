#ifndef COMBINATION_
#define COMBINATION_
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <utility>
#include "../card/card.hpp"
#include "../card/gamecard/gamecard.hpp"


using namespace std;

class CombinationCard : public Card {
    private:
        vector<GameCard*> player_cards;
        vector<GameCard*> table_cards;
        vector<GameCard*> totalCards; // table card + player card
        int value;
        int constant;
        string type;
        int* existingNumber; // array of quantitiy of a number
    public:
        CombinationCard();
        CombinationCard(const vector<GameCard*>& playerCards, const vector<GameCard*>& tableCards);
        virtual ~CombinationCard();

        // function to get the value and set type
        void setValue(int);
        void setType(string);

        // return int value of the highest combination
        int getHighestCombination();
        GameCard* highCard();
        vector<Card*> isPair();
        vector<Card*> isTwoPair();
        vector<Card*> isThreeKind();
        vector<Card*> isStraight();
        vector<Card*> isFlush();
        vector<Card*> isFullHouse();
        vector<GameCard*> isFourKind();
        vector<Card*> isStraightFlush();

        vector<GameCard*> getPlayerCards();
        vector<GameCard*> getTableCards();

        vector<GameCard*> getTotalCards();

        // return double constant of the highest combination 

        float searchElement(pair<int, char> );

        float searchElement(int, char);
        double getHighestCombinationType();

        bool operator<(CombinationCard& );

        bool operator>(CombinationCard& );

        bool operator==(CombinationCard& );

        string getOwnerCards() const;

        // to compare 
        CombinationCard compare();

        void sortByNumber();
        void sortByNumber(int begin, int size);
        void sortByColor();

        pair<int, int> findLongestColor();
        pair<int, int> findLongestStraight();
        pair<int, int> findLongestPair();

        void arrNumbers();
        int* getExistingNumber();


};


#endif