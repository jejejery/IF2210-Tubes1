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
        // int count;  // jumlah pemain
        // string amount;  // in case: input dalam string, ex ="tiga"
        // string fileName; // nama file
        // string line; // jenis kartu
    public:
        // not required default ctor (no list of exception)
        Exception(int); // user-defined ctor
        Exception(const Exception&); // cctor

        static int getNumOfException(); // numOfException getter
        int getID() const; 
        // int getCount() const; // count getter

        virtual void displayMessage() const = 0; // message display

};
#endif