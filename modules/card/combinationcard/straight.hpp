#ifndef STRAIGHT_HPP_
#define STRAIGHT_HPP_

#include "combinationcard.hpp"
using namespace std;

class Straight : public CombinationCard
{
    private:
        // double value;
    public:
        bool detectStraight();
};

#endif