#include "../modules/myqueue/myqueue.hpp"
// #include "../modules/myqueue/myqueue.cpp"

#include <iostream>
using namespace std;

int main(){
    myQueue<int> hehe;
    hehe.enqueue(10);
    hehe.enqueue(20);
    hehe.enqueue(30);
    hehe.debugging();
    hehe.reverse();
    cout << endl;
    hehe.debugging();
    return 0;
}