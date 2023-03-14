#ifndef SWAPCARD_HPP_
#define SWAPCARD_HPP
#include <iostream>
#include "action.hpp"

using namespace std;

class SwapCard : public Action 
{
    private:

    public:
        SwapCard();
        ~SwapCard();
        void execute_action(GameState&);

};

#endif