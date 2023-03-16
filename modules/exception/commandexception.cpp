#include "commandexception.hpp"
using namespace std;


int CommandException :: numOfCommandException = 0;

string CommandException :: message[] = 
{
    "Command tersebut tidak valid!",
    "Kamu tidak memiliki Ability tersebut!",
    "Semua orang telah memakai abilitynya, ability Anda tidak berguna",
    "Eits tidak bisa, kamu tidak punya kartu ability yang sudah kamu gunakan!",
    "Ability kamu telah di-disable!"
};

CommandException :: CommandException(int ID) : Exception(ID)
{
    CommandException :: numOfCommandException++;
}

CommandException :: CommandException(const CommandException& other) : Exception(other.ID)
{
    CommandException :: numOfCommandException++;
}

int CommandException :: getNumOfCommandException() 
{
    return CommandException :: numOfCommandException;
}

void CommandException :: displayMessage() const
{
    cout << CommandException :: message[this->ID] << endl;
}