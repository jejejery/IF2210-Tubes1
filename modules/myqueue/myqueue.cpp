// #include "myqueue.hpp"
// using namespace std;

// template<class T>
// myQueue<T>::myQueue(){};//queue kosong

// template<class T>
// myQueue<T>::myQueue(vector<T> v){
//     for(int i = 0; i < v.size(); v++) this->theQueue.push_back(v[i]);
// };

// template<class T>
// myQueue<T>::~myQueue(){};

// //Copy-Paste operasi dasar queue
// template<class T>
// bool myQueue<T>::isEmpty() const{
//      return this->theQueue.empty();
// };

// template<class T>
// int myQueue<T>::size() const{
//     return this->theQueue.size();
// };

// template<class T>
// void myQueue<T>::swapping(const myQueue<T>& other_queue){
//     this->theQueue.swap(other_queue.theQueue);
// };

// template<class T>
// T myQueue<T>::front() const{
//     return this->theQueue.front();
// }

// template<class T>
// T myQueue<T>::back() const{
//     return this->theQueue.back();
// };

// template<class T>
// void myQueue<T>::enqueue(T el){
//     this->theQueue.push_back(el);
// };

// template<class T>
// void myQueue<T>::dequeue(){
//     this->theQueue.erase(this->theQueue.begin());
// };

// //Advanced queue operation
// template<class T>
// void myQueue<T>::reverse()
// {
//     stack<T> Stack;
//     while (!this->theQueue.empty()) {
//         Stack.push(front());
//         dequeue();
//     }
//     while (!Stack.empty()) {
//         enqueue(Stack.top());
//         Stack.pop();
//     }
// }

// template <class T>
// void myQueue<T>::debug(){
//     for(int i = 0; i<this->theQueue.size(); i++) cout << this->theQueue << ' ';
// }