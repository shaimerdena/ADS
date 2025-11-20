#include <iostream>
#include <vector>
using namespace std;

int counting(const string &pattern){
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
    return m - pi[m-1];
}

int main(){
    string text;
    cin >> text;

    cout << counting(text) << endl;
    return 0;
}