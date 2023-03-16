#include "threekind.hpp"
#include <iostream>
using namespace std;

bool ThreeKind::detectThreeKind()
{
    for (int i = 0; i < existingNumber.size(); i++){
        if (existingNumber[i] == 3){
            return true;
        }
    }
    
    return false;
}