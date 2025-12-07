#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i) if (indeg[i] == 0) q.push(i);

    vector<int> order;
    order.reserve(n);
    while (!q.empty()) {
        int u = q.top(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    if ((int)order.size() != n) {
        cout << "Impossible\n";
    } else {
        cout << "Possible\n";
        for (int x : order) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}