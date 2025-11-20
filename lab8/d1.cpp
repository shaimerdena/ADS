#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> find_patterns(vector<string> &patterns, string text) {
    vector<string> result;
    int max_freq = 0;

    for (int i = 0; i < patterns.size(); i++) {
        string pattern = patterns[i];
        string s = pattern + "#" + text;
        vector<int> prefix(s.size(), 0);

        for (int j = 1; j < s.size(); j++) {
            int k = prefix[j - 1];
            while (k > 0 && s[j] != s[k]) {
                k = prefix[k - 1];
            }
            if (s[j] == s[k]) k++;
            prefix[j] = k;
        }

        int count = 0;
        for (int j = 0; j < prefix.size(); j++) {
            if (prefix[j] == pattern.size()) count++;
        }

        if (count > max_freq) {
            max_freq = count;
            result.clear();
            result.push_back(to_string(max_freq));
            result.push_back(pattern);
        } else if (count == max_freq) {
            result.push_back(pattern);
        }
    }

    return result;
}

int main() {
    int n;
    vector<string> patterns;
    vector<string> output;

    while (cin >> n && n != 0) {
        patterns.clear();
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            patterns.push_back(temp);
        }

        string text;
        cin >> text;
        output = find_patterns(patterns, text);

        for (int i = 0; i < output.size(); i++) {
            cout << output[i] << endl;
        }
    }

    return 0;
}
