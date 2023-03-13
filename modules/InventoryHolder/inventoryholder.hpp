#ifndef INV_HPP_
#define INV_HPP_

#include "../card/card.hpp"
// #include "../card/card.cpp"
#include <iostream>
#include <vector>

using namespace std;


class InventoryHolder{
    protected:
    vector<GameCard*> cardbuffer;
    const uint8_t num_of_cards;

    public:

    InventoryHolder(); //ctor
    InventoryHolder(uint8_t num); //param ctor
    ~InventoryHolder(); //dtor

    vector<GameCard*> get_buffer();
    virtual uint8_t get_num_of_cards() const = 0;

};

#endif