// #include "../modules/card/card.hpp"
#include "../modules/card/card.cpp"
#include "../modules/InventoryHolder/inventoryholder.cpp"
// #include "../modules/InventoryHolder/player/player.hpp"
#include "../modules/InventoryHolder/player/player.cpp"

#include <iostream>
using namespace std;

int main(){
    // InventoryHolder iv1(2);
    Player p1(10);
    p1.debug();
    return 0;
}