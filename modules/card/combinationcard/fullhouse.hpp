#ifndef FULLHOUSE_HPP_
#define FULLHOUSE_HPP_

#include "combinationcard.hpp"
using namespace std;

class FullHouse : public CombinationCard
{
    private:
        // double value;
    public:
        static bool detectFullHouse();
};

#endif