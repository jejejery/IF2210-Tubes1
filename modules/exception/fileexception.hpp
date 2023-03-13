#ifndef FILE_EXCEPTION_HPP
#define FILE_EXCEPTION_HPP
#include "exception.hpp"
#include <iostream>
#include <string> 
using namespace std;  

class FileException : public Exception
{
    protected:
        static int numOfFileException;
        // static string message[];
        string path;
    
    public:
        FileException(int); // ctor 
        // ~FileException();

        static int getNumOfFileException();
        void displayMessage();
};
#endif