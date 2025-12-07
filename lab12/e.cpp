#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e15;

int main() {
    int n;
    cin >> n;
    vector<vector<long long>> w(n, vector<long long>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> w[i][j];

    vector<long long> dist(n, 0);
    vector<int> parent(n, -1);
    int cycle_start = -1;

    for(int iter = 0; iter < n; iter++) {
        cycle_start = -1;
        for(int u = 0; u < n; u++) {
            for(int v = 0; v < n; v++) {
                if(w[u][v] < INF && dist[v] > dist[u] + w[u][v]) {
                    dist[v] = dist[u] + w[u][v];
                    parent[v] = u;
                    if(iter == n-1)
                        cycle_start = v;
                }
            }
        }
    }

    if(cycle_start == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        int v = cycle_start;
        for(int i = 0; i < n; i++)
            v = parent[v];

        vector<int> cycle;
        for(int cur = v;; cur = parent[cur]) {
            cycle.push_back(cur + 1);
            if(cur == v && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for(int x : cycle) cout << x << " ";
        cout << "\n";
    }

    return 0;
}