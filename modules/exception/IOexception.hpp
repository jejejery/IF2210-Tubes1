#ifndef IOEXCEPTION_HPP__
#define IOEXCEPTION_HPP__
#include "exception.hpp"
#include <string>
#include <iostream>
using namespace std;

class IOexception : public Exception
{
    protected: 
        static int numOfIOException;
        static string message[];

    public:
        IOexception(int); // user-defined ctor
        IOexception(const IOexception&); // cctor
        static int getNumOfIOException();
        void displayMessage() const;

};
#endif