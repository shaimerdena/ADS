#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> used(n, 0);
    vector<int> minEdge(n, INT_MAX);
    minEdge[0] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, 0});  // (вес, вершина)

    long long mst = 0;

    while(!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if(used[u]) continue;

        used[u] = 1;
        mst += cost;

        for(auto [v, w] : adj[u]) {
            if(!used[v] && w < minEdge[v]) {
                minEdge[v] = w;
                pq.push({w, v});
            }
        }
    }

    cout << "MST cost = " << mst << endl;
}
