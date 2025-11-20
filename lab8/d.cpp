#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

ll base = 31;
ll mod = 1e9+9;

vector<ll> p_pow;

vector<ll> compute_hash(string str){
    int n = str.size();
    vector<ll> hash(n + 1, 0);
    p_pow.resize(n + 1, 1);
    for(int i=1; i<= n; i++){
        hash[i] = (hash[i-1] * base + (str[i - 1] - 'a' + 1)) % mod;
        p_pow[i] = (p_pow[i-1] * base) % mod;
    }
    return hash;
}

long long compute_hash_of_substrings(string s) {
    int n = s.length();
    ll h = 0;
    for (int i = 0; i < n; i++) {
        h = (h * base + (s[i] - 'a' + 1)) % mod;
    }
    return h;
}

ll compute_substring_hash(int l, int r, const vector<ll> &hash, const vector<ll> &p_pow){
    return ( (hash[r] - (hash[l] * p_pow[r - l]) % mod + mod) % mod );
}

int main(){
    int n;
    while (cin >> n && n != 0){
        map<string, int> freq;
        vector<pair<string, ll>> patterns;

        for (int i = 0; i < n; i++) {
            string pat;
            cin >> pat;
            ll h = compute_hash_of_substrings(pat);
            patterns.push_back({pat, h});
            freq[pat] = 0;
        }

        string str;
        cin >> str;
        vector<ll> hash_of_string = compute_hash(str);

        for (pair<string, ll> &p : patterns) {
            string pat = p.first;
            ll h_pat = p.second;
            int m = pat.size();
            for (int i = 0; i + m <= str.size(); i++) {
                ll h_sub = compute_substring_hash(i, i + m, hash_of_string, p_pow);
                if (h_sub == h_pat) freq[pat]++;
            }
        }

        int max_freq = 0;
        for (pair<const string, int> &p : freq)
            max_freq = max(max_freq, p.second);

        cout << max_freq << endl;

        for (pair<const string, int> &p : freq)
            if (p.second == max_freq)
                cout << p.first << endl;

    }
    return 0;
}