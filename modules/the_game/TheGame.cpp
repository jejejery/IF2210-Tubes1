#include "TheGame.hpp"
#include <iostream>

using namespace std;

TheGame::TheGame(){
    this->gameState = new GameState();
    actions["ABILITYLESS"] = new Abilityless();
    actions["NEXT"] = new Next();
    actions["DOUBLE"] = new Double();
    actions["HALF"] = new Half();
    actions["REVERSE"] = new Reverse();
    actions["QUARTER"] = new Quarter();
    actions["QUADRUPLE"] = new Quadruple();
    actions["REROLL"] = new ReRoll();
    actions["SWAPCARD"] = new SwapCard();
    actions["SWITCH"] = new Switch();
} //ctor

// TheGame(const TheGame& tg){
//     this->action = tg.action;
//     this->gameState = tg.gameState;
//     this->exception = tg.exception;
// }
TheGame::~TheGame(){
    map<string, Action*>::iterator it = actions.begin();
    while (it != actions.end())
    {
    delete it->second;
    ++it;
    }
    delete this->gameState;
} //dtor

void TheGame::start(){
    cout << "\t\t    ____  _   ____  _______     ________            ______               __" << endl;
    cout << "\t\t   / __ )/ | / /  |/  / __ \\  /_  __/ /_  ___     / ____/___ __________/ /" << endl;
    cout << "\t\t  / __  /  |/ / /|_/ / / / /    / / / __ \\/ _ \\   / /   / __ `/ ___/ __  / " << endl;
    cout << "\t\t / /_/ / /|  / /  / / /_/ /    / / / / / /  __/  / /___/ /_/ / /  / /_/ /  " << endl;
    cout << "\t\t/_____/_/ |_/_/  /_/\\____/    /_/ /_/ /_/\\___/   \\____/\\__,_/_/   \\__,_/   " << endl;
    char c;
    cout << "Apakah ingin menerima input dari file??" << endl;
    cin >> c;

    while(c != 'y' && c != 'Y' && c != 'N' && c != 'n'){
        cout << "Input invalid! Masukkan kembali input yang benar: ";
        cin >> c;
    } 
    
    if(c == 'y' || c == 'Y'){
            cout << "\nMasukkan Nama file: ";
            string filename;
            cin>> filename; 
            this->gameState = new GameState(filename);
    }



    while(!((this->gameState)->isEndgame())){
        try{
        this->run_game();
        }
        catch(Exception* e){
            (e)->displayMessage();
            delete e;
        }
    }
    this->gameState->theEnd();
    
}

void TheGame::run_game(){
    
    (this->gameState)->debug();
    cout << "Sekarang Giliran Player " << ((this->gameState)->get_theQueue())->front() << endl;
    cout << "Aksi?" << endl;
    string aksi;
    cin >> aksi;
    this->execute_action(aksi);
    
    
    
}

void TheGame::end(){
    try{
        cout << "Ingin Bermain lagi?" << endl;
        cout << "1. Lanjut" << endl;
        cout << "2. Exit"   << endl;
        int option;
        cin >> option;
        if(option == 1) start();
        else if(option == 2);
        else throw new IOexception(0);
    }
    catch(Exception* e){
        e->displayMessage();
        TheGame::end();
    }
    
}
void TheGame::execute_action(string aksi){
    if(this->actions[aksi] != NULL){
        (this->actions[aksi])->execute_action(*(this->gameState));
    }
    else{
        throw new CommandException(0);
    }
    if(((this->gameState)->get_theQueue())->isEmpty()){
        (this->gameState)->next_round();
    }
}