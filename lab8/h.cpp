#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int k;
    cin >> k;
    vector<string> s(k);

    for (int i = 0; i < k; i++) cin >> s[i];

    sort(s.begin(), s.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });

    string base = s[0];
    string answer;

    for (int len = base.size(); len > 0; len--) {
        for (int i = 0; i + len <= base.size(); i++) {
            string sub = base.substr(i, len);
            bool found = true;

            for (int j = 1; j < k && found; j++) {
                if (s[j].find(sub) == string::npos) found = false;
            }

            if (found) {
                cout << sub << '\n';
                return 0;
            }
        }
    }

    return 0;
}
