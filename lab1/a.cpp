#include <iostream>
#include <deque>
using namespace std;

deque<int> rotation(int number){
    deque<int> cards;
    for(int i=number; i>0; i--){
        cards.push_front(i);
        for(int j=0; j<i; j++){
            int x = cards.back();
            cards.pop_back();
            cards.push_front(x);
        }
    }
    return cards;
}

int main(){
    int num;
    cin >> num;
    for(int i=0; i<num; i++){
        int x;
        cin >> x;
        deque<int> dq = rotation(x);
        for(int i=0; i<x; i++){
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
    }
    return 0;
}