#ifndef REVERSE_HPP_
#define REVERSE_HPP_
#include <iostream>
#include "action.hpp"
#include <stack>
using namespace std;

class Reverse : public Action
{
    private:

    public:
        Reverse();
        ~Reverse();
        void execute_action(GameState&);

};

#endif