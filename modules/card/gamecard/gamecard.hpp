#ifndef GAMECARD_HPP_
#define GAMECARD_HPP_

#include "../card.hpp"
class GameCard : public Card{
    private:
        // int number;
        // string color;
        pair<int,string> card_identity;

    public:
        // default constructor
        GameCard();

        // user-defined constructor
        GameCard(int, string);

        // destructor
        ~GameCard();

        // getter
        int get_number() const;
        string get_color() const;

        // setter
        void set_number(int);
        void set_color(string);

        //Operator assignment
        GameCard& operator=(const GameCard&);
        bool operator>(const GameCard&);
        bool operator<(const GameCard&);
        bool operator==(const GameCard&);
        friend ostream& operator<<(ostream& os, const GameCard& gc);

        //SPEK TUBES
        float card_weight() const; // Menghitung value high card
        int value() const;

};

#endif