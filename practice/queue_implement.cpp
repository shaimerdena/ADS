#include <iostream>
using namespace std;

const int max_size = 100;

class Queue{
private: 
    int arr[max_size];
    int head;
    int tail;
public:
    Queue(){
        head = -1;
        tail = -1;
    }
    bool empty(){ return head == tail; }
    bool full(){return tail == max_size-1; }

    void push(int x){
        if(full()){
            cout << "overflow" << endl;
        }
        else{
            arr[++tail] = x;
        }
    }
    void pop(){
        if(empty()){
            cout << "underflow" << endl;
        }
        else{
            ++head;
        }
    }
    int front(){
        if(empty()){
            return -1;
        }
        else{
            return arr[head+1];
        }
    }
    int back(){
        if(empty()){
            return -1;
        }
        else{
            return arr[tail];
        }
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.back() << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.back() << endl;
    cout << q.front() << endl;
}