#ifndef FLUSH_HPP_
#define FLUSH_HPP_

#include "combinationcard.hpp"
using namespace std;

class Flush : public CombinationCard
{
    private:
        // double value;
    public:
        bool detectFlush();
};

#endif