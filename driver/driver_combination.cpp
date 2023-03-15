// #include "../modules/card/card.hpp"
#include "../modules/card/card.cpp"
// #include "../modules/card/gamecard/gamecard.hpp"
#include "../modules/card/gamecard/gamecard.cpp"
// #include "../modules/card/combinationcard/combinationcard.hpp"
#include "../modules/card/combinationcard/combinationcard.cpp"
// #include "../modules/card/combinationcard/pair.hpp"
#include "../modules/card/combinationcard/pair.cpp"
// #include "../modules/card/combinationcard/twopair.hpp"
#include "../modules/card/combinationcard/twopair.cpp"
// #include "../modules/card/combinationcard/threekind.hpp"
#include "../modules/card/combinationcard/threekind.cpp"
// #include "../modules/card/combinationcard/straight.hpp"
#include "../modules/card/combinationcard/straight.cpp"
// #include "../modules/card/combinationcard/flush.hpp"
#include "../modules/card/combinationcard/flush.cpp"
// #include "../modules/card/combinationcard/straightflush.hpp"
#include "../modules/card/combinationcard/straightflush.cpp"
// #include "../modules/card/combinationcard/fullhouse.hpp"
#include "../modules/card/combinationcard/fullhouse.cpp"
// #include "../modules/card/combinationcard/fourkind.hpp"
#include "../modules/card/combinationcard/fourkind.cpp"

#include <iostream>
#include <string>
using namespace std;


int main(){
    vector<GameCard*> player = {new GameCard(13, "Merah"), new GameCard(12, "Merah")};
    vector<GameCard*> table = {new GameCard(11, "Merah"), new GameCard(10, "Merah"), new GameCard(9, "Merah"), new GameCard(9, "Kuning"), new GameCard(10, "Hijau")};

    CombinationCard* combi = new CombinationCard(player, table);

    cout << "susunan kartu: " << endl;
    for (int i = 0; i < 7; i++){
        cout << combi->getTotalCards()[i]->get_number() << " ";
        cout << combi->getTotalCards()[i]->get_color() << endl;
    }

    cout << "susunan elemen: ";
    for (int i = 0; i < 13; i++){
        cout << CombinationCard::existingNumber[i] << " ";
    } cout << endl;


    cout << "ada angka berurutan mulai dari " << combi->getLongestStraight().first << " sampai " << combi->getLongestStraight().second << endl;
    cout << "ada kartu warna " << combi->getLongestColor().first << " sebanyak " << combi->getLongestColor().second << endl;

    
    if (Pair::detectPair()){cout << "pair" << endl;} // ada 2 kartu 10, ada 2 kartu 9, ada pair
    if (TwoPair::detectTwoPair()){cout << "two pair" << endl;} // ada 2 kartu 10 dan 9, double pair
    if (ThreeKind::detectThreeKind()){cout << "three of a kind" << endl;} // gaada 
    if (Straight::detectStraight(combi->getLongestStraight())){cout << "straight" << endl;} // ada straight 9-13
    if (Flush::detectFlush(combi->getLongestColor())){cout << "flush" << endl;} // ada flush merah
    if (FullHouse::detectFullHouse()){cout << "fullHouse" << endl;} // gaada fullhouse
    if (FourKind::detectFourKind()){cout << "four of a kind" << endl;} // gaada four kind
    if (StraightFlush::detectStraightFlush(combi->getLongestColor(), combi->getLongestStraight())){cout << "straight flush (belum perfect)" << endl;} // ada straight, ada flush, tpi belum perfect

    return 0;
}