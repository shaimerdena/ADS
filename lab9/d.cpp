#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int prefix_suffix_match(const string &text, const string &pattern){
    string added = pattern + "#" + text;
    int k = added.size();
    int j = 0;
    vector<int> p(k);

    for(int i = 1; i < k; i++){
        while (j > 0 && added[i] != added[j])
            j = p[j - 1];
        if (added[i] == added[j])
            j++;
        p[i] = j;
    }
    return p[k - 1];
}

int main(){
    string text;
    cin >> text;
    text[0] = tolower(text[0]);

    int cities;
    cin >> cities;

    int best = 0;
    vector<string> winners;
    int score = 0;

    for(int i=0; i<cities; i++){
        string city;
        cin >> city;
        city[0] = tolower(city[0]);
        score = prefix_suffix_match(text, city);
        if (score > best){
            best = score;
            winners.clear();
            city[0] = toupper(city[0]);
            winners.push_back(city);
        }     
        else if (score == best){
            city[0] = toupper(city[0]);
            winners.push_back(city);
        }    
    }
    if(best == 0){
        cout << 0 << endl;
    }
    else{
        cout << winners.size() << endl;
        for(int i=0; i<winners.size(); i++){
            
            cout << winners[i] << endl;
        }
    }
    return 0;
}