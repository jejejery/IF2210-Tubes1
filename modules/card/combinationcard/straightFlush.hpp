#ifndef STRAIGHTFLUSH_HPP_
#define STRAIGHTFLUSH_HPP_

#include "combinationcard.hpp"
#include "straight.hpp"
#include "flush.hpp"
#include <string>
#include <iostream>
using namespace std;

class StraightFlush : public Straight, public Flush
{
    private:
        // double value;
    public:
        static bool detectStraightFlush(pair<string, int>, pair<int, int>);
};

#endif