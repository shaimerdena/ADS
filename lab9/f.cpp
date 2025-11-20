#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computePrefixSums(const string &pattern){
    int m = pattern.size();
    vector<int> pi(m, 0);
    int k = 0;

    for(int i=1; i<m; i++){
        while(k > 0 && pattern[k] != pattern[i]){
            k = pi[k - 1];
        }
        if(pattern[k] == pattern[i]){
            k++;
        }
        pi[i] = k;
    }
    return pi;
}

void kmp(const string &text, const string &pattern){
    int n = text.size();
    int m = pattern.size();

    vector<int> pi = computePrefixSums(pattern);
    int q = 0;
    vector<int> res;

    for(int i=0; i<n; i++){
        while(q > 0 && pattern[q] != text[i]){
            q = pi[q - 1];
        }
        if(pattern[q] == text[i]){
            q++;
        }
        if(q == m){
            res.push_back(i - m + 2);
            q = pi[q - 1];
        }
    }
    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
}

int main(){
    string text, pattern;
    cin >> text >> pattern;

    kmp(text, pattern);
    return 0;
}