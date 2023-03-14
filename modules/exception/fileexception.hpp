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
        string path;
    
    public:
        FileException(string); // user-defined ctor  
        FileException(const FileException&);
        static int getNumOfFileException();
        string getFileException();
        void displayMessage() const;
};
#endif