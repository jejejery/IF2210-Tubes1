#ifndef COMMAND_EXCEPTION_HPP
#define COMMAND_EXCEPTION_HPP
#include "exception.hpp"
#include <string>
#include <iostream>
using namespace std;

class CommandException : public Exception
{
    protected: 
        static int numOfCommandException;
        static string message[]; 

    public: 
        CommandException(int); // ctor 
        static int getNumOfCommandException();
        void displayMessage() const;

};
#endif