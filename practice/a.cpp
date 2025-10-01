#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char top;
        for(auto c:s){
            if(!st.empty()){
                top = st.top();
            }
            if(c == '(' || c=='{' || c=='['){
                st.push(c);
            }
            else if((top == '(' && c == ')') || 
            (top == '{' && c == '}') || 
            (top=='[' && c == ']')){
                st.pop();
            }
        }
        return st.empty();

    }
};