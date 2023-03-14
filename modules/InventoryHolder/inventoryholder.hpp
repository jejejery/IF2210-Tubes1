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
    const int num_of_cards;

    public:

    InventoryHolder(); //ctor
    InventoryHolder(int num); //param ctor
    ~InventoryHolder(); //dtor

    vector<GameCard*> get_buffer();
    virtual int get_num_of_cards() const = 0;

};

#endif