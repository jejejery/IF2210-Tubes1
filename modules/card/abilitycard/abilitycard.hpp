#ifndef ABILITYCARD_HPP_
#define ABILITYCARD_HPP_

#include "../card.hpp"

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

#endif