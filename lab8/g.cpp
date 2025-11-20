#include <iostream>
#include <vector>
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

ll compute_substring_hash(int l, int r, const vector<ll> &hash, const vector<ll> &p_pow){
    return ( (hash[r] - (hash[l] * p_pow[r - l]) % mod + mod) % mod );
}

int main(){
    string str;
    cin >> str;
    int n = str.size();

    vector<ll> hash = compute_hash(str);

    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int x, y;
        cin >> x >> y;
        ll subtstring_hash = compute_substring_hash(x-1, y, hash, p_pow);
        int diff = y - x + 1;
        int count = 0;
        for(int j=0; j + diff <= n; j++){
            if(compute_substring_hash(j, j+diff, hash, p_pow) == subtstring_hash){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}