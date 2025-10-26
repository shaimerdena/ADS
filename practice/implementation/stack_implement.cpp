#include <iostream>
using namespace std;

const int max_size = 100;

class Stack {
private:
    int arr[max_size];
    int top;
public:
    Stack(){
        top = -1;
    }
    bool empty() {
        return top == -1;
    }
    bool full(){
        return top == max_size - 1;
    }
    void push(int x){
        if(full()){
            cout << "overflow" << endl;
        }
        else{
            arr[++top] = x;
        }
    }
    void pop(){
        if(empty()){
            cout << "underflow" << endl;
        }
        else{
            --top;
        }
    }
    int peek(){
        if(empty()){
            return -1;
        }
        else{
            return arr[top];
        }
    }
};

int main(){
    Stack st;
    st.push(1);
    cout << st.peek() << endl;
}