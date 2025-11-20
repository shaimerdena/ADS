#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdint>
using namespace std;
using ll = long long;

ll base1 = 31;
ll mod1 = 1e9 + 7;
ll base2 = 37;
ll mod2 = 1e9 + 9;

int main(){
    string str;
    cin >> str;
    int n = str.size();

    vector<ll> h1(n+1,0), p1pow(n+1,1);
    vector<ll> h2(n+1,0), p2pow(n+1,1);

    for(int i=1;i<=n;i++){
        p1pow[i] = (p1pow[i-1]*base1) % mod1;
        p2pow[i] = (p2pow[i-1]*base2) % mod2;
        h1[i] = (h1[i-1]*base1 + (str[i-1]-'a'+1)) % mod1;
        h2[i] = (h2[i-1]*base2 + (str[i-1]-'a'+1)) % mod2;
    }

    unordered_set<uint64_t> distinct_substrings;

    for(int i=1; i <= str.size(); i++){
        for(int j=0; j <= str.size() - i; j++){
            int l = j;
            int r = j + i - 1;
            ll x1 = (h1[r+1] - (h1[l]*p1pow[r-l+1])%mod1 + mod1) % mod1;
            ll x2 = (h2[r+1] - (h2[l]*p2pow[r-l+1])%mod2 + mod2) % mod2;
            uint64_t combined = ((uint64_t)x1 << 32) ^ (uint64_t)x2;
            distinct_substrings.insert(combined);
        }
    }
    cout << distinct_substrings.size() << endl;
    return 0;
}