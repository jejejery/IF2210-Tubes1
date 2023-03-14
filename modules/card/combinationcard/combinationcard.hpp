#ifndef COMBINATIONCARD_HPP_
#define COMBINATIONCARD_HPP_
#include <iostream>
#include <vector>
#include "../gamecard/gamecard.hpp"
using namespace std;


class CombinationCard : public GameCard {
    private:
        vector<GameCard*> player_cards;
        vector<GameCard*> table_cards;
        int value;
        int constant;
        string type;
    public:
        // function to get the value and set type
        void setValue(int);
        void setType(string);

        // return int value of the highest combination
        int getHighestCombination();

        // return double constant of the highest combination 
        double getHighestCombiType();

        // to compare 
        CombinationCard compare();
};


#endif