#include "combinationcard.hpp"
using namespace std;

/*
Combo          Nilai Max   Rumus
--------       --------   --------
Pair             4.14       1.39 + kedua bobot kartu    
TwoPair          9.44 	    4.14 +  Pair1 + Pair2
ThreeKind        13.52      9.44 + ketiga bobot kartu(MAX: merah, kuning, ijo)   
Straight         19.47      13.52 + kelima bobot kartu    
Flush            25.42  	19.47 + kelima bobot kartu
FullHouse        32.05      25.42 + ketiga bobot kartu, 13 Kuning-Biru-Merah
FourKind         37,43      32.05 + keempat bobot kartu, MAX: 13 semua
StraightFlush    43.38      37.43 + kelima bobot kartu  

*/
// vector<int> CombinationCard::existingNumber {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0};

map<string,int> CombinationCard::combinationOrder{{"High_Card",1}, {"Pair",2},{"Two_Pair",3},{"Three_Kind",4},{"Straight",5},{"Flush",6},{"Full_House",7},{"Four_Kind",8},{"Straight_Flush",9}};
CombinationCard::CombinationCard(){}

CombinationCard::CombinationCard(const vector<GameCard*>& playerCards, const vector<GameCard*>& tableCards)
{
    
    // totalcards = playerCards + tableCards
    this->totalCards.insert(totalCards.end(), playerCards.begin(), playerCards.end());
    this->totalCards.insert(totalCards.end(), tableCards.begin(), tableCards.end());

    this->existingNumber = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0};
    size_t length = this->totalCards.size(); // harusnya 7 sih

    for (size_t i = 0; i < length; i++){
        existingNumber[this->totalCards[i]->get_number()-1]++;  // misal di totalcard = {1, 2, 3, 3, 4, 13, 11}
    }                                                           // di existingNumber = {1, 1, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1}

}

CombinationCard::~CombinationCard() 
{
    // delete[] existingNumber;
}

string CombinationCard::getType(){
    return this->type;
}

void CombinationCard::setType(string t) {
    this->type = t;
}

void  CombinationCard::setTotalCards(const vector<GameCard*>& playerCards, const vector<GameCard*>& tableCards){
    this->totalCards.clear();
    this->existingNumber.clear();

    this->totalCards.insert(totalCards.end(), playerCards.begin(), playerCards.end());
    this->totalCards.insert(totalCards.end(), tableCards.begin(), tableCards.end());

    this->type = "High_Card";
    this->sortTotalCards();  
    this->existingNumber = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0};
    size_t length = this->totalCards.size(); // harusnya 7 sih
    for (size_t i = 0; i < length; i++){
        existingNumber[this->totalCards[i]->get_number()-1]++;  // misal di totalcard = {1, 2, 3, 3, 4, 13, 11}
    }
        
};

void CombinationCard::set_ith_Card(int x,GameCard* gc){
    this->totalCards[x] = gc;
}
vector<GameCard*> CombinationCard::getTotalCards() const
{
    return this->totalCards;
}

vector<int> CombinationCard::getExistingNumber() const{
    return this->existingNumber;
    }

//Another Getter
vector<GameCard*> CombinationCard::getPair() const{
    vector<GameCard*> vec;
    int num = 0;
    for (int i = existingNumber.size()-1; i >= 0; i--){
        if (existingNumber[i] == 2){
            num = i+1;
            break;
        }
    }
    
    int counter = 0;
    for(int i = totalCards.size()-1; i >= 0; i--){
        if(totalCards[i]->get_number() == num){
            vec.push_back(totalCards[i]);
            counter++;
        } 
        if(counter == 2) break;

    }
    return vec;
}

vector<GameCard*> CombinationCard::getTwoPair() const{
    vector<GameCard*> vec;
    int num1, num2 = 0;
    for (int i = existingNumber.size()-1; i >= 0; i--){
        if (existingNumber[i] == 2){
            num1 = i+1;
            for (int j = i; j >= 0; i--){
                if (existingNumber[j] == 2){
                    num2 = j+1;
                    break;
                }
            }
            break;
        }
    }

    int counter = 0;
    for (int i = totalCards.size()-1; i >= 0; i--){
        if (totalCards[i]->get_number() == num1){
            vec.push_back(totalCards[i]);
            counter++;
        } else if(totalCards[i]->get_number() == num2){
            vec.push_back(totalCards[i]);
            counter++;
        }
        if (counter == 4){
            break;
        }
    }
    return vec;
}

vector<GameCard*> CombinationCard::getThreeKind() const{
    vector<GameCard*> vec;
    int num = 0;
    for (int i = existingNumber.size()-1; i >= 0; i--){
        if (existingNumber[i] == 3){
            num = i+1;
            break;
        }
    }
    
    int counter = 0;
    for(int i = totalCards.size()-1; i >= 0; i--){
        if(totalCards[i]->get_number() == num){
            vec.push_back(totalCards[i]);
            counter++;
        } 
        if(counter == 3) break;

    }
    return vec;
}
vector<GameCard*> CombinationCard::getStraight() const{
    vector<GameCard*> vc;
    int counter = 0;
    int mark = 0;
    for(int i = existingNumber.size()-1; i >= 0; i--){
        if(this->existingNumber[i] != 0) counter++;
        else counter = 0;
        if(counter == 5){
            mark = i;
            counter = 0;
            break;
        } 
    }
    for(int i = 0; i < this->totalCards.size(); i++){
        if((this->totalCards[i])->get_number() == mark){
            vc.push_back(this->totalCards[i]);
            counter++;
        }
        if(counter == 5) break;
    }
    return vc;
}



vector<GameCard*> CombinationCard::getFullHouse() const {
    vector<GameCard*> vec;
    int num = 0;
    for (int i = existingNumber.size()-1; i >= 0; i--){
        if (existingNumber[i] == 3){
            num = i+1;
            break;
        }
    }

    int counter = 0;
    for (int i = totalCards.size()-1; i >= 0; i--){
        if (totalCards[i]->get_number() == num){
            vec.push_back(totalCards[i]);
            counter++;
        } if (counter == 3){
            break;
        }
    }
    return vec;
    
}

vector<GameCard*> CombinationCard::getFourKind() const{
    vector<GameCard*> vec;
    int num = 0;
    for (int i = existingNumber.size()-1; i >= 0; i--){
        if (existingNumber[i] == 4){
            num = i+1;
            break;
        }
    }
    
    int counter = 0;
    for(int i = totalCards.size()-1; i >= 0; i--){
        if(totalCards[i]->get_number() == num){
            vec.push_back(totalCards[i]);
            counter++;
        } 
        if(counter == 4) break;

    }
    return vec;
}

vector<GameCard*> CombinationCard::getStraightFlush() const{
    // map<string,int> colour {{"Hijau",0},{"Biru",0},{"Kuning",0},{"Merah",0}};
    vector<GameCard*> gc;
    gc.push_back(this->totalCards[totalCards.size()-1]);
    for(int i = this->totalCards.size()-2; i >= 0; i++){
        if((gc.back())->get_color() != (this->totalCards[i])->get_color() || (gc.back())->get_number() - (this->totalCards[i])->get_number() > 1) gc.pop_back();
        gc.push_back(this->totalCards[i]);
        if(gc.size()==5) break;
    }
    return gc;
}


//DETECTION: 

bool CombinationCard::detectPair() const
{
    for (int i = 0; i < existingNumber.size(); i++){
        if (existingNumber[i] == 2){
            return true;
        }
    }
    return false;
}

bool CombinationCard::detectTwoPair() const
{
    int counter = 0;

    for (int i = 0; i < existingNumber.size(); i++){
        if (existingNumber[i] == 2){
            counter++;
        }
    }
    if (counter >= 2){
        return true;
    } else {
        return false;
    }
    
}

bool CombinationCard::detectThreeKind() const
{
    for (int i = 0; i < existingNumber.size(); i++){
        if (existingNumber[i] == 3){
            return true;
        }
    } 
    return false;
}

bool CombinationCard::detectStraight(pair<int, int> longestStraight) const
{
    if (longestStraight.second - longestStraight.first + 1 >= 5){
        return true;
    } else{
        return false;
    }
}

bool CombinationCard::detectFlush(pair<string, int> longestColor) const
{
    if (longestColor.second >= 5)
    {
        return true;
    } else
    {
        return false;
    }
}


bool CombinationCard::detectFullHouse() const
{
    bool pair3 = false;
    bool pair2 = false;

    for (int i = existingNumber.size()-1; i >=0; i--){
        if (existingNumber[i] == 3){
            pair3 = true;
        }
        else if (existingNumber[i] == 2) {
            pair2 = true;
        }
    }
    
    if (pair2 && pair3){
        return true;
    } else{
        return false;
    }
}

bool CombinationCard::detectFourKind() const
{
   for (int i = 0; i < existingNumber.size(); i++){
        if (existingNumber[i] == 4){
            return true;
        }
    }
    return false;
}

bool CombinationCard::detectStraightFlush(pair<string, int> longestColor, pair<int, int> longestStraight) const
{
    if(detectFlush(longestColor) && detectStraight(longestStraight)){
        return true;
    } else{
        return false;
    }

}





bool CombinationCard::operator>(const CombinationCard& cc){
    if(this->combinationOrder[this->type] > cc.combinationOrder[cc.type]) return true;
    else{
        if(this->type == "High_Card"){
            return this->sameHandlerHighCard(cc);
        }
        else if(this->type == "Pair"){
            return this->sameHandlerPair(cc);
        }
        else if(this->type == "Two_Pair"){
            return this->sameHandlerTwoPair(cc);
        }
        else if(this->type == "Three_Kind"){
            return this->sameHandlerThreeKind(cc);
        }
        else if(this->type == "Straight"){
            return this->sameHandlerStraight(cc);
        }
        else if(this->type == "Flush"){
            this->sameHandlerFlush(cc);
        }
        else if(this->type == "Full_House"){
            return this->sameHandlerFullHouse(cc);
        }
        else if(this->type == "Four_Kind"){
            return this->sameHandlerFourKind(cc);
        }
        else{//straight flush
            return this->sameHandlerStraightFlush(cc);
        }
        
    }

};
bool CombinationCard::operator<(const CombinationCard& cc){
    return !((*this) > cc);
};
bool CombinationCard::operator==(const CombinationCard& cc) const{
    return this->type == cc.type && this->totalCards == cc.totalCards;
};


bool CombinationCard::sameHandlerHighCard(const CombinationCard& cc) const{
    return *(this->totalCards.back()) > *(cc.totalCards.back());
}
bool CombinationCard::sameHandlerPair(const CombinationCard& cc) const{
    return *(getMaxValue(this->getPair())) > *(getMaxValue(cc.getPair()));
}
bool CombinationCard::sameHandlerTwoPair(const CombinationCard& cc) const{
    return *(getMaxValue(this->getTwoPair())) > *(getMaxValue(cc.getTwoPair()));
}
bool CombinationCard::sameHandlerThreeKind(const CombinationCard& cc) const{
    return *(getMaxValue(this->getThreeKind())) > *(getMaxValue(cc.getThreeKind()));
}
bool CombinationCard::sameHandlerStraight(const CombinationCard& cc) const{
    return *(getMaxValue(this->getStraight())) > *(getMaxValue(cc.getStraight()));
}
bool CombinationCard::sameHandlerFlush(const CombinationCard& cc){
    map<string,int> colour {{"Hijau",0},{"Biru",1},{"Kuning",2},{"Merah",3}};
    vector<pair<string,int>> color_counter {{"Hijau",0},{"Biru",0},{"Kuning",0},{"Merah",0}};
     string color1 = this->getLongestColor().first;
     
     for(int i = 0; i < cc.getTotalCards().size(); i++){
        if(color_counter[1].first == (cc.getTotalCards()[i])->get_color()) color_counter[1].second++;
         if(color_counter[2].first == (cc.getTotalCards()[i])->get_color()) color_counter[2].second++;
         if(color_counter[3].first == (cc.getTotalCards()[i])->get_color()) color_counter[3].second++;
         if(color_counter[4].first == (cc.getTotalCards()[i])->get_color()) color_counter[4].second++;
     };

     string color2 = "";
     int max = 0;
     for(int i = 0; i < colour.size(); i++){
        if(color_counter[i].second > max){
           max = color_counter[i].second;
           color2 = color_counter[i].first;
        }  
     }
     
     



    vector<int> flush1;
    vector<int> flush2;
        int counter = 0;
        int point1 = 0;
        int point2 = 0;
        
        for (int i = this->totalCards.size()-1; i >=0; i--){
        if ((this->totalCards[i])->get_color() == color1){ 
            flush1.push_back(this->totalCards[i]->get_number());
            counter++;
            }
        if(counter == 5) break;
        }
        counter = 0;

        for (int i = cc.totalCards.size()-1; i >=0; i--){
        if ((cc.totalCards[i])->get_color() == color2){ 
            flush2.push_back(cc.totalCards[i]->get_number());
            counter++;
            }
        if(counter == 5) break;
        }

        //Komparasi elemen:
        for(int i = 0; i < 5; i++){
            if(flush1[i] != flush2[i]) return flush1[i] > flush2[i];
        }

        return colour[color1] > colour[color2];    
        
    }

bool CombinationCard::sameHandlerFullHouse(const CombinationCard& cc) const{
    return *(getMaxValue(this->getFullHouse())) > *(getMaxValue(cc.getFullHouse()));
}
bool CombinationCard::sameHandlerFourKind(const CombinationCard& cc) const{
    return *(getMaxValue(this->getFourKind())) > *(getMaxValue(cc.getFourKind()));
}
bool CombinationCard::sameHandlerStraightFlush(const CombinationCard& cc) const{
   return *(this->getStraightFlush().front()) > *(cc.getStraightFlush().front());
}

bool CombinationCard::compareNumber(GameCard* gc1, GameCard* gc2){
    return gc1->get_number() > gc2->get_number();
}

bool CombinationCard::compareColor(GameCard* gc1, GameCard* gc2){
    return gc1->get_color() < gc2->get_color();
}

bool CombinationCard::compareCard(GameCard* gc1, GameCard* gc2){
    return *gc1 < *gc2;
}



// sorting in descending order

void CombinationCard::sortTotalCards(){ // sort descending
    GameCard* temp;
    for(int i = 0; i < this->totalCards.size()-1; i++){
        for(int j = 0; j < this->totalCards.size()-1; j++){
            // cout << *(this->totalCards[j]);
            if(*(this->totalCards[j]) > *(this->totalCards[j+1])){
                temp = this->totalCards[j];
                this->totalCards[j] = this->totalCards[j+1];
                this->totalCards[j+1] = temp;
            } 
        }
    }
};

void CombinationCard::sortByNumber(){
    sort(this->totalCards.begin(), this->totalCards.end(), compareNumber);
     
}

void CombinationCard::sortByNumber(int begin, int size){
    sort(this->totalCards.begin() + begin, this->totalCards.begin() + begin + size, compareNumber);
}

// sorting in descending order by card_weight
void CombinationCard::sortByColor(){
    sort(this->totalCards.begin(), this->totalCards.end(), compareColor);
}

pair<string, int> CombinationCard::getLongestColor()
{
    string color;
    int counter = 0;
    int length = 0;
    this->sortByColor();

    for (int i = 1; i < this->totalCards.size(); i++){
        if (this->totalCards[i]->get_color() == this->totalCards[i-1]->get_color()){
            counter++;
        } else{
            counter = 0;
        }

        if (counter > length){
            color = this->totalCards[i]->get_color();
            length = counter;
        }
    }
    length++;
    this->sortTotalCards();
    return make_pair(color, length);
}


pair<int, int> CombinationCard::getLongestStraight()
{
    int counter = 0;
    int length = 0;
    int bottomValue = 0;
    this->sortByNumber();
    for (int i = 1; i < this->totalCards.size(); i++){
        if (this->totalCards[i]->get_number() == (this->totalCards[i-1]->get_number()-1)){
            counter++;
        } else if (this->totalCards[i]->get_number() == (this->totalCards[i-1]->get_number())){
            continue;
        } else{
            counter = 0;
        }

        if (counter > length){
            length = counter;
            bottomValue = this->totalCards[i]->get_number();
        }
    }
    this->sortTotalCards();
    return make_pair(bottomValue, bottomValue+length); // misal straight 3, 4, 5, 6, 7, then bottomValue = 3, topvalue(bottom+length) = 7
}

void CombinationCard::decideBestCombination(){
    //MENCARI KOMBINASI TERBAIK
    if(this->detectStraightFlush(this->getLongestColor(),this->getLongestStraight())){
        this->type = "Straight_Flush";
    }
    else if(this->detectFourKind()){
        this->type = "Four_King";
    }
    else if(this->detectFullHouse()){
        this->type = "Full_House";
    }
    else if(this->detectFlush(this->getLongestColor())){
        this->type = "Flush";
    }
    else if(this->detectStraight(this->getLongestStraight())){
        this->type = "Straight";
    }
    else if(this->detectThreeKind()){
        this->type = "Three_Kind";
    }
    else if(this->detectTwoPair()){
        this->type = "Two_Pair";
    }
    else if(this->detectPair()){
        this->type = "Pair";
    }
    else{
        this->type = "High_Card";
    }   
}


void CombinationCard::debug(){
    cout << "Total Cards: " << endl;
    for(int i = 0; i < this->totalCards.size(); i++){
        cout << i+1 << ". " << *(this->totalCards[i]) << endl;
    }
}