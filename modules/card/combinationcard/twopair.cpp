#include "twopair.hpp"
#include <iostream>
using namespace std;

bool TwoPair::detectTwoPair()
{
    CombinationCard::arrNumbers(); // bangkitkan existing number
    int* checker = CombinationCard::getExistingNumber();
    int counter = 0;

    for (int i = 12; i >= 0; i--){
        // check if any pair is >= 2 (cari dari kartu no.13 (idx ke-12))
        if (checker[i] == 2){ // && check if it's player card (pr: bagusnya sih ngecek apakah pair itu hasil kartunya dia atau dari meja)
            counter++;
        }
    }
    if (counter >= 2){
        return true;
    } else{
        return false;
    }
    
}