#include "straightFlush.hpp"

using namespace std;

bool StraightFlush::detectStraightFlush(pair<string, int> longestColor, pair<int, int> longestStraight)
{
    if(detectFlush(longestColor) && detectStraight(longestStraight)){
        return true;
    } else{
        return false;
    }

}