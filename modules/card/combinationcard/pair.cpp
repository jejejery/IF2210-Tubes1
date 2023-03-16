#include "pair.hpp"
#include <iostream>
using namespace std;


bool Pair::detectPair()
{
    for (int i = 0; i < existingNumber.size(); i++){
        if (existingNumber[i] == 2){
            return true;
        }
    }
    return false;
}