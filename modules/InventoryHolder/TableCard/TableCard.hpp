#define TABLE_HPP_
#ifdef TABLE_HPP_

#include "../inventoryholder.hpp"

class TableCard : public InventoryHolder{
    public:
    TableCard(); //ctor
    ~TableCard(); //dtor
    
    void addCard(const GameCard* gc);



};

#endif