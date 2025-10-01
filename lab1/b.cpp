#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    stack<int> st;
    int num;
    cin >> num;
    vector<int> result(num);
    vector<int> age(num);

    for(int i=0; i<num; i++){
        cin >> age[i];

    }
    for(int i=0; i<num; i++){
        while(!st.empty() && st.top()>age[i]){
            st.pop();
        }
        if(st.empty()){
            result[i] = -1;
        }
        else{
            result[i] = st.top();
        }
        st.push(age[i]);
    }

    for(int i=0; i<num; i++){
        cout << result[i] << " ";
    }

    return 0;
}