#ifndef CARD_HPP_
#define CARD_HPP_
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

//Generic Function, Tipe Pointer
template <class T>
T* getMaxValue(vector<T*> vec){
   T* max = vec[0];
    for(int i = 0; i < vec.size(); i++){
        if(i == 0); //Do Nothing;
        else{
            if(*max < *(vec[i])) max = vec[i];
        }
    }
    return max;
}

class Card{
   public:
   Card();
   ~Card();
   virtual int value() const;
};


#endif