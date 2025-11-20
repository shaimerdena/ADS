#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computePrefixSums(const string &pattern) {
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

int minRepeatsToContain(string A, string B) {
    int n = A.size();
    int m = B.size();
    vector<int> pi = computePrefixSums(B);

    int q = 0; // current matched prefix in B
    int i = 0; // position in repeated A
    int limit = n + m; // max needed length
    int repetitions = 1;

    while (i < limit) {
        char current = A[i % n];
        while (q > 0 && B[q] != current)
            q = pi[q - 1];
        if (B[q] == current)
            q++;
        if (q == m)
            return (i + 1 + n - 1) / n; // ceil division — how many repeats used
        i++;
    }
    return -1;
}

int main() {
    string A, B;
    cin >> A >> B;
    cout << minRepeatsToContain(A, B) << endl;
    return 0;
}
