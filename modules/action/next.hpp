#ifndef NEXT_HPP_
#define NEXT_HPP_
#include "action.hpp"
using namespace std;

class Next : public Action
{
    private:

    public:
        Next();
        ~Next();
        void execute_action(const GameState&);

};

#endif