#ifndef TABLE_HPP_
#define TABLE_HPP_

#include "../inventoryholder.hpp"

#include <iostream>
#include <vector>

using namespace std;

class TableCard : public InventoryHolder{

    private: 
    int capacity;

    public:
    TableCard(); //ctor
    ~TableCard(); //dtor

    //Setter Getter
    int get_num_of_cards() const override;
    int get_capacity() const;

    GameCard* drawCard();
    
    void set_capacity(int);
    void addCard(GameCard* gc);

    void debug();

};

#endif