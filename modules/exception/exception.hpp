#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Exception {
    protected:
        static int numOfException;
        const int ID;
    public:
        // not required default ctor (no list of exception)
        Exception(int); // user-defined ctor
        Exception(const Exception&); // cctor

        static int getNumOfException(); // numOfException getter
        int getID() const; 

        virtual void displayMessage() const = 0; // message display

};
#endif