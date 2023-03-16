#include "twopair.hpp"
#include <iostream>
using namespace std;

bool TwoPair::detectTwoPair()
{
    int counter = 0;

    for (int i = 0; i < existingNumber.size(); i++){
        if (existingNumber[i] == 2){
            counter++;
        }
    }
    if (counter >= 2){
        return true;
    } else {
        return false;
    }
    
}