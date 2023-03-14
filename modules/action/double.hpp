#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_
#include "action.hpp"
#include <iostream>
using namespace std;

class Double : public Action
{
    public:
        Double();
        ~Double();
        void execute_action(GameState&);
        // int cln();
};

#endif