#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<long long>> a(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]--;
    }
    
    vector<long long> ans(n);
    vector<bool> added(n, false);
    
    for (int k = 0; k < n; k++) {
        int v = x[k];
        added[v] = true;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][v] + a[v][j] < a[i][j]) {
                    a[i][j] = a[i][v] + a[v][j];
                }
            }
        }
        
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            if (!added[i]) continue;
            for (int j = 0; j < n; j++) {
                if (!added[j]) continue;
                if (a[i][j] > cur) {
                    cur = a[i][j];
                }
            }
        }
        ans[k] = cur;
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}