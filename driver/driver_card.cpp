#include "../modules/card/card.hpp"
#include "../modules/card/card.cpp"
#include <iostream>
using namespace std;


int main(){
    Card *gc1 = new Card();
    GameCard gc2(131,"Biru");
    cout << hex << gc1->value() << endl;
    cout << hex << gc1->value() << endl;
    cout << hex << gc2.value() << endl;
    AbilityCard ab1("jem");
    cout << ab1 << endl;
    ab1.set_ability("hehe");
    cout << ab1 << endl;
    return 0;
}