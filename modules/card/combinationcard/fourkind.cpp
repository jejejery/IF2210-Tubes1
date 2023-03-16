#include "fourkind.hpp"
#include <iostream>

using namespace std;

bool FourKind::detectFourKind()
{
   for (int i = 0; i < existingNumber.size(); i++){
        if (existingNumber[i] == 4){
            return true;
        }
    }
    return false;
}