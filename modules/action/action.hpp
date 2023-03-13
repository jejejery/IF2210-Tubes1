#define ACTION_HPP_
#ifdef ACTION_HPP_

#include "../inventoryholder/player/player.hpp"
// #include "../inventoryholder/player/player.hpp"

class GameState; //forward declaration

class Action{
    public:
    virtual void execute_action() = 0;
};

#endif