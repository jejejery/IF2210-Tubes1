#include "../modules/card/card.hpp"
#include "../modules/card/card.cpp"
#include <iostream>
using namespace std;


int main(){
    Card *gc1 = new Card();
    GameCard gc2(12,"Biru");
    cout << hex << gc1->value() << endl;
    cout << hex << gc1->value() << endl;
    cout << hex << gc2.value() << endl;
    AbilityCard ab1("jem");
    cout << ab1 << endl;
    ab1.set_ability("hehe");
    cout << ab1 << endl;

    GameCard *gc3 = new GameCard(12,"Merah");
    cout << "Bobot gc2: " << gc2.card_weight() << endl;
    cout << "Bobot gc3: " << gc3->card_weight() << endl;
    cout << "gc2 == gc3: " << (gc2 == *gc3) << endl;
    delete gc3;
    return 0;
}