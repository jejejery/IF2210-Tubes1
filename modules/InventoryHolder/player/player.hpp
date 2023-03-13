#define PLAYER_HPP_
#ifdef PLAYER_HPP_

#include "../inventoryholder.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Player : public InventoryHolder {
    private:
    AbilityCard* theAbilityCard;
    bool AbilityState;
    


    
    
    public:
    Player(); //default ctor
    ~Player(); //dtor


} ;

#endif