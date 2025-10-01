#include <iostream>
#include <deque>
using namespace std;

int main(){
    int num;
    cin >> num;
    string str;
    cin >> str;

    deque<int> saka;
    deque<int> kat;

    for(int i=0; i<num; i++){
        if(str[i] == 'S'){
            saka.push_back(i);
        }
        else{
            kat.push_back(i);
        }
    }
    int x;
    while(!saka.empty() && !kat.empty()){
        if(saka.front() > kat.front()){
            saka.pop_front();
            x = kat.front();
            kat.pop_front();
            kat.push_back(x+num);
        }
        else{
            kat.pop_front();
            x = saka.front();
            saka.pop_front();
            saka.push_back(x+num);
        }
    }
    if(saka.empty()){
        cout << "KATSURAGI" << endl;
    }
    else{
        cout << "SAKAYANAGI" << endl;
    }
    return 0;
}