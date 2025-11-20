#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Функция для вычисления префикс-функции (π)
vector<int> computePrefixFunction(const string &pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    int k = 0;

    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[k] != pattern[i])
            k = pi[k - 1];
        if (pattern[k] == pattern[i])
            k++;
        pi[i] = k;
    }
    return pi;
}

// KMP алгоритм поиска подстроки
void KMP(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> pi = computePrefixFunction(pattern);
    int q = 0; // число совпавших символов

    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i])
            q = pi[q - 1];
        if (pattern[q] == text[i])
            q++;
        if (q == m) {
            cout << "Pattern found at index: " << i - m + 1 << endl;
            q = pi[q - 1]; // готовимся к следующему совпадению
        }
    }
}

int main() {
    string text = "ababcababcabc";
    string pattern = "abc";

    KMP(text, pattern);

    return 0;
}