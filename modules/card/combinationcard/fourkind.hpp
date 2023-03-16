#ifndef FOURKIND_HPP_
#define FOURKIND_HPP_

#include "combinationcard.hpp"
using namespace std;

class FourKind : public CombinationCard
{
    private:
        // double value;
    public:
        static bool detectFourKind();
};

#endif