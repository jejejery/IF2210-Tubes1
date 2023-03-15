#include "straight.hpp"

using namespace std;

bool Straight::detectStraight(pair<int, int> longestStraight)
{
    if (longestStraight.second - longestStraight.first + 1 >= 5){
        return true;
    } else{
        return false;
    }
}