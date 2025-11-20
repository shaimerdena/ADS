#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n;
    cin >> n;

    vector<string> tapes(n);
    for (int i = 0; i < n; i++) {
        cin >> tapes[i];
    }

    int len = s.size();
    vector<bool> dp(len + 1, false);
    dp[0] = true; 

    for (int i = 0; i < len; i++) {
        if (!dp[i]) continue; 

        for (int j = 0; j < n; j++) {
            int tlen = tapes[j].size();
            if (i + tlen <= len && s.substr(i, tlen) == tapes[j]) {
                dp[i + tlen] = true;
            }
        }
    }

    cout << (dp[len] ? "YES" : "NO") << "\n";
    return 0;
}
