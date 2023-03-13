#ifndef INV_HPP_
#define INV_HPP_

#include "../card/card.hpp"
#include <iostream>
#include <vector>

using namespace std;


class InventoryHolder{
    protected:
    vector<GameCard*> cardbuffer;
    const uint8_t num_of_cards;

    public:

    InventoryHolder():num_of_cards(0){}; //ctor
    ~InventoryHolder(){}; //dtor

    vector<GameCard*> get_buffer(){return this->cardbuffer;}
    virtual uint8_t get_num_of_cards() = 0;

};

#endif