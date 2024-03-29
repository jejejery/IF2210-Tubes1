#include "TableCard.hpp"
#include <vector>

TableCard::TableCard():InventoryHolder(5){
    this->capacity = 0;
}; //ctor
TableCard::~TableCard(){}; //dtor
    
void TableCard::addCard(GameCard* gc){
    // if(this->capacity >= 5) throw fulltablecardexception;  //TO BE IMPLEMENTED!
    cardbuffer.push_back(gc);
    capacity++;
};

int TableCard::get_num_of_cards() const{
    return this->num_of_cards;
} 

int TableCard::get_capacity() const{
    return this->capacity;
}

void TableCard::set_capacity(int cap){
    this->capacity = cap;
}


GameCard* TableCard::drawCard()
{
    
    GameCard* drawn = this->cardbuffer.front();
    this->cardbuffer.erase(this->cardbuffer.begin());
    this->capacity--;
    return drawn;
}

void TableCard::debug(){
    if(this->capacity){
        cout << "Kapasitas: " << this->capacity << endl;
        for(int i = 0; i < this->capacity; i++) cout << *(this->cardbuffer[i]) << endl;
    }
    else{
        cout << "TableCard Kosong!" << endl;
    }
}