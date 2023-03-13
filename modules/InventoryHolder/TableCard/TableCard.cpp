#include "TableCard.hpp"
#include <vector>

TableCard::TableCard():InventoryHolder(5){
    this->idx = 0;
}; //ctor
TableCard::~TableCard(){}; //dtor
    
void TableCard::addCard(GameCard* gc){
    // if(this->idx >= 4) throw fulltablecardexception;  //TO BE IMPLEMENTED!
    cardbuffer[idx] = gc;
    idx++;
};