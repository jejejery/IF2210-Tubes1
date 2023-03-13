#ifndef CARD_HPP_
#define CARD_HPP_
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Card{
   public:
   Card();
   ~Card();
   virtual int value() const;
};

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



class AbilityCard : public Card{
    private:
        string ability;

    public:
        // default constructor
        AbilityCard(); //no param
        AbilityCard(string); //param

        // destructor
        ~AbilityCard();

        // getter
        string get_ability();

        // setter
        void set_ability(string);

        //Operator Assignment
        AbilityCard& operator=(const AbilityCard&);

        
        //SPEK TUBES
        int value() const;

        //debug
        friend ostream& operator<<(ostream&, AbilityCard&);
        
};

// class AbilityCard{
//     public:
//         // default constructor
//         AbilityCard();

//         // user-defined constructor
//         AbilityCard(vector<string>);

//         // destructor
//         ~AbilityCard();

//         // getter
//         string getAbility();

//         // setter
//         void setAbilities(vector<string>);

//         // shuffle
//         void shuffleAbilities();

//     private:
//         string ability;
//         vector<string> abilities;
// };

class CombinationCard : public GameCard {
    private:
        vector<GameCard*> player_cards;
        vector<GameCard*> table_cards;
        int value;
        int constant;
        string type;
    public:
        // function to get the value and set type
        void setValue(int);
        void setType(string);

        // return int value of the highest combination
        int getHighestCombination();

        // return double constant of the highest combination 
        double getHighestCombiType();

        // to compare 
        CombinationCard compare();
};

#endif