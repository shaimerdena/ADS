#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdint>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll P1 = 31;
const ll P2 = 37;
const int MAXN = 2002;

vector<ll> h1(MAXN, 0), h2(MAXN, 0);
vector<ll> p1(MAXN, 1), p2(MAXN, 1);

pair<ll, ll> get_hash(int l, int r) {
    ll x1 = (h1[r] - h1[l] * p1[r - l]) % MOD1;
    ll x2 = (h2[r] - h2[l] * p2[r - l]) % MOD2;
    if (x1 < 0) x1 += MOD1;
    if (x2 < 0) x2 += MOD2;
    return {x1, x2};
}

void solve() {
    fast
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        h1[i + 1] = (h1[i] * P1 + (s[i] - 'a' + 1)) % MOD1;
        h2[i + 1] = (h2[i] * P2 + (s[i] - 'a' + 1)) % MOD2;
    }

    unordered_set<uint64_t> uniq;
    for (int len = 1; len <= n; len++) {
        for (int j = 0; j + len <= n; j++) {
            pair<ll, ll> p = get_hash(j, j + len);
            ll x1 = p.first;
            ll x2 = p.second;
            uint64_t key = ((uint64_t)x1 << 32) | (uint64_t)x2;
            uniq.insert(key);
        }
    }

    cout << uniq.size();
}

int main() {
    fast
    for (int i = 1; i < MAXN; i++) {
        p1[i] = (p1[i - 1] * P1) % MOD1;
        p2[i] = (p2[i - 1] * P2) % MOD2;
    }
    solve();
    return 0;
}