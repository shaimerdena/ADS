#include <iostream>
#include <stack>
using namespace std;

int main(){
    string str1;
    string str2;
    cin >> str1 >> str2;
    
    stack<char> st1;
    stack<char> st2;

    for(int i=0; i<str1.length(); i++){
        if(str1[i] != '#'){
            st1.push(str1[i]);
        }
        else{
            st1.pop();
        }
    }

    for(int i=0; i<str2.length(); i++){
        if(str2[i] != '#'){
            st2.push(str2[i]);
        }
        else{
            st2.pop();
        }
    }

    if(st1 == st2) cout << "YES" << endl;
    else cout << "NO" << endl;
}