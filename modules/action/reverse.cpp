#include "reverse.hpp"
#include "../gamestate/gamestate.hpp"
#include "../exception/exception.hpp"
#include "../exception/commandexception.hpp"

#include <iostream>

using namespace std;

Reverse :: Reverse() : Action() {

}

Reverse :: ~Reverse() {

}

void Reverse :: execute_action(GameState& game) {
    AbilityCard* ab = (game.get_current_player())->get_theAbilityCard();
    if(ab->get_ability() != "REVERSE") throw new CommandException(1); //To Be Implemented

    //Reverse Algorithm:
    int theFront = (game.theQueue)->front();
    cout << "<p" << theFront << "> melakukan reverse!" << endl;

    int delta = (game.theQueue)->get_max_capacity() - (game.theQueue)->size();

    stack<int> container1;
    for(int i = 0; i < delta; i++){
        container1.push(game.futureQueue[i]);
    }
    stack<int> container2;
    for(int i = delta; i < (game.theQueue)->get_max_capacity(); i++){
        container2.push(game.futureQueue[i]);
    }

    for(int i = 0; i < delta; i++){
       game.futureQueue[i] = container1.top();
       container1.pop();
    }

    //Kosongkan queue
    while(!game.theQueue->isEmpty()) game.theQueue->dequeue();
    game.theQueue->enqueue(theFront);
    cout << "(sisa) urutan eksekusi giliran ini : ";
    for(int i = delta; i < (game.theQueue)->get_max_capacity(); i++){
        if(i != delta){
            cout << "<p" << container2.top() << "> ";
            game.theQueue->enqueue(container2.top());
        } 
        game.futureQueue[i] = container2.top();
        container2.pop();
    }
    cout << "\nurutan eksekusi giliran selanjutnya : ";
        for(int i = 0; i < (game.theQueue)->get_max_capacity(); i++) cout << "<p" << game.futureQueue[i] <<"> ";
    cout << endl;
   
}