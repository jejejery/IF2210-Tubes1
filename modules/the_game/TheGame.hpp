#ifndef _THE_GAME_HPP
#define _THE_GAME_HPP

#include "../gamestate/gamestate.hpp"
#include "../action/action.hpp"
#include "../action/double.hpp"
#include "../action/half.hpp"
#include "../action/next.hpp"

class TheGame{
    private:
    Action* action;
    GameState* gameState;
    
    public:
    TheGame(); //ctor
    ~TheGame(); //dtor
    
    void start();
    void run_game();

    void execute_action(string);



};

#endif