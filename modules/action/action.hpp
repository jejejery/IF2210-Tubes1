#ifndef ACTION_HPP_
#define ACTION_HPP_


// #include "../inventoryholder/player/player.hpp"
// #include "../inventoryholder/player/player.hpp"

#include "../gamestate/gamestate.hpp"

// class GameState; //forward declaration

class Action{
    public:
    Action(){};
    ~Action(){};
    virtual void execute_action(GameState&) = 0;
    // virtual int cln() = 0;
};

#endif