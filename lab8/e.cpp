#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    string s = "";
    for (int i = 1; i <= n; i++) {
        long long diff = p[i] - p[i - 1];
        long long val = diff / (1LL << (i - 1)); // 2^(i-1)
        s += char(val + 97);
    }

    cout << s << endl;
    return 0;
}
