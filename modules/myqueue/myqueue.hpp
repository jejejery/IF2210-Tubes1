#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <class T>
class myQueue{
    private:
    vector<T> theQueue;
    const int maxCapacity;

    public:
    myQueue(int max):maxCapacity(max){}; //queue kosong
    myQueue(vector<T> v):maxCapacity(v.size()){
        for(int i = 0; i < v.size(); v++) this->theQueue.push_back(v[i]);
    };
    ~myQueue(){};

    //Copy-Paste operasi dasar queue
    bool isEmpty() const{
        return this->theQueue.empty();
    };
    int size() const{
        return this->theQueue.size();
    };

    int get_max_capacity() const{
        return this->maxCapacity;
    }
    void swapping(const myQueue<T>& other_queue){
        this->theQueue.swap(other_queue.theQueue);
    };
    T front() const{
        return this->theQueue.front();
    };
    T back() const{
        return this->theQueue.back();
    };
    void enqueue(T el){
        this->theQueue.push_back(el);
    };
    void dequeue(){
        this->theQueue.erase(this->theQueue.begin());
    };

    void requeue(){ // Memindahkan elemen pertama ke elemen 
    //BEFORE: p1 p2 p3 p4 p5 p6 p7
    //AFTER: p2 p3 p4 p5 p6 p7 p1
        this->enqueue(this->front());
        this->dequeue;
    }

    //Advanced queue operation
    // void reverse(){
    //     stack<T> Stack;
    // while (!this->theQueue.empty()) {
    //     Stack.push(front());
    //     dequeue();
    // }
    // while (!Stack.empty()) {
    //     enqueue(Stack.top());
    //     Stack.pop();
    // }
    // }

    void replace_queue(vector<T> another_queue){
        theQueue.clear();
        for(int i = 0; i < another_queue.size() ; i++){
            this->enqueue(another_queue[i]);
        }
    }

    void debugging(){
        for(int i = 0; i<this->theQueue.size(); i++) cout << this->theQueue[i] << ' ';
    }
    
};

//GenericFunction, Tipe T: Pointer, asumsi tidak kosong


#endif
