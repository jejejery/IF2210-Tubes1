#ifndef QUARTER_HPP_
#define QUARTER_HPP_
#include "action.hpp"
#include <iostream>

class Quarter : public Action 
{
    private:

    public:
        Quarter();
        ~Quarter();
        void execute_action(GameState&);

};

#endif