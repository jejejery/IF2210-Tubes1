#ifndef CARD_HPP_
#define CARD_HPP_
#include <iostream>
#include <vector>
using namespace std;

class GameCard{
    public:
        // constructor
        GameCard();

        // destructor
        ~GameCard();

        // getter
        int get_number();
        char get_color();

        // setter
        void set_number(int);
        void set_color(char);

    private:
        vector<int> number;
        vector<char> color;

};

class AbilityCard{
    public:
        // constructor
        AbilityCard();

        // destructor
        ~AbilityCard();

        // getter
        int get_ability();

        // setter
        void set_ability(int);

    private:
        vector<int> ability;
};


#endif