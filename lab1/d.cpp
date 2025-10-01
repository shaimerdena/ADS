#include <iostream>
#include <stack>
using namespace std;

int main(){
    string str;
    cin >> str;

    stack<char> st;
    
    for(auto q : str){
        if(!st.empty() && st.top() == q){
            st.pop();
        }
        else{
            st.push(q);
        }
    }
    if(st.empty()){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}