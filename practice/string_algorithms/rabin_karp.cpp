#include <iostream>
#include <vector>
using namespace std;

const long long P = 31;         // Основание (часто берут 31 или 53)
const long long MOD = 1e9 + 9;  // Простое число для модуля

vector<long long> compute_hash(const string &s) {
    int n = s.size();
    vector<long long> hash(n + 1, 0);
    vector<long long> p_pow(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        p_pow[i] = (p_pow[i - 1] * P) % MOD;
        hash[i] = (hash[i - 1] * P + (s[i - 1] - 'a' + 1)) % MOD;
    }
    return hash;
}

long long substring_hash(int l, int r, const vector<long long> &hash, const vector<long long> &p_pow) {
    return (hash[r] - (hash[l] * p_pow[r - l]) % MOD + MOD) % MOD;
}

int main() {
    string text = "abacaba";
    string pattern = "aba";

    int n = text.size();
    int m = pattern.size();

    // Префиксные хэши и степени P
    vector<long long> text_hash(n + 1, 0), p_pow(n + 1, 1);
    
    for (int i = 1; i <= n; i++) {
        p_pow[i] = (p_pow[i - 1] * P) % MOD;
        text_hash[i] = (text_hash[i - 1] * P + (text[i - 1] - 'a' + 1)) % MOD;
    }

    // Хэш шаблона
    long long pattern_hash = 0;
    for (char c : pattern) {
        pattern_hash = (pattern_hash * P + (c - 'a' + 1)) % MOD;
    }

    // Поиск
    for (int i = 0; i + m <= n; i++) {
        long long curr_hash = (text_hash[i + m] - (text_hash[i] * p_pow[m]) % MOD + MOD) % MOD;
        if (curr_hash == pattern_hash) {
            cout << "Found at index: " << i << endl;
        }
    }
}
