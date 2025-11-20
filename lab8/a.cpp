#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

const long long p = 11;
const long long mod = 1e9 + 7;

long long compute_hash(string s) {
    long long h = 0;
    long long power = 1;

    for (int i = 0; i < s.length(); i++) {
        h = (h + (s[i] - 47) * power) % mod;
        power = (power * p) % mod;
    }
    return h;
}


int main() {
    int n;
    cin >> n;
    vector<string> arr(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> arr[i];

    unordered_map<string, long long> mp;
    for (auto &str : arr)
        mp[str] = compute_hash(str);

    int count = 0;
    for (auto &str : arr) {
        string candidate = to_string(mp[str]);
        if (mp.find(candidate) != mp.end()) {
            cout << "Hash of string \"" << str << "\" is " << mp[str] << endl;
            count++;
            if(count == n){
                break;
            }
        } 
    }
}