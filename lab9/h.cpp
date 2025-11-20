#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(const string &s){
    int n = s.size();
    vector<int> pi(n, 0);
    int j = 0;

    for(int i=1; i<n; i++){
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}


int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi = prefix_function(s);
    
    int count = 0;

    for(int i=0; i<n-1; i++){
        int len_a = i + 1;
        if(2 * len_a < n){
            bool ok = true;
            for(int j=0; j<len_a; j++){
                if(s[j] != s[len_a + j]){
                    ok = false;
                    break;
                }
            }
            if(ok) count++;
        }
    }
    
    cout << count << endl;
    return 0;
}