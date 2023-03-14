#include "inventoryholder.hpp"

InventoryHolder::InventoryHolder():num_of_cards(0){}; //ctor

InventoryHolder::InventoryHolder(int num):num_of_cards(num){
    // cardbuffer.resize(num);
    // for(int i = 0; i < num; i++) cardbuffer[i] = new GameCard();
}; //param ctor

InventoryHolder::~InventoryHolder(){
    for(int i = 0; i<this->num_of_cards; i++) delete this->cardbuffer[i];
}; //dtor

vector<GameCard*> InventoryHolder::get_buffer(){return this->cardbuffer;}
