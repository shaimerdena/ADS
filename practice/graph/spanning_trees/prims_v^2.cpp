#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    const int INF = 1e9;
    vector<int> key(n, INF), parent(n, -1), used(n, 0);

    key[0] = 0; // start from vertex 0
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || key[j] < key[v])) v = j;
        }
        used[v] = 1;
        for (auto [to, w] : g[v]) {
            if (!used[to] && w < key[to]) {
                key[to] = w;
                parent[to] = v;
            }
        }
    }

    int total = 0;
    for (int w : key) total += w;

    cout << "MST cost: " << total << "\nEdges:\n";
    for (int v = 1; v < n; v++) {
        cout << parent[v] + 1 << " - " << v + 1 << " (" << key[v] << ")\n";
    }
    return 0;
}