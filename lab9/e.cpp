#include <iostream>
#include <vector>
using namespace std;

int max_overlap(const string &text){
    int n = text.size();
    vector<int> p(n, 0);
    int j = 0;

    for(int i=1; i<n; i++){
        while(j > 0 && text[i] != text[j]){
            j = p[j - 1];
        }
        if(text[i] == text[j]){
            j++;
        }
        p[i] = j;
    }
    return p[n-1];
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        string s;
        int k;
        cin >> s >> k;
        cout << s.length() + (s.length() - max_overlap(s)) * (k - 1) << endl;
    }
    return 0;
}