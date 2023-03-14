#include "gamestate.hpp"
#include <iostream>
using namespace std;

GameState::GameState(){
    this->permainan_ke = 0;
    this->round = 1;
    this->reward = 64;

    //inisiasi objek
    theDeck = new Deck();

    theQueue = new myQueue<int>();
    for(int i = 0; i < 7; i++) thePlayers.push_back(new Player(i+1));

    for(int i = 1; i <= 7; i++) theQueue->enqueue(i);
    for(int i = 0; i < 7; i++){
        for(int k = 0; k < 2; k++) {
            (this->thePlayers[i])->add_card((this->theDeck)->drawCard());
        }
    }
    //CombinationCard *theCombination;
    theTableCards = new TableCard();
}

GameState::~GameState(){
    delete this->theDeck;
    delete this->theQueue;
    for(int i = 0; i < 7; i++) delete this->thePlayers[i];
    delete this->theTableCards;
}


 //==============SETTER=============
int GameState::get_permainan_ke() const{
    return this->permainan_ke;
}
int GameState::get_round() const{
    return this->round;
}

uint64_t GameState::get_reward() const{
    return this->reward;
}

Deck* GameState::get_theDeck() const{
    return this->theDeck;
}

myQueue<int>* GameState::get_theQueue() const{
    return this->theQueue;
}

vector<Player*> GameState::get_thePlayers() const{
    return this->thePlayers;
}

//CombinationCard *theCombination{}
TableCard* GameState::get_theTableCards() const{
    return this->theTableCards;
}

//==============GETTER=============
void GameState::set_permainan_ke(int x){
    this->permainan_ke = x;
}

void GameState::set_round(int x){ this->round = x;}
void GameState::set_reward(uint64_t r){this->reward = r;}

void GameState::set_theDeck(Deck* d){this->theDeck = d;}
void GameState::set_theQueue(myQueue<int>* q){this->theQueue = q;}
void GameState::set_thePlayers(vector<Player*> tp){this->thePlayers = tp;}
//CombinationCard *theCombination{}
void GameState::set_theTableCards(TableCard* tc){this->theTableCards = tc;}
//==============Method==========
void GameState::reset_permainan(){
    this->permainan_ke++;
    this->round = 1;
    this->reward = 64;

    //Pindahin seluruh kartu dari tablecard ke dek
    this->restore_deck();
}

 void GameState::restore_deck(){
    for(int i= 0; i < 7; i++){
        for(int h = 0; h < 2; h++) (this->theDeck)->addCard((thePlayers[i])->get_ith_card(h));
        (this->thePlayers[i])->empty_cards();
    }

    while((this->theTableCards)->get_capacity() > 0){
        (this->theDeck)->addCard((this->theTableCards)->drawCard());
    } 

    (this->theDeck)->shuffleDeck();

    for(int i = 0; i < 7; i++){
        thePlayers[i]->add_card((this->theDeck)->drawCard());
        thePlayers[i]->add_card((this->theDeck)->drawCard());
    } 
 }

void GameState::calculate_winner(){}


void GameState::run_game(){}

void GameState::debug(){
    cout << "==================================================" << endl;
    cout << "\t\t DEBUGGING GAMESTATE\n\n" << endl;
    cout << "==================================================" << endl;

    cout << "THE DECK: " << endl;
    (this->theDeck)->debug();
    cout << endl << endl;

    cout << "THE QUEUE: " << endl;
    (this->theQueue)->debugging();

    cout << "PLAYERS: " << endl;
    for(int i = 0; i < thePlayers.size(); i++){
        cout << endl;
        thePlayers[i]->debug();
        cout << endl;
    }

    cout << "TABLE CARDS: " << endl;
    (this->theTableCards)->debug();

    cout << "Permainan ke: " << this->permainan_ke << endl;
    cout << "Ronde ke: " << this->round << endl;
    cout << "Reward: " << this->reward << endl;

    cout << "==================================================" << endl;
    cout << "\t\tAKHIR DARI DEBUGGING\n\n" << endl;
    cout << "==================================================" << endl;
    
}