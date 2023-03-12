#ifndef CARD_HPP_
#define CARD_HPP_

#include <iostream>
#include "../card/card.hpp"
using namespace std;


class InventoryHolder{
    protected:
    vector<GameCard*> cardbuffer;

    public:
    InventoryHolder(); //ctor
    ~InventoryHolder(); //dtor

    vector<GameCard*> get_buffer();

};