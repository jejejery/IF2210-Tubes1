#include "gamestate.hpp"
#include <iostream>
#include <ctime>
// #include <fstream>
// #include <sstream>
using namespace std;

GameState::GameState(){
    this->permainan_ke = 1;
    this->round = 1;
    this->reward = 64;
    this->isReverse = false;

    //inisiasi objek
    //Inisialisasi dek
    theDeck = new Deck();

    theQueue = new myQueue<int>(7);
    for(int i = 0; i < this->num_of_players; i++) thePlayers.push_back(new Player(i+1));

    //inisialisasi player
    for(int i = 1; i <= this->num_of_players; i++) theQueue->enqueue(i);
    for(int i = 0; i < this->num_of_players; i++){
        for(int k = 0; k < 2; k++) {
            (this->thePlayers[i])->add_card((this->theDeck)->drawCard());
        }
    }
    
    //futureQueue dinisialisasi
    for(int i = 2; i <= this->num_of_players; i++) futureQueue.push_back(i);
    futureQueue.push_back(1);

    //CombinationCard *theCombination;

    //abilityCard diinisiasi
    theAbilities.push_back(new AbilityCard("RE-ROLL"));
    theAbilities.push_back(new AbilityCard("QUADRUPLE"));
    theAbilities.push_back(new AbilityCard("QUARTER"));
    theAbilities.push_back(new AbilityCard("REVERSE"));
    theAbilities.push_back(new AbilityCard("SWAPCARD"));
    theAbilities.push_back(new AbilityCard("SWITCH"));
    theAbilities.push_back(new AbilityCard("ABILITYLESS"));

    //TableCard diinisiasi
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

Player* GameState::get_current_player() const{
    return this->thePlayers[theQueue->front()-1];
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
void GameState::next_round(){      
        this->restore_queue();
        this->round++;

        //Beggining of new round
        if(this->round == 2) this->share_ability_cards();
        if(this->round != 1 && this->round <= 6) (this->theTableCards)->addCard((this->theDeck)->drawCard());
        if(this->round > 6) this->next_permainan();
    
}

void GameState::next_permainan(){
    cout << "Next Permainan!" << endl;
    this->reward = 64;
    this->permainan_ke++;
    this->round = 1;
    // Pindahin seluruh kartu dari tablecard ke dek
    this->restore_deck();
}

 void GameState::restore_deck(){

    //LAKUKAN PENGOSONGAN KARTU DAN KEMBALIKAN KE DEK BESERTA DISABLE ABILITY STATE
    for(int i= 0; i < this->num_of_players; i++){
        for(int h = 0; h < 2; h++) (this->theDeck)->addCard((thePlayers[i])->get_ith_card(h));
        (this->thePlayers[i])->empty_cards();
        (this->thePlayers[i])->setAbilityState(false);
        (this->thePlayers[i])->setAbilityDisable(false);
    }

    //KOSONGKAN TABLE CARDS
    while((this->theTableCards)->get_capacity() > 0){
        (this->theDeck)->addCard((this->theTableCards)->drawCard());
    } 

    (this->theDeck)->shuffleDeck();

    for(int i = 0; i < this->num_of_players; i++){
        thePlayers[i]->add_card((this->theDeck)->drawCard());
        thePlayers[i]->add_card((this->theDeck)->drawCard());
    } 
 }

void GameState::restore_queue(){
    for(int i = 0; i < this->num_of_players; i++) theQueue->enqueue(futureQueue[i]); //Copy seluruhnya
    if(this->isReverse){
        this->isReverse = false;    
    }
    else{
        futureQueue.push_back(futureQueue.front());
        futureQueue.erase(futureQueue.begin()); 
    }
    
}

void GameState::share_ability_cards(){
    
    srand(time(0));
    
    // Inisiasi LCG
    int a = 11, c = 8, k = this->theAbilities.size();
    int x = rand() % k;

    // LCG untuk bilangan antara 0 - 51
    for (int i = 0; i < k; i++) {
        x = (a * x + c) % k;
        swap(this->theAbilities[i],this->theAbilities[x]);
    }

    for(int i = 0; i < k; i++){
        (this->thePlayers[i])->setAbility(this->theAbilities[i]);
        (this->thePlayers[i])->setAbilityState(true);
    }
}


bool GameState::isEndgame() const{
    bool hehe = false;
    for(int i = 0; i < this->num_of_players; i++) hehe = hehe || ((this->thePlayers[i])->get_the_score() == this->maxScore);
    return hehe;
}


void GameState::debug(){
    cout << "==================================================" << endl;
    cout << "\t\t DEBUGGING GAMESTATE" << endl;
    cout << "==================================================\n" << endl;

    cout << "THE DECK: " << endl;
    (this->theDeck)->debug();
    cout << endl << endl;

    cout << "THE QUEUE: " << endl;
    (this->theQueue)->debugging();
    cout << endl << endl;

    cout << "PLAYERS: " << endl;
    for(int i = 0; i < thePlayers.size(); i++){
        cout << endl;
        thePlayers[i]->debug();
        cout << endl;
    }

    cout << "TABLE CARDS: " << endl;
    (this->theTableCards)->debug();

    cout << "Permainan ke: " << this->get_permainan_ke() << endl;
    cout << "Ronde ke: " << this->round << endl;
    cout << "Reward: " << this->reward << endl;

    cout << "==================================================" << endl;
    cout << "\t\tAKHIR DARI DEBUGGING" << endl;
    cout << "==================================================\n" << endl;
    
}