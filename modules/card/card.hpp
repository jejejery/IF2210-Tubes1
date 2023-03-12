#ifndef CARD_HPP_
#define CARD_HPP_
#include <iostream>
#include <vector>
using namespace std;

class GameCard{
    public:
        // default constructor
        GameCard();

        // user-defined constructor
        GameCard(int, string);

        // destructor
        ~GameCard();

        // getter
        int getNumber();
        string getColor();

        // setter
        void setNumber(int);
        void setColor(string);

    private:
        int number;
        string color;

};

class Deck{
    public:
        // default constructor
        Deck();

        // user-defined constructor
        Deck(int);

        // destructor
        ~Deck();

        // method
        void shuffleDeck();

        GameCard drawCard();

    private:
        const int deckSize;
        vector<GameCard> cards;
};

class AbilityCard{
    public:
        // default constructor
        AbilityCard();

        // user-defined constructor
        AbilityCard(vector<string>);

        // destructor
        ~AbilityCard();

        // getter
        string getAbility();

        // setter
        void setAbilities(vector<string>);

        // shuffle
        void shuffleAbilities();

    private:
        string ability;
        vector<string> abilities;
};


#endif