#define ACTION_HPP_
#ifdef ACTION_HPP_

#include "../inventoryholder/player/player.hpp"
// #include "../inventoryholder/player/player.hpp"

class GameState; //forward declaration

class Action{
    public:
    Action();
    ~Action();
    virtual void execute_action(GameState&) = 0;
};

#endif