#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long;
const ll INF = 1e18;

vector<ll> dijkstra(int start, int N, const vector<vector<pair<int, int>>>& graph) {
    vector<ll> dist(N + 1, INF);
    dist[start] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> graph(N + 1);
    
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    
    int s, a, b, f;
    cin >> s >> a >> b >> f;
    
    vector<ll> distS = dijkstra(s, N, graph);
    vector<ll> distA = dijkstra(a, N, graph);
    vector<ll> distB = dijkstra(b, N, graph);
    vector<ll> distF = dijkstra(f, N, graph);
    
    // Order 1: s -> a -> b -> f
    ll ans = INF;
    if (distS[a] < INF && distA[b] < INF && distB[f] < INF) {
        ans = min(ans, distS[a] + distA[b] + distB[f]);
    }
    
    // Order 2: s -> b -> a -> f
    if (distS[b] < INF && distB[a] < INF && distA[f] < INF) {
        ans = min(ans, distS[b] + distB[a] + distA[f]);
    }
    
    if (ans == INF) ans = -1;
    cout << ans << "\n";
    
    return 0;
}