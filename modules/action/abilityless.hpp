#ifndef ABILITYLESS_HPP_
#define ABILITYLESS_HPP_
#include <iostream>
#include "action.hpp"
#include "../exception/exception.hpp"
#include "../exception/commandexception.hpp"
#include "../exception/IOexception.hpp"
using namespace std;

class Abilityless : public Action{
    private:

    public:
        Abilityless();
        ~Abilityless();
        void execute_action(GameState&);

};

#endif