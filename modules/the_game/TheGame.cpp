#include "TheGame.hpp"
#include <iostream>

using namespace std;

TheGame::TheGame(){
    this->action = new Next();
    this->gameState = new GameState();
} //ctor
TheGame::~TheGame(){
    delete this->action;
    delete this->gameState;
} //dtor
    
void TheGame::start(){
    cout << "\t\t    ____  _   ____  _______     ________            ______               __" << endl;
    cout << "\t\t   / __ )/ | / /  |/  / __ \\  /_  __/ /_  ___     / ____/___ __________/ /" << endl;
    cout << "\t\t  / __  /  |/ / /|_/ / / / /    / / / __ \\/ _ \\   / /   / __ `/ ___/ __  / " << endl;
    cout << "\t\t / /_/ / /|  / /  / / /_/ /    / / / / / /  __/  / /___/ /_/ / /  / /_/ /  " << endl;
    cout << "\t\t/_____/_/ |_/_/  /_/\\____/    /_/ /_/ /_/\\___/   \\____/\\__,_/_/   \\__,_/   " << endl;

    cout << "Apakah ingin menerima input dari file??" << endl;

    while(!((this->gameState)->isEndgame())){
        this->run_game();
    }
}

void TheGame::run_game(){
    
    (this->gameState)->debug();
    cout << "Sekarang Giliran Player " << ((this->gameState)->get_theQueue())->front() << endl;
    cout << "Aksi?" << endl;
    string aksi;
    cin >> aksi;
    this->execute_action(aksi);
    cout << ((this->gameState)->get_theQueue())->isEmpty() << endl;
    if(((this->gameState)->get_theQueue())->isEmpty()){
        (this->gameState)->reset_permainan();
    }
    
    
}

void TheGame::execute_action(string aksi){
    if(aksi == "DOUBLE"){
        this->action = new Double();
        (this->action)->execute_action(*(this->gameState));
    }
    else if(aksi == "NEXT"){
        this->action = new Next();
        (this->action)->execute_action(*(this->gameState));
    }
    else if(aksi == "HALF"){
        this->action = new Half();
        (this->action)->execute_action(*(this->gameState));
    }
    else{
        cout << "Bukan pilihan yg tepat yah" << endl;
    }
}