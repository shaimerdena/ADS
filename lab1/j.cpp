#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> zhans_sum;

    char x;
    while(cin >> x && x!='!'){
        int num;
        if(x == '+'){
            cin >> num;
            zhans_sum.push_front(num);
        }
        else if(x == '-'){
            cin >> num;
            zhans_sum.push_back(num);
        }
        else if(x == '*'){
            if(zhans_sum.empty()){
                cout << "error" << endl;
                continue;
            }
            else{
                int res = zhans_sum.front() + zhans_sum.back();
                zhans_sum.pop_front();
                if(!zhans_sum.empty()){
                    zhans_sum.pop_back();
                }
                cout << res << endl;
            }
        }
    }
}