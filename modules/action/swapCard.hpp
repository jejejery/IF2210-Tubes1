#ifndef _SWAPCARD_HPP_
#define _SWAPCARD_HPP_
#include <iostream>
#include "action.hpp"
#include "../exception/exception.hpp"
#include "../exception/commandexception.hpp"
#include "../exception/IOexception.hpp"

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