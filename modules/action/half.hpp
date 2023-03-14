#ifndef HALF_HPP_
#define HALF_HPP_
#include <iostream>
#include "action.hpp"
using namespace std;

class Half : public Action 
{
    public:
    Half();
    ~Half();
    void execute_action(GameState&) override;
};

#endif