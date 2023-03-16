#include "flush.hpp"
#include <iostream>

using namespace std;

bool Flush::detectFlush(pair<string, int> longestColor)
{
    if (longestColor.second >= 5)
    {
        return true;
    } else
    {
        return false;
    }
}