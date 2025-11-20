#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll p = 31;
const ll mod = 1e9 + 7;

vector<ll> p_pow;

vector<ll> compute_hash(const string &s) {
    int n = s.size();
    vector<ll> hash(n + 1, 0);
    p_pow.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % mod;
        hash[i] = (hash[i - 1] * p + (s[i - 1] - 'a' + 1)) % mod;
    }
    return hash;
}

ll pattern_hash(string str){
    ll n = 0;
    for(int i=0; i<str.length(); i++){
        n = (n * p + (str[i] - 'a' + 1))%mod;
    }
    return n;
}

ll substring_hash(int l, int r, const vector<ll> &hash, const vector<ll> &p_pow) {
    return (hash[r] - (hash[l] * p_pow[r - l]) % mod + mod) % mod;
}

int main(){
    string str1;
    string str2;
    string ptr;
    cin >> str1 >> str2 >> ptr;

    vector<ll> hash1 = compute_hash(str1);
    vector<ll> hash2 = compute_hash(str2);
    ll pattern = pattern_hash(ptr);

    int size;
    if(str1.length() >= str2.length()){
        size = str2.length();
    }else {
        size = str1.length();
    }

    int m = ptr.length();

    int count = 0;
    for (int i = 0; i + m <= size; i++) {
        ll hash1_sub = substring_hash(i, i + m, hash1, p_pow);
        ll hash2_sub = substring_hash(i, i + m, hash2, p_pow);
        if (hash1_sub == pattern && hash2_sub == pattern) count++;
    }
    cout << count << endl;
    return 0;
}
