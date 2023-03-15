#ifndef TWOPAIR_HPP_
#define TWOPAIR_HPP_

#include "combinationcard.hpp"
using namespace std;

class TwoPair : public CombinationCard
{
    private:
        // double value;
    public:
        bool detectTwoPair();
};

#endif