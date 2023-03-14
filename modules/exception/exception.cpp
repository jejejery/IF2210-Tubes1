#include "exception.hpp"
using namespace std;

int Exception :: numOfException = 0;

Exception :: Exception(int ID) : ID(ID)
{
    Exception :: numOfException++;
}

Exception :: Exception(const Exception& other) : ID(other.ID)
{
    Exception :: numOfException++;
}

int Exception :: getNumOfException()
{
    return Exception :: numOfException;
}

int Exception :: getID() const
{
    return this->ID;
}