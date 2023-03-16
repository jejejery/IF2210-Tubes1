#ifndef COMBINATION_
#define COMBINATION_
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <utility>
#include "../card.hpp"
#include "../gamecard/gamecard.hpp"


using namespace std;

class CombinationCard : public Card {
    private:
        vector<GameCard*> player_cards;
        vector<GameCard*> table_cards;
        vector<GameCard*> totalCards; // table card + player card
        int value;
        int constant;
        string type;
    public:
        CombinationCard();
        CombinationCard(const vector<GameCard*>& playerCards, const vector<GameCard*>& tableCards);
        virtual ~CombinationCard();

        // function to get the value and set type
        void setValue(int);
        void setType(string);

        // return int value of the highest combination
        // int getHighestCombination();
        // GameCard* highCard();
        // vector<Card*> isPair();
        // vector<Card*> isTwoPair();
        // vector<Card*> isThreeKind();
        // vector<Card*> isStraight();
        // vector<Card*> isFlush();
        // vector<Card*> isFullHouse();
        // vector<GameCard*> isFourKind();
        // vector<Card*> isStraightFlush();

        // vector<GameCard*> getTableCards();
        // vector<GameCard*> getPlayerCards();
        // bool isPlayerCard(GameCard*);

        vector<GameCard*> getTotalCards();

        // return double constant of the highest combination 

        float searchElement(pair<int, char> );

        float searchElement(int, char);
        // double getHighestCombinationType();

        // bool operator<(CombinationCard& );

        // bool operator>(CombinationCard& );

        // bool operator==(CombinationCard& );

        // string getOwnerCards() const;

        // to compare 
        // CombinationCard compare();

        static bool compareNumber(GameCard*, GameCard*);
        static bool compareColor(GameCard*, GameCard*);
        void sortByNumber();
        void sortByNumber(int begin, int size);
        void sortByColor();

        pair<string, int> getLongestColor();
        pair<int, int> getLongestStraight();

        static vector<int> existingNumber;
        // vector<int> getExistingNumber();
        // int* getExistingNumber();


};


#endif