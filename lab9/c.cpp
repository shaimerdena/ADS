#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int kmp(const string &s, const string &pattern){
    if(s == pattern) return 0;
    string doubled = s + s;
    int n = doubled.size();
    int m = pattern.size();

    vector<int> p = prefix_function(doubled);
    int j = 0;

    for(int i=0; i<n; i++){
        while(j > 0 && doubled[i] != pattern[j]){
            j = p[j - 1];
        }
        if(doubled[i] == pattern[j]){
            j++;
        }
        if(j == m){
            return m - (i - m + 1);
        }
    }
    return -1;
}

int main(){
    string s, pattern;
    cin >> s >> pattern;
    cout << kmp(s, pattern) << endl;
    return 0;
}