#include "fileexception.hpp"
using namespace std;

int FileException :: numOfFileException = 0;

FileException :: FileException(string _path) : Exception(ID)
{
    this->path = _path;
    FileException :: numOfFileException++;
} 

FileException :: FileException(const FileException& other) : Exception(other.ID)
{
    this->path = other.path;
    FileException :: numOfFileException++;
}

string FileException :: getFileException()
{
    return this->path;
}

int FileException :: getNumOfFileException()
{
    return FileException :: numOfFileException;
}

void FileException :: displayMessage() const
{
    cout << "Path '" << this->path << "' invalid." << endl;
}
