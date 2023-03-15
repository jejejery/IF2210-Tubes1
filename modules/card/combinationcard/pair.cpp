#include "pair.hpp"
#include <iostream>
using namespace std;

bool Pair::detectPair()
{
    CombinationCard::arrNumbers(); // bangkitkan existing number
    int* checker = CombinationCard::getExistingNumber();

    for (int i = 12; i >= 0; i--){
        // check if any existingNumber is >= 2 (cari yg nilai pairnya terbesar)
        if (checker[i] == 2){ // && check if it's player card (pr: bagusnya sih ngecek apakah pair itu hasil kartunya dia atau dari meja)
            return true;
        }
    }
    
    return false;
}