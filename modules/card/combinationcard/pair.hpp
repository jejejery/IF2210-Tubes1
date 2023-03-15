#ifndef PAIR_HPP_
#define PAIR_HPP_

#include "combinationcard.hpp"
using namespace std;

class Pair : public CombinationCard
{
    private:
        // double value;
    public:
        bool detectPair();
};

#endif