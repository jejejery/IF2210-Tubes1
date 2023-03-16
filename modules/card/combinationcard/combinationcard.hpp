#ifndef COMBINATION_
#define COMBINATION_
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <utility>
#include <map>
#include "../card.hpp"
#include "../gamecard/gamecard.hpp"


using namespace std;

class CombinationCard : public Card {
    private:
        vector<GameCard*> totalCards; // table card + player card
        vector<int> existingNumber;
        
        static map<string,int> combinationOrder;

        string type;
    public:
        CombinationCard();
        CombinationCard(const vector<GameCard*>& playerCards, const vector<GameCard*>& tableCards);
        virtual ~CombinationCard();

        string getType();
        // function to get the value and set type
        void setValue(int);
        void setType(string);
        void setTotalCards(const vector<GameCard*>&, const vector<GameCard*>&);
        void set_ith_Card(int,GameCard*);

        
        //getter
        vector<GameCard*> getTotalCards() const;
        vector<int> getExistingNumber() const;

        //Pair
        vector<GameCard*> getPair() const;
        vector<GameCard*> getTwoPair() const;
        vector<GameCard*> getThreeKind() const;
        vector<GameCard*> getFourKind() const;
        vector<GameCard*> getStraight() const;
        vector<GameCard*> getFullHouse() const;
        vector<GameCard*> getStraightFlush() const;
        
         

        
        //DETECT:
        bool detectPair() const;
        bool detectTwoPair() const;
        bool detectThreeKind() const;
        bool detectStraight(pair<int, int>) const;
        bool detectFlush(pair<string, int>) const;
        bool detectFullHouse() const;
        bool detectFourKind() const;
        bool detectStraightFlush(pair<string, int>, pair<int, int>) const;
        
        
        

        //Assignment operator
        bool operator>(const CombinationCard&);
        bool operator<(const CombinationCard&);
        bool operator==(const CombinationCard&) const;

        //SameHandler
        bool sameHandlerHighCard(const CombinationCard&) const;
        bool sameHandlerPair(const CombinationCard&) const;
        bool sameHandlerTwoPair(const CombinationCard&) const;
        bool sameHandlerThreeKind(const CombinationCard&) const;
        bool sameHandlerStraight(const CombinationCard&) const;
        bool sameHandlerFlush(const CombinationCard&);
        bool sameHandlerFullHouse(const CombinationCard&) const;
        bool sameHandlerFourKind(const CombinationCard&) const;
        bool sameHandlerStraightFlush(const CombinationCard&) const;








        // to compare 
        // CombinationCard compare();

        static bool compareNumber(GameCard*, GameCard*);
        static bool compareColor(GameCard*, GameCard*);
        static bool compareCard(GameCard*, GameCard*);

        void sortTotalCards();

        void sortByNumber();
        void sortByNumber(int begin, int size);
        void sortByColor();

        //
        void decideBestCombination();

        pair<string, int> getLongestColor();
        pair<int, int> getLongestStraight();

        // vector<int> getExistingNumber();
        // int* getExistingNumber();

        void debug();


};


#endif