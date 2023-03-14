#ifndef SWITCH_HPP_
#define SWITCH_HPP_
#include <iostream>
#include "action.hpp"

using namespace std;

class Switch : public Action
{
    private:

    public:
        Switch();
        ~Switch();
        void execute_action(GameState&);

};

#endif