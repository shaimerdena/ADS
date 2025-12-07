#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<char> used(n + 1, 0);      
    vector<int> parent(n + 1, -1);    
    vector<int> children(n + 1, 0);    
    long long result = 0;

    for (int s = 1; s <= n; ++s) {
        if (used[s]) continue;

        queue<int> q;
        q.push(s);
        used[s] = 1;
        vector<int> comp;
        comp.push_back(s);
        int root = s;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u < root) root = u;
            for (int v : adj[u]) if (!used[v]) {
                used[v] = 1;
                q.push(v);
                comp.push_back(v);
            }
        }

        queue<int> q2;
        parent[root] = 0;
        q2.push(root);
        while (!q2.empty()) {
            int u = q2.front(); q2.pop();
            for (int v : adj[u]) {
                if (parent[v] == -1) { 
                    parent[v] = u;
                    children[u] += 1;
                    q2.push(v);
                }
            }
        }

        result += 1; 
        for (int v : comp) {
            if (v == root) continue;
            int p = parent[v];
            if (children[v] > children[p]) ++result;
        }
    }

    cout << result << '\n';
    return 0;
}