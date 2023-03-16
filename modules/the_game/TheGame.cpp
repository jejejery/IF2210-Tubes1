#include "TheGame.hpp"
#include <iostream>

using namespace std;

TheGame::TheGame(){
    this->gameState = new GameState();
    //Inisiasi actions
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
    // this->action = new Next();
    // this->gameState = new GameState();
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

    cout << "Apakah ingin menerima input dari file??" << endl;

    while(!((this->gameState)->isEndgame())){
        try{
        this->run_game();
        }
        catch(Exception* e){
            (e)->displayMessage();
            delete e;
        }
    }
}

void TheGame::run_game(){
    
    (this->gameState)->debug();
    cout << "Sekarang Giliran Player " << ((this->gameState)->get_theQueue())->front() << endl;
    cout << "Aksi?" << endl;
    string aksi;
    cin >> aksi;
    this->execute_action(aksi);
    
    
    
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