#ifndef REROLL_HPP_
#define REROLL_HPP_
#include <iostream>
#include "action.hpp"

using namespace std;

class ReRoll : public Action
{
    private:

    public:
        ReRoll();
        ~ReRoll();
        void execute_action(GameState&);
};

#endif