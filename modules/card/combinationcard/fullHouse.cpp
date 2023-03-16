#include "fullHouse.hpp"
#include <iostream>

using namespace std;

bool FullHouse::detectFullHouse() 
{
    bool pair3 = false;
    bool pair2 = false;

    for (int i = 0; i < existingNumber.size(); i++){
        if (existingNumber[i] == 3){
            pair3 = true;
        }
        else if (existingNumber[i] == 2) {
            pair2 = true;
        }
    }
    
    if (pair2 && pair3){
        return true;
    } else{
        return false;
    }
}