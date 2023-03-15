#ifndef _THE_GAME_HPP
#define _THE_GAME_HPP

#include "../gamestate/gamestate.hpp"
#include "../action/action.hpp"
#include "../action/double.hpp"
#include "../action/half.hpp"
#include "../action/next.hpp"
#include "../action/reverse.hpp"
#include "../exception/exception.hpp"
#include "../exception/commandexception.hpp"
#include <map>

class TheGame{
    private:
    GameState* gameState;
    map<string,Action*> actions;
    
    public:
    TheGame(); //ctor
    TheGame(const TheGame&); //cctor
    ~TheGame(); //dtor
    
    void start();
    void run_game();

    void execute_action(string);



};

#endif