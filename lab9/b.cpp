#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computePrefixFunction(const string &pattern){
    int m = pattern.size();
    vector<int> pi(m, 0);
    int k = 0;
    
    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[k] != pattern[i])
            k = pi[k - 1];
        if (pattern[k] == pattern[i])
            k++;
        pi[i] = k;
    }
    return pi;
}

int KMP(const string &text, const string &pattern){
    int n = text.size();
    int m = pattern.size();

    vector<int> pi = computePrefixFunction(pattern);
    int q = 0;
    int count = 0;

    for(int i=0; i < n; i++){
        while (q > 0 && pattern[q] != text[i])
            q = pi[q - 1];
        if (pattern[q] == text[i])
            q++;
        if (q == m) {
            count++;
            q = pi[q - 1]; 
        }
    }
    return count;
}

int main(){
    string pattern;
    int num;
    string text;
    cin >> pattern >> num >> text;
    int count = KMP(text, pattern);
    if(count >= num){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}