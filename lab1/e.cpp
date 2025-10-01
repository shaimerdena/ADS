#include <iostream>
#include <deque>
using namespace std;

deque<int> nums(){
    deque<int> dq;
    for(int i=0; i<5; i++){
        int num;
        cin >> num;
        dq.push_back(num);
    }
    return dq;
}

int main(){
    deque<int> boris = nums();
    deque<int> nursik = nums();
    int counter = 0;

    while(!boris.empty() && !nursik.empty()){
        int b = boris.front();
        int n = nursik.front();

        boris.pop_front();
        nursik.pop_front();

        if((b>n && !(b==9 && n==0)) || (b==0 && n==9)){
            boris.push_back(b);
            boris.push_back(n);
        }
        else{
            nursik.push_back(b);
            nursik.push_back(n);
        }

        counter++;

        if(counter == 1000000){
            break;
        }
    }
    if(nursik.empty()){
        cout << "Boris" << " " << counter << endl;
    }
    else if(boris.empty()){
        cout << "Nursik" << " " << counter << endl;
    }
    else{
        cout << "blin nichya" << endl;
    }
    return 0;
}