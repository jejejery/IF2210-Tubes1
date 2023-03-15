#ifndef THREEKIND_HPP_
#define THREEKIND_HPP_

#include "combinationcard.hpp"
using namespace std;

class ThreeKind : public CombinationCard
{
    private:
        // double value;
    public:
        bool detectThreeKind();
};

#endif