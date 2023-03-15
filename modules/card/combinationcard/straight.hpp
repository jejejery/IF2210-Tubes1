#ifndef STRAIGHT_HPP_
#define STRAIGHT_HPP_

#include "combinationcard.hpp"
#include <iostream>
using namespace std;

class Straight : public CombinationCard
{
    private:
        // double value;
    public:
        static bool detectStraight(pair<int, int>);
};

#endif