#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computePrefixSums(const string &pattern){
    int m = pattern.size();
    vector<int> pi(m, 0);
    int k = 0;

    for(int i=1; i<m; i++){
        while (k > 0 && pattern[k] != pattern[i])
            k = pi[k - 1];
        if (pattern[k] == pattern[i])
            k++;
        pi[i] = k;
    }
    return pi;
}

int KMP(string text, string pattern){
    int n = text.size();
    int m = pattern.size();
    int limit = n + m;
    string original = text;

    vector<int> pi = computePrefixSums(pattern);
    int q = 0;
    int count = 1;

    if(n > m){
        for (int i = 0; i < text.size(); i++) {
            while (q > 0 && pattern[q] != text[i])
                q = pi[q - 1];
            if (pattern[q] == text[i])
                q++;
            if (q == m)
                return 1;
        }
        return -1;
    }

    while (text.size() <= limit) {
        text += original;
        count++;
        q = 0;
        for (int i = 0; i < text.size(); i++) {
            while (q > 0 && pattern[q] != text[i])
                q = pi[q - 1];
            if (pattern[q] == text[i])
                q++;
            if (q == m)
                return count;
        }
    }
    return -1;
}

int main(){
    string text;
    string pattern;
    cin >> text >> pattern;
    cout << KMP(text, pattern) << endl;
    return 0;
}