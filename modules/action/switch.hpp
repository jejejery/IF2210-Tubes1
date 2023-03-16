#ifndef SWITCH_HPP_
#define SWITCH_HPP_
#include <iostream>
#include "action.hpp"
#include "../exception/exception.hpp"
#include "../exception/commandexception.hpp"
#include "../exception/IOexception.hpp"
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