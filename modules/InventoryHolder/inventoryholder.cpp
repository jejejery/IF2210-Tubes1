#include "inventoryholder.hpp"

InventoryHolder::InventoryHolder():num_of_cards(0){}; //ctor

InventoryHolder::InventoryHolder(uint8_t num):num_of_cards(num){
    cardbuffer.assign(num_of_cards, new GameCard());
}; //param ctor

InventoryHolder::~InventoryHolder(){
    for(int i = 0; i<this->num_of_cards; i++) delete this->cardbuffer[i];
}; //dtor

vector<GameCard*> InventoryHolder::get_buffer(){return this->cardbuffer;}
