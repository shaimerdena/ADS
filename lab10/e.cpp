#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t; cin >> t;
            a[i][j] = (t != 0);
        }
    }

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        --x; --y; --z;
        if (a[x][y] && a[x][z] && a[y][z]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}