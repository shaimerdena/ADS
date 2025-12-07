//дороги и мин стоимость 
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); 
    }
    int find(int v) { 
        return parent[v] == v ? v : parent[v] = find(parent[v]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        parent[b] = a;
        return true;
    }
};

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v]){
        if (!visited[to])
            dfs(graph, to, visited);}
}

int main() {
    int n, m;
    cin>>n>>m;
    long long A, B;
    cin>>A>>B;

    vector<tuple<long long,int,int>> edges;

    for (int i = 0; i < m; i++) {
        string type;
        int u, v, len;
        cin>>type>>u>>v>>len;

        long long cost;
        if (type == "big") cost = A * len; 
        else if (type == "small") cost = B * len;
        else cost = min(A * len, B * len);

        edges.push_back({cost, u, v});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long sum = 0;
    vector<vector<int>> mst(n + 1);

    for (auto &e : edges) {
        long long cost;
        int u, v;
        tie(cost, u, v) = e;

        if (dsu.unite(u, v)) { 
            sum += cost;
            mst[u].push_back(v);
            mst[v].push_back(u);
        }
    }
    vector<int> visited(n + 1, 0);
    dfs(mst, 1, visited);

    cout <<sum;
    return 0;
}