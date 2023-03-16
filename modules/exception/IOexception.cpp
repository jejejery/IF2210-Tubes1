#include "IOexception.hpp"
using namespace std;

int IOexception :: numOfIOException = 0;

string IOexception :: message[] = 
{
    "Input angka tidak sesuai!",
    "Indeks angka diluar batas!",
};

IOexception :: IOexception(int ID) : Exception(ID)
{
    IOexception :: numOfIOException++;
} 

IOexception :: IOexception(const IOexception& other) : Exception(other.ID)
{
    IOexception :: numOfIOException++;
}

int IOexception :: getNumOfIOException()
{
    return IOexception :: numOfIOException;
}

void IOexception :: displayMessage() const 
{
    cout << IOexception :: message[this->ID] << endl;
}
