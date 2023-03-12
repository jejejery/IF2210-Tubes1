#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <class T>
class myQueue{
    private:
    vector<T> theQueue;

    public:
    myQueue(){}; //queue kosong
    myQueue(vector<T> v){
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

    //Advanced queue operation
    void reverse(){
        stack<T> Stack;
    while (!this->theQueue.empty()) {
        Stack.push(front());
        dequeue();
    }
    while (!Stack.empty()) {
        enqueue(Stack.top());
        Stack.pop();
    }
    }

    void debugging(){
        for(int i = 0; i<this->theQueue.size(); i++) cout << this->theQueue[i] << ' ';
    }
    
};
