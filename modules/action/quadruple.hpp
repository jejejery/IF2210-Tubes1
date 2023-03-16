#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP
#include "action.hpp"
#include "../exception/exception.hpp"
#include "../exception/commandexception.hpp"
using namespace std;

class Quadruple : public Action 
{
    private:

    public:
        Quadruple();
        ~Quadruple();
        void execute_action(GameState&);

};

#endif